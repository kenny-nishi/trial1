// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from testing_interfaces:srv/ServoControl.idl
// generated code does not contain a copyright notice

#ifndef TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__STRUCT_H_
#define TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ServoControl in the package testing_interfaces.
typedef struct testing_interfaces__srv__ServoControl_Request
{
  int32_t angle;
} testing_interfaces__srv__ServoControl_Request;

// Struct for a sequence of testing_interfaces__srv__ServoControl_Request.
typedef struct testing_interfaces__srv__ServoControl_Request__Sequence
{
  testing_interfaces__srv__ServoControl_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} testing_interfaces__srv__ServoControl_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/ServoControl in the package testing_interfaces.
typedef struct testing_interfaces__srv__ServoControl_Response
{
  rosidl_runtime_c__String response;
} testing_interfaces__srv__ServoControl_Response;

// Struct for a sequence of testing_interfaces__srv__ServoControl_Response.
typedef struct testing_interfaces__srv__ServoControl_Response__Sequence
{
  testing_interfaces__srv__ServoControl_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} testing_interfaces__srv__ServoControl_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TESTING_INTERFACES__SRV__DETAIL__SERVO_CONTROL__STRUCT_H_
