// this serve as template for set up the micro_ros client 
// to send the request, set up a timer for doing it
// also set up a publisher to publish the result

//include the library if needed

# include <Arduino.h>
# include <micro_ros_platformio.h>

// library of ROS2 client Support Library rcl
// library of ROS2 Client Library package rclc
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <example_interfaces/srv/add_two_ints.h> //import the interface from extra_package

#include <std_msgs/msg/int32.h>

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

rcl_client_t client; //declare client
example_interfaces__srv__AddTwoInts_Response res; //declare response

rcl_publisher_t publisher; //declare publisher
std_msgs__msg__Int32 message; //declare message

rcl_timer_t timer; //declare timer
int64_t seq_num;
// callback function for client
void client_callback(const void * msg){
    //cast the message
    example_interfaces__srv__AddTwoInts_Response * msg_in = (example_interfaces__srv__AddTwoInts_Response *)msg;
    message.data = msg_in->sum; //change the data of msg
    rcl_publish(&publisher, &message, NULL); //publish the message
}


// callback function for timer
void timer_callback(rcl_timer_t * timer, int64_t last_call_time){
    RCLC_UNUSED(last_call_time);
    if(timer != NULL){
      //cast the request
      example_interfaces__srv__AddTwoInts_Request req;
      req.a = rand()%100;
      req.b = rand()%100;
      rcl_send_request(&client, &req, &seq_num); //send the request
    }
}

void setup()
{
    Serial.begin(115200);
    set_microros_serial_transports(Serial);
    delay(2000);
 
    allocator = rcl_get_default_allocator();
    // create init_options
    rclc_support_init(&support, 0, NULL, &allocator);

    // create node
    rclc_node_init_default(&node, "node_name", "", &support);

    // create executor
    rclc_executor_init(&executor, &support.context, 2, &allocator);

    // create client
    rclc_client_init_default(&client, &node, ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts), "/micro_ros_client");
    rclc_executor_add_client(&executor, &client, &res, &client_callback); //add client to executor

    // create publisher
    rclc_publisher_init_default(&publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "/result");

    // create timer
    rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(1000), timer_callback); //timer with 1000ms = 1s
    rclc_executor_add_timer(&executor, &timer); //add timer to executor
}

void loop(){
    delay(1000);
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1000));
}