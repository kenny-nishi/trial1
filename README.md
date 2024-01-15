## using Micro_ros to set up the node in stm32
1. Please according to the following website to create the ros2 environment on your laptop/ machine
https://micro.ros.org/docs/tutorials/core/first_application_linux/

2. in each time, please enter the correct folder and correct virtual environment before using it
for example, if you follow the first step, you should enter the microros_ws directory first, then type 
"source install/local_setup.bash" 
to enter the virtual environment

3. Run the ros2 command
for instance, to connect it through the serail connection, type the following command

ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/ttyUSB0

if you looking for running on wifi, use the following command instead
ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888


## How to send one time message as publisher to specific topics?
example:
ros2 topic pub /led_cmd std_msgs/msg/Int32 "{data: 0}" --once
where, 
/led_cmd is the topic name
std_msgs/msg/Int32 is datatype
0 is the data

## service
ros2 service list
cmd for one time service request
ros2 service call /micro_ros_service example_interfaces/srv/AddTwoInts "{a: 114, b: 514}"

## client
ros2 client

we need to build the server side in our pc, we can use python code or c++ code to do it, for reference, I will do it in both languages for you guys 

See the folder called server_example for reference on cpp and python one
first make server_ws directory
then make src diirectory under it

type the following command to initialize it (for python)
ros2 pkg create microros_server --build-type ament_python --dependencies rcipy example_interfaces --node-name microros_server

(for c++)
ros2 pkg create microros_server_cpp --build-type ament_cmake --dependencies rcpputils example_interfaces --node-name microros_server_cpp
(later look reference at https://blog.csdn.net/qq_38649880/article/details/104427265)

after programming the server site (syntax please according to ros2)
go back to the sserver_ws layer, and type "colcon build" to build the packagess
and then source with the environment "source install/local_setup.bash"
final to run the server, type "ros2 run microros_server microros_server" for python one
for cpp, we type "ros2 run microros_server microros_server_cpp"

## runYolo.py
Run $ pip install ultralytics 
If there's AttributeError and some libraries are missing, such as cv2, cpuinfo, ultralytics, you're missing some libraries then just 
search the libaries and pip install them back.
Simple python3 runYolo.py, then it will display your webcam with detection boxes, terminal will show each detected box name and bounding box coordinates.
for more information in working with the result detection, follow documentations in https://docs.ultralytics.com/reference/engine/results/#ultralytics.engine.results.Results.verbose


--Kenny 2024-1-5s

For set up the interface, please read the README.md in testing_interfaces folder


### for one time running the signal to the servo
ros2 service call /change_angle testing_interfaces/srv/ServoControl "{angle: 180}"
please look for the ServoAdjust_wifi.cpp for more detailed
