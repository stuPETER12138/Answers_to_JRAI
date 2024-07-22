from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'sample_bot_description'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        (os.path.join('share', package_name, 'urdf'), glob('urdf/**')),
        (os.path.join('share', package_name, 'world'), glob('world/**')),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='wu',
    maintainer_email='2667497807@qq.com',
    description='TODO: Package description',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "rotate_wheel = sample_bot_description.rotate_wheel:main"
        ],
    },
)
