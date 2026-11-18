from glob import glob

from setuptools import find_packages, setup

package_name = 'my_arm_description'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
        ('share/' + package_name + '/urdf', glob('urdf/*.urdf')),
        ('share/' + package_name + '/rviz', glob('rviz/*.rviz')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hyperdrant',
    maintainer_email='sas573920@gmail.com',
    description='Two-link arm URDF + tf2 learning package',
    license='MIT',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'joint_state_pub = my_arm_description.joint_state_pub:main',
            'fk_check = my_arm_description.fk_check:main',
        ],
    },
)
