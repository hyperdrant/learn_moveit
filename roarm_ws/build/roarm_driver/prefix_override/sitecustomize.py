import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/hyperdrant/learning_ros2/roarm_ws/install/roarm_driver'
