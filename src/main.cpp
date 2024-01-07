//include the library if needed

# include <Arduino.h>
# include <micro_ros_platformio.h>

// library of ROS2 client Support Library rcl
// library of ROS2 Client Library package rclc
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <WiFi.h>
#include <testing_interfaces/srv/servo_control.h>
#include <rosidl_runtime_c/string_functions.h>
// #include <std_msgs/msg/string.h>
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

rcl_service_t service; //declare service
testing_interfaces__srv__ServoControl_Request req; //declare request
testing_interfaces__srv__ServoControl_Response res; //declare response


// set up for servo
#include <ESP32Servo.h>
#define ServoPin 15
Servo servo;
int32_t current_angle = 90;




// function to change the angle of servo
String change_angle(int32_t target_angle){
    //here you need to write the code to change the angle of servo
    //and return the string of the result
    // rosidl_runtime_c__String result;
    //arduino code
    #define ServoPin 15
    if (current_angle < target_angle){
        for (int i = current_angle; i <= target_angle; i++){
        servo.write(i);
        delay(20);
        }
    }
    else{
        for (int i = current_angle; i >= target_angle; i--){
        servo.write(i);
        delay(20);
        }
    }

    current_angle = target_angle;

    String my_string = "The angle is changed to " + String(target_angle) + " degree.";
    return my_string;
}



// callback function for service
void service_callback(const void * req, void * res){
    //cast the request and response
    testing_interfaces__srv__ServoControl_Request * req_in = (testing_interfaces__srv__ServoControl_Request *)req;
    testing_interfaces__srv__ServoControl_Response * res_in = (testing_interfaces__srv__ServoControl_Response *)res;
    String res_string = change_angle(req_in->angle);

    // change the type of response from string to rosidl_runtime_c__String for return the string
    rosidl_runtime_c__String__assignn(&res_in->response, res_string.c_str(), res_string.length());
    //here already change the data of res (as using pointer here)
}

void setup()
{
    Serial.begin(115200);
    // use wifi to communicate
    IPAddress agent_ip;
    agent_ip.fromString("192.168.43.146");//here you need to change the ip address to your computer ip address
    // set wifi name, password, ip address and port
    set_microros_wifi_transports("faiphone", "12345678", agent_ip, 8888);
    // delay 2s for wifi connection
    delay(2000);
 
    allocator = rcl_get_default_allocator();
    // create init_options
    rclc_support_init(&support, 0, NULL, &allocator);

    // create node
    rclc_node_init_default(&node, "servo_node", "", &support);

    // create executor
    rclc_executor_init(&executor, &support.context, 1, &allocator);

    rclc_service_init_default(&service, &node, ROSIDL_GET_SRV_TYPE_SUPPORT(testing_interfaces, srv, ServoControl), "/change_angle");

    res.response.data = (char*)malloc(sizeof(char)*128);
    //need allocate the memory for response (as it is string) (128 char)
    rclc_executor_add_service(&executor, &service, &req, &res, &service_callback); //add service to executor

    // set it be servo pin, but just according to the GPIO number
    servo.attach(ServoPin, 550, 2400);
    servo.write(90);
}

void loop(){
    delay(1000);
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1000));
}