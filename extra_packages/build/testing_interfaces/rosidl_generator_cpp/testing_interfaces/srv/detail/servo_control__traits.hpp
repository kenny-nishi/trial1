// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from testing_interfaces:srv/ServoControl.idl
// generated code does not contain a copyright notice

#ifndef TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__TRAITS_HPP_
#define TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__TRAITS_HPP_

#include "testing_interfaces/srv/detail/servo_control__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<testing_interfaces::srv::ServoControl_Request>()
{
  return "testing_interfaces::srv::ServoControl_Request";
}

template<>
inline const char * name<testing_interfaces::srv::ServoControl_Request>()
{
  return "testing_interfaces/srv/ServoControl_Request";
}

template<>
struct has_fixed_size<testing_interfaces::srv::ServoControl_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<testing_interfaces::srv::ServoControl_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<testing_interfaces::srv::ServoControl_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<testing_interfaces::srv::ServoControl_Response>()
{
  return "testing_interfaces::srv::ServoControl_Response";
}

template<>
inline const char * name<testing_interfaces::srv::ServoControl_Response>()
{
  return "testing_interfaces/srv/ServoControl_Response";
}

template<>
struct has_fixed_size<testing_interfaces::srv::ServoControl_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<testing_interfaces::srv::ServoControl_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<testing_interfaces::srv::ServoControl_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<testing_interfaces::srv::ServoControl>()
{
  return "testing_interfaces::srv::ServoControl";
}

template<>
inline const char * name<testing_interfaces::srv::ServoControl>()
{
  return "testing_interfaces/srv/ServoControl";
}

template<>
struct has_fixed_size<testing_interfaces::srv::ServoControl>
  : std::integral_constant<
    bool,
    has_fixed_size<testing_interfaces::srv::ServoControl_Request>::value &&
    has_fixed_size<testing_interfaces::srv::ServoControl_Response>::value
  >
{
};

template<>
struct has_bounded_size<testing_interfaces::srv::ServoControl>
  : std::integral_constant<
    bool,
    has_bounded_size<testing_interfaces::srv::ServoControl_Request>::value &&
    has_bounded_size<testing_interfaces::srv::ServoControl_Response>::value
  >
{
};

template<>
struct is_service<testing_interfaces::srv::ServoControl>
  : std::true_type
{
};

template<>
struct is_service_request<testing_interfaces::srv::ServoControl_Request>
  : std::true_type
{
};

template<>
struct is_service_response<testing_interfaces::srv::ServoControl_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__TRAITS_HPP_
