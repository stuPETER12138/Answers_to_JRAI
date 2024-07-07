// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Now.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__NOW__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__NOW__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Now __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Now __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Now_
{
  using Type = Now_<ContainerAllocator>;

  explicit Now_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->now = "";
    }
  }

  explicit Now_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : now(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->now = "";
    }
  }

  // field types and members
  using _now_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _now_type now;

  // setters for named parameter idiom
  Type & set__now(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->now = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Now_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Now_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Now_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Now_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Now_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Now_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Now_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Now_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Now_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Now_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Now
    std::shared_ptr<interfaces::msg::Now_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Now
    std::shared_ptr<interfaces::msg::Now_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Now_ & other) const
  {
    if (this->now != other.now) {
      return false;
    }
    return true;
  }
  bool operator!=(const Now_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Now_

// alias to use template instance with default allocator
using Now =
  interfaces::msg::Now_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__NOW__STRUCT_HPP_
