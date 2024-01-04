// Description: ros2 server example in C++.
// going to finish this laters

// #include "rclcpp/rclcpp.hpp"
// #include "example_interfaces/srv/add_two_ints.hpp"

// class MicroROSServer : public rclcpp::Node
// {
// public:
//   MicroROSServer() : Node("micro_ros_server")
//   {
//     // /micro_ros_client is the name declared in the client
//     // rclc_client_init_default(&client, &node, ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts), "/micro_ros_client");
//     add_two_ints_server_ = create_service<example_interfaces::srv::AddTwoInts>(
//       "/micro_ros_client",
//       std::bind(&MicroROSServer::add_two_ints_callback, this, std::placeholders::_1, std::placeholders::_2));
//   }

// private:
//   void add_two_ints_callback(
//     const std::shared_ptr<rmw_request_id_t> request_header,
//     const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
//     const std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
//   {
//     RCLCPP_INFO(this->get_logger(), "Calculating %d + %d", request->a, request->b);
//     response->sum = request->a + request->b;
//   }

//   rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr add_two_ints_server_;
// };

// int main(int argc, char** argv)
// {
//   std::cout << "Hi from microros_server." << std::endl;
//   rclcpp::init(argc, argv);
//   auto node = std::make_shared<MicroROSServer>();
//   rclcpp::spin(node);
//   rclcpp::shutdown();
//   return 0;
// }