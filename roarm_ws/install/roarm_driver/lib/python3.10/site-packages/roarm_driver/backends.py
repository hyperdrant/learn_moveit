"""
硬件后端：驱动节点只通过这几个方法和"机械臂"打交道

    read()          -> 当前 4 个关节角 [base, shoulder, elbow, hand]（rad），读不到时返回 None
    command(q)      -> 让 4 个关节去往 q（rad），立即返回，不等到位
    home()          -> 回到初始位姿
    close()

SimBackend 和 SerialBackend 实现同样的方法，所以驱动节点不用关心另一端是模拟器还是真机。
"""
import json
import math
import threading
import time

JOINT_NAMES = ['base_joint', 'shoulder_joint', 'elbow_joint', 'hand_joint']

# 关节限位（rad），来自固件 RoArm-M2_module.h
JOINT_LIMITS = [
    (-math.pi, math.pi),            # base
    (-math.pi / 2, math.pi / 2),    # shoulder
    (-math.pi / 4, math.pi),        # elbow
    # hand：固件允许 1.07~5.21（舵机位置 700~3396），
    # 夹爪版本 3.14 已经夹紧，再大只是更用力挤，这里保守地限制到 3.14
    (1.08, math.pi),
]

# 固件 {"T":100} 的初始位姿：所有舵机回中位
HOME = [0.0, 0.0, math.pi / 2, math.pi]

GRIPPER_OPEN = 1.57    # 固件注释里的 release
GRIPPER_CLOSE = 3.14   # 固件注释里的 grab


class SimBackend:
    """内存里的假机械臂：每个关节以不超过 max_velocity 的速度追向目标角度"""

    def __init__(self, max_velocity=1.5):
        self.max_velocity = max_velocity
        self._pos = list(HOME)
        self._target = list(HOME)
        self._last = time.monotonic()
        self._lock = threading.Lock()

    def _update(self):
        # 用"距离上次更新过了多久"推算位置，不需要额外的线程
        now = time.monotonic()
        step = self.max_velocity * (now - self._last)
        self._last = now
        for i, (p, t) in enumerate(zip(self._pos, self._target)):
            self._pos[i] = p + max(-step, min(step, t - p))

    def read(self):
        with self._lock:
            self._update()
            return list(self._pos)

    def command(self, q):
        with self._lock:
            self._update()
            self._target = list(q)

    def home(self):
        self.command(HOME)

    def close(self):
        pass


class SerialBackend:
    """通过 USB 串口和 RoArm-M2 固件通信（JSON 命令，见固件 json_cmd.h）"""

    def __init__(self, port, baudrate=115200, logger=None):
        import serial  # 只在真机模式才需要 pyserial

        self._log = logger
        self._ser = serial.Serial(port, baudrate=baudrate, timeout=0.1)
        # 和官方示例 serial_simple_ctrl.py 一样，避免拉低 ESP32 的复位脚
        self._ser.setRTS(False)
        self._ser.setDTR(False)
        self._write_lock = threading.Lock()
        self._pos = None
        self._last_request = 0.0
        self._running = True
        self._reader = threading.Thread(target=self._read_loop, daemon=True)
        self._reader.start()

    def _send(self, cmd):
        with self._write_lock:
            self._ser.write(json.dumps(cmd).encode() + b'\n')

    def _read_loop(self):
        while self._running:
            try:
                line = self._ser.readline().decode('utf-8', errors='ignore').strip()
            except Exception as e:  # 串口被拔掉等
                if self._log:
                    self._log.error(f'串口读取失败: {e}')
                time.sleep(0.5)
                continue
            if not line.startswith('{'):
                continue
            try:
                data = json.loads(line)
            except json.JSONDecodeError:
                continue
            # {"T":105} 的回复：{"T":1051,"x":..,"b":..,"s":..,"e":..,"t":..}
            if data.get('T') == 1051:
                self._pos = [data['b'], data['s'], data['e'], data['t']]

    def read(self):
        # 每次 read 顺便请求一次新反馈，回复由读线程异步收到
        now = time.monotonic()
        if now - self._last_request > 0.02:
            self._send({'T': 105})
            self._last_request = now
        return None if self._pos is None else list(self._pos)

    def command(self, q):
        self._send({'T': 102, 'base': q[0], 'shoulder': q[1],
                    'elbow': q[2], 'hand': q[3], 'spd': 0, 'acc': 10})

    def home(self):
        self._send({'T': 100})

    def close(self):
        self._running = False
        self._ser.close()
