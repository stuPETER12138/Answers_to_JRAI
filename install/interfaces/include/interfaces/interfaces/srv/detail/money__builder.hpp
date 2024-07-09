// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/Money.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__MONEY__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__MONEY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/money__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Money_Request_num
{
public:
  Init_Money_Request_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Money_Request num(::interfaces::srv::Money_Request::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Money_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Money_Request>()
{
  return interfaces::srv::builder::Init_Money_Request_num();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Money_Response_answer
{
public:
  Init_Money_Response_answer()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Money_Response answer(::interfaces::srv::Money_Response::_answer_type arg)
  {
    msg_.answer = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Money_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Money_Response>()
{
  return interfaces::srv::builder::Init_Money_Response_answer();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__MONEY__BUILDER_HPP_
