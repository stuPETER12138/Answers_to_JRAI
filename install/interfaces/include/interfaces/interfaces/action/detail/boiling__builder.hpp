// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:action/Boiling.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__ACTION__DETAIL__BOILING__BUILDER_HPP_
#define INTERFACES__ACTION__DETAIL__BOILING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/action/detail/boiling__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Boiling_Goal_start_temperature
{
public:
  Init_Boiling_Goal_start_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Boiling_Goal start_temperature(::interfaces::action::Boiling_Goal::_start_temperature_type arg)
  {
    msg_.start_temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Boiling_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Boiling_Goal>()
{
  return interfaces::action::builder::Init_Boiling_Goal_start_temperature();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Boiling_Result_final_temperature
{
public:
  Init_Boiling_Result_final_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Boiling_Result final_temperature(::interfaces::action::Boiling_Result::_final_temperature_type arg)
  {
    msg_.final_temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Boiling_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Boiling_Result>()
{
  return interfaces::action::builder::Init_Boiling_Result_final_temperature();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Boiling_Feedback_per_second_temperature
{
public:
  Init_Boiling_Feedback_per_second_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Boiling_Feedback per_second_temperature(::interfaces::action::Boiling_Feedback::_per_second_temperature_type arg)
  {
    msg_.per_second_temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Boiling_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Boiling_Feedback>()
{
  return interfaces::action::builder::Init_Boiling_Feedback_per_second_temperature();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Boiling_SendGoal_Request_goal
{
public:
  explicit Init_Boiling_SendGoal_Request_goal(::interfaces::action::Boiling_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Boiling_SendGoal_Request goal(::interfaces::action::Boiling_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Boiling_SendGoal_Request msg_;
};

class Init_Boiling_SendGoal_Request_goal_id
{
public:
  Init_Boiling_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Boiling_SendGoal_Request_goal goal_id(::interfaces::action::Boiling_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Boiling_SendGoal_Request_goal(msg_);
  }

private:
  ::interfaces::action::Boiling_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Boiling_SendGoal_Request>()
{
  return interfaces::action::builder::Init_Boiling_SendGoal_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Boiling_SendGoal_Response_stamp
{
public:
  explicit Init_Boiling_SendGoal_Response_stamp(::interfaces::action::Boiling_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Boiling_SendGoal_Response stamp(::interfaces::action::Boiling_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Boiling_SendGoal_Response msg_;
};

class Init_Boiling_SendGoal_Response_accepted
{
public:
  Init_Boiling_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Boiling_SendGoal_Response_stamp accepted(::interfaces::action::Boiling_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Boiling_SendGoal_Response_stamp(msg_);
  }

private:
  ::interfaces::action::Boiling_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Boiling_SendGoal_Response>()
{
  return interfaces::action::builder::Init_Boiling_SendGoal_Response_accepted();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Boiling_GetResult_Request_goal_id
{
public:
  Init_Boiling_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Boiling_GetResult_Request goal_id(::interfaces::action::Boiling_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Boiling_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Boiling_GetResult_Request>()
{
  return interfaces::action::builder::Init_Boiling_GetResult_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Boiling_GetResult_Response_result
{
public:
  explicit Init_Boiling_GetResult_Response_result(::interfaces::action::Boiling_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Boiling_GetResult_Response result(::interfaces::action::Boiling_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Boiling_GetResult_Response msg_;
};

class Init_Boiling_GetResult_Response_status
{
public:
  Init_Boiling_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Boiling_GetResult_Response_result status(::interfaces::action::Boiling_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Boiling_GetResult_Response_result(msg_);
  }

private:
  ::interfaces::action::Boiling_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Boiling_GetResult_Response>()
{
  return interfaces::action::builder::Init_Boiling_GetResult_Response_status();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Boiling_FeedbackMessage_feedback
{
public:
  explicit Init_Boiling_FeedbackMessage_feedback(::interfaces::action::Boiling_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Boiling_FeedbackMessage feedback(::interfaces::action::Boiling_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Boiling_FeedbackMessage msg_;
};

class Init_Boiling_FeedbackMessage_goal_id
{
public:
  Init_Boiling_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Boiling_FeedbackMessage_feedback goal_id(::interfaces::action::Boiling_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Boiling_FeedbackMessage_feedback(msg_);
  }

private:
  ::interfaces::action::Boiling_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Boiling_FeedbackMessage>()
{
  return interfaces::action::builder::Init_Boiling_FeedbackMessage_goal_id();
}

}  // namespace interfaces

#endif  // INTERFACES__ACTION__DETAIL__BOILING__BUILDER_HPP_
