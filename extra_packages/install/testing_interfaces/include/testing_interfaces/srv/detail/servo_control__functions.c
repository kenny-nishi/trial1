// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from testing_interfaces:srv/ServoControl.idl
// generated code does not contain a copyright notice
#include "testing_interfaces/srv/detail/servo_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
testing_interfaces__srv__ServoControl_Request__init(testing_interfaces__srv__ServoControl_Request * msg)
{
  if (!msg) {
    return false;
  }
  // angle
  return true;
}

void
testing_interfaces__srv__ServoControl_Request__fini(testing_interfaces__srv__ServoControl_Request * msg)
{
  if (!msg) {
    return;
  }
  // angle
}

bool
testing_interfaces__srv__ServoControl_Request__are_equal(const testing_interfaces__srv__ServoControl_Request * lhs, const testing_interfaces__srv__ServoControl_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  return true;
}

bool
testing_interfaces__srv__ServoControl_Request__copy(
  const testing_interfaces__srv__ServoControl_Request * input,
  testing_interfaces__srv__ServoControl_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // angle
  output->angle = input->angle;
  return true;
}

testing_interfaces__srv__ServoControl_Request *
testing_interfaces__srv__ServoControl_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  testing_interfaces__srv__ServoControl_Request * msg = (testing_interfaces__srv__ServoControl_Request *)allocator.allocate(sizeof(testing_interfaces__srv__ServoControl_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(testing_interfaces__srv__ServoControl_Request));
  bool success = testing_interfaces__srv__ServoControl_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
testing_interfaces__srv__ServoControl_Request__destroy(testing_interfaces__srv__ServoControl_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    testing_interfaces__srv__ServoControl_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
testing_interfaces__srv__ServoControl_Request__Sequence__init(testing_interfaces__srv__ServoControl_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  testing_interfaces__srv__ServoControl_Request * data = NULL;

  if (size) {
    data = (testing_interfaces__srv__ServoControl_Request *)allocator.zero_allocate(size, sizeof(testing_interfaces__srv__ServoControl_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = testing_interfaces__srv__ServoControl_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        testing_interfaces__srv__ServoControl_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
testing_interfaces__srv__ServoControl_Request__Sequence__fini(testing_interfaces__srv__ServoControl_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      testing_interfaces__srv__ServoControl_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

testing_interfaces__srv__ServoControl_Request__Sequence *
testing_interfaces__srv__ServoControl_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  testing_interfaces__srv__ServoControl_Request__Sequence * array = (testing_interfaces__srv__ServoControl_Request__Sequence *)allocator.allocate(sizeof(testing_interfaces__srv__ServoControl_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = testing_interfaces__srv__ServoControl_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
testing_interfaces__srv__ServoControl_Request__Sequence__destroy(testing_interfaces__srv__ServoControl_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    testing_interfaces__srv__ServoControl_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
testing_interfaces__srv__ServoControl_Request__Sequence__are_equal(const testing_interfaces__srv__ServoControl_Request__Sequence * lhs, const testing_interfaces__srv__ServoControl_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!testing_interfaces__srv__ServoControl_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
testing_interfaces__srv__ServoControl_Request__Sequence__copy(
  const testing_interfaces__srv__ServoControl_Request__Sequence * input,
  testing_interfaces__srv__ServoControl_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(testing_interfaces__srv__ServoControl_Request);
    testing_interfaces__srv__ServoControl_Request * data =
      (testing_interfaces__srv__ServoControl_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!testing_interfaces__srv__ServoControl_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          testing_interfaces__srv__ServoControl_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!testing_interfaces__srv__ServoControl_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
#include "rosidl_runtime_c/string_functions.h"

bool
testing_interfaces__srv__ServoControl_Response__init(testing_interfaces__srv__ServoControl_Response * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    testing_interfaces__srv__ServoControl_Response__fini(msg);
    return false;
  }
  return true;
}

void
testing_interfaces__srv__ServoControl_Response__fini(testing_interfaces__srv__ServoControl_Response * msg)
{
  if (!msg) {
    return;
  }
  // response
  rosidl_runtime_c__String__fini(&msg->response);
}

bool
testing_interfaces__srv__ServoControl_Response__are_equal(const testing_interfaces__srv__ServoControl_Response * lhs, const testing_interfaces__srv__ServoControl_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
testing_interfaces__srv__ServoControl_Response__copy(
  const testing_interfaces__srv__ServoControl_Response * input,
  testing_interfaces__srv__ServoControl_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

testing_interfaces__srv__ServoControl_Response *
testing_interfaces__srv__ServoControl_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  testing_interfaces__srv__ServoControl_Response * msg = (testing_interfaces__srv__ServoControl_Response *)allocator.allocate(sizeof(testing_interfaces__srv__ServoControl_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(testing_interfaces__srv__ServoControl_Response));
  bool success = testing_interfaces__srv__ServoControl_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
testing_interfaces__srv__ServoControl_Response__destroy(testing_interfaces__srv__ServoControl_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    testing_interfaces__srv__ServoControl_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
testing_interfaces__srv__ServoControl_Response__Sequence__init(testing_interfaces__srv__ServoControl_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  testing_interfaces__srv__ServoControl_Response * data = NULL;

  if (size) {
    data = (testing_interfaces__srv__ServoControl_Response *)allocator.zero_allocate(size, sizeof(testing_interfaces__srv__ServoControl_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = testing_interfaces__srv__ServoControl_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        testing_interfaces__srv__ServoControl_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
testing_interfaces__srv__ServoControl_Response__Sequence__fini(testing_interfaces__srv__ServoControl_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      testing_interfaces__srv__ServoControl_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

testing_interfaces__srv__ServoControl_Response__Sequence *
testing_interfaces__srv__ServoControl_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  testing_interfaces__srv__ServoControl_Response__Sequence * array = (testing_interfaces__srv__ServoControl_Response__Sequence *)allocator.allocate(sizeof(testing_interfaces__srv__ServoControl_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = testing_interfaces__srv__ServoControl_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
testing_interfaces__srv__ServoControl_Response__Sequence__destroy(testing_interfaces__srv__ServoControl_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    testing_interfaces__srv__ServoControl_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
testing_interfaces__srv__ServoControl_Response__Sequence__are_equal(const testing_interfaces__srv__ServoControl_Response__Sequence * lhs, const testing_interfaces__srv__ServoControl_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!testing_interfaces__srv__ServoControl_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
testing_interfaces__srv__ServoControl_Response__Sequence__copy(
  const testing_interfaces__srv__ServoControl_Response__Sequence * input,
  testing_interfaces__srv__ServoControl_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(testing_interfaces__srv__ServoControl_Response);
    testing_interfaces__srv__ServoControl_Response * data =
      (testing_interfaces__srv__ServoControl_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!testing_interfaces__srv__ServoControl_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          testing_interfaces__srv__ServoControl_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!testing_interfaces__srv__ServoControl_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
