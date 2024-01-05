// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from testing_interfaces:srv/ServoControl.idl
// generated code does not contain a copyright notice

#ifndef TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__BUILDER_HPP_
#define TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__BUILDER_HPP_

#include "testing_interfaces/srv/detail/servo_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace testing_interfaces
{

namespace srv
{

namespace builder
{

class Init_ServoControl_Request_angle
{
public:
  Init_ServoControl_Request_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::testing_interfaces::srv::ServoControl_Request angle(::testing_interfaces::srv::ServoControl_Request::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::testing_interfaces::srv::ServoControl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::testing_interfaces::srv::ServoControl_Request>()
{
  return testing_interfaces::srv::builder::Init_ServoControl_Request_angle();
}

}  // namespace testing_interfaces


namespace testing_interfaces
{

namespace srv
{

namespace builder
{

class Init_ServoControl_Response_response
{
public:
  Init_ServoControl_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::testing_interfaces::srv::ServoControl_Response response(::testing_interfaces::srv::ServoControl_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::testing_interfaces::srv::ServoControl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::testing_interfaces::srv::ServoControl_Response>()
{
  return testing_interfaces::srv::builder::Init_ServoControl_Response_response();
}

}  // namespace testing_interfaces

#endif  // TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__BUILDER_HPP_
