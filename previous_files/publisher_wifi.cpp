// File: publisher.cpp
// it is using the wifi to do the publisher 
// remember to add the line of code in the platformio.ini

#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/string.h>

//executor is used to drive the event loop and timers of the node.
rclc_executor_t executor;
//support is used to store the allocator and context.
rclc_support_t support;
//allocator is used to allocate memory.
rcl_allocator_t allocator;
//node is used to store the node related information.
rcl_node_t node;
//publisher is used to publish messages.
rcl_publisher_t publisher;
//timer is used to publish messages periodically.
rcl_timer_t timer;
//msg is used to store the message data.
std_msgs__msg__String msg;


/* 
 * timer_callback - timer callback function
 * @timer: timer struct
 * @last_call_time: last call time
 */
void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
    static int times; // static times, used to count the number of times the callback function is executed
  
    RCLC_UNUSED(last_call_time); // unused parameter, avoid warning

    if (timer != NULL) // if timer is not NULL
    {
        rcl_publish(&publisher, &msg, NULL); // use publisher to publish the message

        // allocate memory for message data
        std_msgs__msg__String__init(&msg); // initialize the message
        msg.data.data = (char*)malloc(20); // allocate 20 bytes of memory for the message data
        msg.data.capacity = 20; // set the message data capacity to 20 bytes
        snprintf(msg.data.data, msg.data.capacity,("Running times:"+std::to_string(times)).c_str()); // generate message content
        msg.data.size = strlen(msg.data.data); // the actual length of the message data

        times+=1; // timer callback function execution times plus 1 for next time
    }
}



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
  // initialize allocator
  allocator = rcl_get_default_allocator();
  // initialize support
  rclc_support_init(&support, 0, NULL, &allocator);
  // create node on wifi with the name "microros_wifi"
  rclc_node_init_default(&node, "microros_wifi", "", &support);
  // create publisher
  rclc_publisher_init_default(
    &publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
    "Esp32_Time");
  //set timer period to 1000ms
  rclc_timer_init_default(
    &timer,
    &support,
    RCL_MS_TO_NS(1000),
    timer_callback);
  // create executor
  rclc_executor_init(&executor, &support.context, 1, &allocator);
  // add timer to executor (basically, any function that need to use recall will need to add to the executor)
  rclc_executor_add_timer(&executor, &timer);
}

void loop()
{
  delay(100);
  // spin the executor
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
}




