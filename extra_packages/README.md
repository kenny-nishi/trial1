# set up the interfaces

## For set up the interface, type the following command

make the folder of extra_packages

in that folder, type the following command

ros2 pkg create testing_interfaces --build-type ament_cmake 

where the testing_interfaces are the name of the interface

## then enter the interface, create the folder and set up the msg file or the file of service, here i use the service as example

cd testing_interfaces
mkdir srv
cd srv
touch ServoControl.srv # remainder here, the first character must be Capital

check the ServoControl.srv for more reference

Before compile, modified the CMakeLists.txt and package.xml to make sure it has the info of the new service type

look at the CMakeLists.txt and package.xml for more reference

## compile
cd extra_package/
colcon build --packages-select testing_interface
or just
colcon build

before using it, please delete the folder under pio doc (to remove the cache)
show in the following capscreen
![Alt text](<Screenshot from 2024-01-06 02-06-05.png>)