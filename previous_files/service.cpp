// this serve as template for set up the micro_ros service

//include the library if needed

# include <Arduino.h>
# include <micro_ros_platformio.h>

// library of ROS2 client Support Library rcl
// library of ROS2 Client Library package rclc
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <example_interfaces/srv/add_two_ints.h> //import the interface from extra_package

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

rcl_service_t service; //declare service
example_interfaces__srv__AddTwoInts_Request req; //declare request
example_interfaces__srv__AddTwoInts_Response res; //declare response

// callback function for service
void service_callback(const void * req, void * res){
    //cast the request and response
    example_interfaces__srv__AddTwoInts_Request * req_in = (example_interfaces__srv__AddTwoInts_Request *)req;
    example_interfaces__srv__AddTwoInts_Response * res_in = (example_interfaces__srv__AddTwoInts_Response *)res;
    
    res_in->sum = req_in->a + req_in->b; //do the operation
    //here already change the data of res (as using pointer here)
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
    rclc_executor_init(&executor, &support.context, 1, &allocator);

    // create service
    rclc_service_init_default(&service, &node, ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts), "/micro_ros_service");
    rclc_executor_add_service(&executor, &service, &req, &res, &service_callback); //add service to executor
}

void loop(){
    delay(1000);
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1000));
}