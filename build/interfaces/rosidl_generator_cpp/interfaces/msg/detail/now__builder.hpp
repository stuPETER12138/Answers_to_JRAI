// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Now.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__NOW__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__NOW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/now__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Now_now
{
public:
  Init_Now_now()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::Now now(::interfaces::msg::Now::_now_type arg)
  {
    msg_.now = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Now msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Now>()
{
  return interfaces::msg::builder::Init_Now_now();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__NOW__BUILDER_HPP_
