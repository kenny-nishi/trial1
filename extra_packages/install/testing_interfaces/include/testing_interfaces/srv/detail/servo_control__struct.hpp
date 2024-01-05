// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from testing_interfaces:srv/ServoControl.idl
// generated code does not contain a copyright notice

#ifndef TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__STRUCT_HPP_
#define TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__testing_interfaces__srv__ServoControl_Request __attribute__((deprecated))
#else
# define DEPRECATED__testing_interfaces__srv__ServoControl_Request __declspec(deprecated)
#endif

namespace testing_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ServoControl_Request_
{
  using Type = ServoControl_Request_<ContainerAllocator>;

  explicit ServoControl_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle = 0l;
    }
  }

  explicit ServoControl_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle = 0l;
    }
  }

  // field types and members
  using _angle_type =
    int32_t;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__angle(
    const int32_t & _arg)
  {
    this->angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    testing_interfaces::srv::ServoControl_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const testing_interfaces::srv::ServoControl_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<testing_interfaces::srv::ServoControl_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<testing_interfaces::srv::ServoControl_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      testing_interfaces::srv::ServoControl_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<testing_interfaces::srv::ServoControl_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      testing_interfaces::srv::ServoControl_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<testing_interfaces::srv::ServoControl_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<testing_interfaces::srv::ServoControl_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<testing_interfaces::srv::ServoControl_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__testing_interfaces__srv__ServoControl_Request
    std::shared_ptr<testing_interfaces::srv::ServoControl_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__testing_interfaces__srv__ServoControl_Request
    std::shared_ptr<testing_interfaces::srv::ServoControl_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoControl_Request_ & other) const
  {
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoControl_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoControl_Request_

// alias to use template instance with default allocator
using ServoControl_Request =
  testing_interfaces::srv::ServoControl_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace testing_interfaces


#ifndef _WIN32
# define DEPRECATED__testing_interfaces__srv__ServoControl_Response __attribute__((deprecated))
#else
# define DEPRECATED__testing_interfaces__srv__ServoControl_Response __declspec(deprecated)
#endif

namespace testing_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ServoControl_Response_
{
  using Type = ServoControl_Response_<ContainerAllocator>;

  explicit ServoControl_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  explicit ServoControl_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  // field types and members
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    testing_interfaces::srv::ServoControl_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const testing_interfaces::srv::ServoControl_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<testing_interfaces::srv::ServoControl_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<testing_interfaces::srv::ServoControl_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      testing_interfaces::srv::ServoControl_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<testing_interfaces::srv::ServoControl_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      testing_interfaces::srv::ServoControl_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<testing_interfaces::srv::ServoControl_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<testing_interfaces::srv::ServoControl_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<testing_interfaces::srv::ServoControl_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__testing_interfaces__srv__ServoControl_Response
    std::shared_ptr<testing_interfaces::srv::ServoControl_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__testing_interfaces__srv__ServoControl_Response
    std::shared_ptr<testing_interfaces::srv::ServoControl_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoControl_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoControl_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoControl_Response_

// alias to use template instance with default allocator
using ServoControl_Response =
  testing_interfaces::srv::ServoControl_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace testing_interfaces

namespace testing_interfaces
{

namespace srv
{

struct ServoControl
{
  using Request = testing_interfaces::srv::ServoControl_Request;
  using Response = testing_interfaces::srv::ServoControl_Response;
};

}  // namespace srv

}  // namespace testing_interfaces

#endif  // TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__STRUCT_HPP_
