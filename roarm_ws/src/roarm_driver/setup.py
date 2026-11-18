from glob import glob

from setuptools import find_packages, setup

package_name = 'roarm_driver'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hyperdrant',
    maintainer_email='sas573920@gmail.com',
    description='RoArm-M2 ROS 2 driver (topic/service/action/parameters)',
    license='MIT',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'driver = roarm_driver.driver:main',
            'move_client = roarm_driver.move_client:main',
        ],
    },
)
