// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from testing_interfaces:srv/ServoControl.idl
// generated code does not contain a copyright notice
#include "testing_interfaces/srv/detail/servo_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "testing_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "testing_interfaces/srv/detail/servo_control__struct.h"
#include "testing_interfaces/srv/detail/servo_control__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ServoControl_Request__ros_msg_type = testing_interfaces__srv__ServoControl_Request;

static bool _ServoControl_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ServoControl_Request__ros_msg_type * ros_message = static_cast<const _ServoControl_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: angle
  {
    cdr << ros_message->angle;
  }

  return true;
}

static bool _ServoControl_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ServoControl_Request__ros_msg_type * ros_message = static_cast<_ServoControl_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: angle
  {
    cdr >> ros_message->angle;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_testing_interfaces
size_t get_serialized_size_testing_interfaces__srv__ServoControl_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ServoControl_Request__ros_msg_type * ros_message = static_cast<const _ServoControl_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name angle
  {
    size_t item_size = sizeof(ros_message->angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ServoControl_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_testing_interfaces__srv__ServoControl_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_testing_interfaces
size_t max_serialized_size_testing_interfaces__srv__ServoControl_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ServoControl_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_testing_interfaces__srv__ServoControl_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ServoControl_Request = {
  "testing_interfaces::srv",
  "ServoControl_Request",
  _ServoControl_Request__cdr_serialize,
  _ServoControl_Request__cdr_deserialize,
  _ServoControl_Request__get_serialized_size,
  _ServoControl_Request__max_serialized_size
};

static rosidl_message_type_support_t _ServoControl_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ServoControl_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, testing_interfaces, srv, ServoControl_Request)() {
  return &_ServoControl_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "testing_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "testing_interfaces/srv/detail/servo_control__struct.h"
// already included above
// #include "testing_interfaces/srv/detail/servo_control__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // response
#include "rosidl_runtime_c/string_functions.h"  // response

// forward declare type support functions


using _ServoControl_Response__ros_msg_type = testing_interfaces__srv__ServoControl_Response;

static bool _ServoControl_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ServoControl_Response__ros_msg_type * ros_message = static_cast<const _ServoControl_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: response
  {
    const rosidl_runtime_c__String * str = &ros_message->response;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _ServoControl_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ServoControl_Response__ros_msg_type * ros_message = static_cast<_ServoControl_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: response
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->response.data) {
      rosidl_runtime_c__String__init(&ros_message->response);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->response,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'response'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_testing_interfaces
size_t get_serialized_size_testing_interfaces__srv__ServoControl_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ServoControl_Response__ros_msg_type * ros_message = static_cast<const _ServoControl_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name response
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->response.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _ServoControl_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_testing_interfaces__srv__ServoControl_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_testing_interfaces
size_t max_serialized_size_testing_interfaces__srv__ServoControl_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: response
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _ServoControl_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_testing_interfaces__srv__ServoControl_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ServoControl_Response = {
  "testing_interfaces::srv",
  "ServoControl_Response",
  _ServoControl_Response__cdr_serialize,
  _ServoControl_Response__cdr_deserialize,
  _ServoControl_Response__get_serialized_size,
  _ServoControl_Response__max_serialized_size
};

static rosidl_message_type_support_t _ServoControl_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ServoControl_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, testing_interfaces, srv, ServoControl_Response)() {
  return &_ServoControl_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "testing_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "testing_interfaces/srv/servo_control.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ServoControl__callbacks = {
  "testing_interfaces::srv",
  "ServoControl",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, testing_interfaces, srv, ServoControl_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, testing_interfaces, srv, ServoControl_Response)(),
};

static rosidl_service_type_support_t ServoControl__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ServoControl__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, testing_interfaces, srv, ServoControl)() {
  return &ServoControl__handle;
}

#if defined(__cplusplus)
}
#endif
