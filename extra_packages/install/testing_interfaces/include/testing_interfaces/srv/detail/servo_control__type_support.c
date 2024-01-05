// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from testing_interfaces:srv/ServoControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "testing_interfaces/srv/detail/servo_control__rosidl_typesupport_introspection_c.h"
#include "testing_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "testing_interfaces/srv/detail/servo_control__functions.h"
#include "testing_interfaces/srv/detail/servo_control__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  testing_interfaces__srv__ServoControl_Request__init(message_memory);
}

void ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_fini_function(void * message_memory)
{
  testing_interfaces__srv__ServoControl_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_message_member_array[1] = {
  {
    "angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(testing_interfaces__srv__ServoControl_Request, angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_message_members = {
  "testing_interfaces__srv",  // message namespace
  "ServoControl_Request",  // message name
  1,  // number of fields
  sizeof(testing_interfaces__srv__ServoControl_Request),
  ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_message_member_array,  // message members
  ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_message_type_support_handle = {
  0,
  &ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_testing_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, testing_interfaces, srv, ServoControl_Request)() {
  if (!ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_message_type_support_handle.typesupport_identifier) {
    ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ServoControl_Request__rosidl_typesupport_introspection_c__ServoControl_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "testing_interfaces/srv/detail/servo_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "testing_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "testing_interfaces/srv/detail/servo_control__functions.h"
// already included above
// #include "testing_interfaces/srv/detail/servo_control__struct.h"


// Include directives for member types
// Member `response`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  testing_interfaces__srv__ServoControl_Response__init(message_memory);
}

void ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_fini_function(void * message_memory)
{
  testing_interfaces__srv__ServoControl_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_message_member_array[1] = {
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(testing_interfaces__srv__ServoControl_Response, response),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_message_members = {
  "testing_interfaces__srv",  // message namespace
  "ServoControl_Response",  // message name
  1,  // number of fields
  sizeof(testing_interfaces__srv__ServoControl_Response),
  ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_message_member_array,  // message members
  ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_message_type_support_handle = {
  0,
  &ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_testing_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, testing_interfaces, srv, ServoControl_Response)() {
  if (!ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_message_type_support_handle.typesupport_identifier) {
    ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ServoControl_Response__rosidl_typesupport_introspection_c__ServoControl_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "testing_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "testing_interfaces/srv/detail/servo_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers testing_interfaces__srv__detail__servo_control__rosidl_typesupport_introspection_c__ServoControl_service_members = {
  "testing_interfaces__srv",  // service namespace
  "ServoControl",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // testing_interfaces__srv__detail__servo_control__rosidl_typesupport_introspection_c__ServoControl_Request_message_type_support_handle,
  NULL  // response message
  // testing_interfaces__srv__detail__servo_control__rosidl_typesupport_introspection_c__ServoControl_Response_message_type_support_handle
};

static rosidl_service_type_support_t testing_interfaces__srv__detail__servo_control__rosidl_typesupport_introspection_c__ServoControl_service_type_support_handle = {
  0,
  &testing_interfaces__srv__detail__servo_control__rosidl_typesupport_introspection_c__ServoControl_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, testing_interfaces, srv, ServoControl_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, testing_interfaces, srv, ServoControl_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_testing_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, testing_interfaces, srv, ServoControl)() {
  if (!testing_interfaces__srv__detail__servo_control__rosidl_typesupport_introspection_c__ServoControl_service_type_support_handle.typesupport_identifier) {
    testing_interfaces__srv__detail__servo_control__rosidl_typesupport_introspection_c__ServoControl_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)testing_interfaces__srv__detail__servo_control__rosidl_typesupport_introspection_c__ServoControl_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, testing_interfaces, srv, ServoControl_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, testing_interfaces, srv, ServoControl_Response)()->data;
  }

  return &testing_interfaces__srv__detail__servo_control__rosidl_typesupport_introspection_c__ServoControl_service_type_support_handle;
}
