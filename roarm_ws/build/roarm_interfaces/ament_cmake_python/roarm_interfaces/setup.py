from setuptools import find_packages
from setuptools import setup

setup(
    name='roarm_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('roarm_interfaces', 'roarm_interfaces.*')),
)
