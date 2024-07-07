// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Now.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__NOW__STRUCT_H_
#define INTERFACES__MSG__DETAIL__NOW__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'now'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Now in the package interfaces.
typedef struct interfaces__msg__Now
{
  rosidl_runtime_c__String now;
} interfaces__msg__Now;

// Struct for a sequence of interfaces__msg__Now.
typedef struct interfaces__msg__Now__Sequence
{
  interfaces__msg__Now * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Now__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__NOW__STRUCT_H_
