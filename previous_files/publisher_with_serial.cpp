// this serve as template for set up the micro_ros publisher

//include the library if needed

# include <Arduino.h>
# include <micro_ros_platformio.h>

// library of ROS2 client Support Library rcl
// library of ROS2 Client Library package rclc
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/int32.h>


rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;
rcl_publisher_t publisher;

//declare variables
std_msgs__msg__Int32 msg;


// to remove warning
#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

// Error handle loop
void error_loop() {
  while(1) {
    delay(100);
  }
}


//for the arduino code, set up as reference
#define LED_GPIO 2
void gpio_init() {
  pinMode(LED_GPIO, OUTPUT);
  digitalWrite(LED_GPIO, LOW);
}

void timer_callback(rcl_timer_t * timer, int64_t last_call_time) {
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    // you can do something when timer is up, like arduino code
    digitalWrite(LED_GPIO, !digitalRead(LED_GPIO));
    //can change the value of msg here
    msg.data = digitalRead(LED_GPIO);
    //publish the msg
    // rcl_publish(&publisher, &msg, NULL);
    //remove warning
    RCSOFTCHECK(rcl_publish(&publisher, &msg, NULL));
  }
}

void setup()
{
    gpio_init();
    // Configure serial transport
    Serial.begin(115200);
    set_microros_serial_transports(Serial);
    delay(2000);
 
    allocator = rcl_get_default_allocator();

    //create init_options
    // rclc_support_init(&support, 0, NULL, &allocator); // this is the original code
    // remove warning
    RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

    // create node
    // rclc_node_init_default(&node, "micro_ros_platformio_node", "", &support);
    // rclc_node_init_default(&node, "node name", "", &support);
    // remove warning
    RCCHECK(rclc_node_init_default(&node, "node_name", "", &support));

    // create executor
    // rclc_executor_init(&executor, &support.context, 1, &allocator);
    // rclc_executor_add_timer(&executor, &timer);
    // remove warning
    RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));


    // create timer,
    // rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(1000), timer_callback);
    // remove warning
    RCCHECK(rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(1000), timer_callback));
    //every 1000ms, the timer_callback will be called (every 1 second now), timer_callback is a function when the timer is up
    RCCHECK(rclc_executor_add_timer(&executor, &timer));


    // create publisher
    // rclc_publisher_init_default(&publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "topic_name");
    // remove warning
    // initialize the publisher the data type in here
    /*
        #include <std_msgs/msg/int32.h>
        std_msgs__msg__Int32 num;
        num.data = 1;
    */
    // RCSOFTCHECK(rclc_publisher_init_default(&publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(see the header), "topic_name"));
    RCCHECK(rclc_publisher_init_default(&publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "/led_status"));


}

void loop(){
    delay(1000);
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1000));
}





