// this serve as template for set up the micro_ros with wifi

//include the library if needed

# include <Arduino.h>
# include <micro_ros_platformio.h>

// library of ROS2 client Support Library rcl
// library of ROS2 Client Library package rclc
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <WiFi.h>
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;


void setup()
{
    Serial.begin(115200);
    // use wifi to communicate
    IPAddress agent_ip;
    agent_ip.fromString("192.168.1.112");//here you need to change the ip address to your computer ip address
    // set wifi name, password, ip address and port
    set_microros_wifi_transports("TP-LINK_2503", "lau19840215", agent_ip, 8888);
    // delay 2s for wifi connection
    delay(2000);
 
    allocator = rcl_get_default_allocator();
    // create init_options
    rclc_support_init(&support, 0, NULL, &allocator);

    // create node
    rclc_node_init_default(&node, "node_name", "", &support);

    // create executor
    rclc_executor_init(&executor, &support.context, 1, &allocator);
}

void loop(){
    delay(1000);
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1000));
}