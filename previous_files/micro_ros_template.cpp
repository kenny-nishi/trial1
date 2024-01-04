// this serve as template for set up the micro_ros

//include the library if needed

# include <Arduino.h>
# include <micro_ros_platformio.h>

// library of ROS2 client Support Library rcl
// library of ROS2 Client Library package rclc
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;

// to remove warning
#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

// Error handle loop
void error_loop() {
  while(1) {
    delay(100);
  }
}

void timer_callback(rcl_timer_t * timer, int64_t last_call_time) {
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    // you can do something when timer is up, like arduino code
    /*
    digitalWrite(LED_BUILTIN, HIGH);
    */
    RCSOFTCHECK(rcl_publish(&publisher, &msg, NULL));
    msg.data++;
  }
}


void setup()
{
    // Configure serial transport
    Serial.begin(115200);
    set_microros_serial_transports(Serial);
    delay(2000);
 
    allocator = rcl_get_default_allocator();

    //create init_options
    // rclc_support_init(&support, 0, NULL, &allocator); // this is the original code
    // remove warning
    RCSOFTCHECK(rclc_support_init(&support, 0, NULL, &allocator));

    // create node
    // rclc_node_init_default(&node, "micro_ros_platformio_node", "", &support);
    // rclc_node_init_default(&node, "node name", "", &support);
    // remove warning
    RCSOFTCHECK(rclc_node_init_default(&node, "node name", "", &support));

    // create executor
    // rclc_executor_init(&executor, &support.context, 1, &allocator);
    // rclc_executor_add_timer(&executor, &timer);
    // remove warning
    RCSOFTCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));

    // create timer,
    // rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(1000), timer_callback);
    // remove warning
    RCSOFTCHECK(rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(1000), timer_callback));
    //every 1000ms, the timer_callback will be called (every 1 second now), timer_callback is a function when the timer is up
    RCCHECK(rclc_executor_add_timer(&executor, &timer));
}

void loop(){
    delay(1000);
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
}




