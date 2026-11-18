// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roarm_interfaces:action/MoveJoints.idl
// generated code does not contain a copyright notice

#ifndef ROARM_INTERFACES__ACTION__DETAIL__MOVE_JOINTS__BUILDER_HPP_
#define ROARM_INTERFACES__ACTION__DETAIL__MOVE_JOINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roarm_interfaces/action/detail/move_joints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roarm_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveJoints_Goal_duration
{
public:
  explicit Init_MoveJoints_Goal_duration(::roarm_interfaces::action::MoveJoints_Goal & msg)
  : msg_(msg)
  {}
  ::roarm_interfaces::action::MoveJoints_Goal duration(::roarm_interfaces::action::MoveJoints_Goal::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_Goal msg_;
};

class Init_MoveJoints_Goal_positions
{
public:
  explicit Init_MoveJoints_Goal_positions(::roarm_interfaces::action::MoveJoints_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveJoints_Goal_duration positions(::roarm_interfaces::action::MoveJoints_Goal::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return Init_MoveJoints_Goal_duration(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_Goal msg_;
};

class Init_MoveJoints_Goal_joint_names
{
public:
  Init_MoveJoints_Goal_joint_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJoints_Goal_positions joint_names(::roarm_interfaces::action::MoveJoints_Goal::_joint_names_type arg)
  {
    msg_.joint_names = std::move(arg);
    return Init_MoveJoints_Goal_positions(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_interfaces::action::MoveJoints_Goal>()
{
  return roarm_interfaces::action::builder::Init_MoveJoints_Goal_joint_names();
}

}  // namespace roarm_interfaces


namespace roarm_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveJoints_Result_max_error
{
public:
  explicit Init_MoveJoints_Result_max_error(::roarm_interfaces::action::MoveJoints_Result & msg)
  : msg_(msg)
  {}
  ::roarm_interfaces::action::MoveJoints_Result max_error(::roarm_interfaces::action::MoveJoints_Result::_max_error_type arg)
  {
    msg_.max_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_Result msg_;
};

class Init_MoveJoints_Result_final_positions
{
public:
  explicit Init_MoveJoints_Result_final_positions(::roarm_interfaces::action::MoveJoints_Result & msg)
  : msg_(msg)
  {}
  Init_MoveJoints_Result_max_error final_positions(::roarm_interfaces::action::MoveJoints_Result::_final_positions_type arg)
  {
    msg_.final_positions = std::move(arg);
    return Init_MoveJoints_Result_max_error(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_Result msg_;
};

class Init_MoveJoints_Result_message
{
public:
  explicit Init_MoveJoints_Result_message(::roarm_interfaces::action::MoveJoints_Result & msg)
  : msg_(msg)
  {}
  Init_MoveJoints_Result_final_positions message(::roarm_interfaces::action::MoveJoints_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_MoveJoints_Result_final_positions(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_Result msg_;
};

class Init_MoveJoints_Result_success
{
public:
  Init_MoveJoints_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJoints_Result_message success(::roarm_interfaces::action::MoveJoints_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveJoints_Result_message(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_interfaces::action::MoveJoints_Result>()
{
  return roarm_interfaces::action::builder::Init_MoveJoints_Result_success();
}

}  // namespace roarm_interfaces


namespace roarm_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveJoints_Feedback_progress
{
public:
  explicit Init_MoveJoints_Feedback_progress(::roarm_interfaces::action::MoveJoints_Feedback & msg)
  : msg_(msg)
  {}
  ::roarm_interfaces::action::MoveJoints_Feedback progress(::roarm_interfaces::action::MoveJoints_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_Feedback msg_;
};

class Init_MoveJoints_Feedback_current_positions
{
public:
  Init_MoveJoints_Feedback_current_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJoints_Feedback_progress current_positions(::roarm_interfaces::action::MoveJoints_Feedback::_current_positions_type arg)
  {
    msg_.current_positions = std::move(arg);
    return Init_MoveJoints_Feedback_progress(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_interfaces::action::MoveJoints_Feedback>()
{
  return roarm_interfaces::action::builder::Init_MoveJoints_Feedback_current_positions();
}

}  // namespace roarm_interfaces


namespace roarm_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveJoints_SendGoal_Request_goal
{
public:
  explicit Init_MoveJoints_SendGoal_Request_goal(::roarm_interfaces::action::MoveJoints_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::roarm_interfaces::action::MoveJoints_SendGoal_Request goal(::roarm_interfaces::action::MoveJoints_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_SendGoal_Request msg_;
};

class Init_MoveJoints_SendGoal_Request_goal_id
{
public:
  Init_MoveJoints_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJoints_SendGoal_Request_goal goal_id(::roarm_interfaces::action::MoveJoints_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveJoints_SendGoal_Request_goal(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_interfaces::action::MoveJoints_SendGoal_Request>()
{
  return roarm_interfaces::action::builder::Init_MoveJoints_SendGoal_Request_goal_id();
}

}  // namespace roarm_interfaces


namespace roarm_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveJoints_SendGoal_Response_stamp
{
public:
  explicit Init_MoveJoints_SendGoal_Response_stamp(::roarm_interfaces::action::MoveJoints_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::roarm_interfaces::action::MoveJoints_SendGoal_Response stamp(::roarm_interfaces::action::MoveJoints_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_SendGoal_Response msg_;
};

class Init_MoveJoints_SendGoal_Response_accepted
{
public:
  Init_MoveJoints_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJoints_SendGoal_Response_stamp accepted(::roarm_interfaces::action::MoveJoints_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveJoints_SendGoal_Response_stamp(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_interfaces::action::MoveJoints_SendGoal_Response>()
{
  return roarm_interfaces::action::builder::Init_MoveJoints_SendGoal_Response_accepted();
}

}  // namespace roarm_interfaces


namespace roarm_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveJoints_GetResult_Request_goal_id
{
public:
  Init_MoveJoints_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::roarm_interfaces::action::MoveJoints_GetResult_Request goal_id(::roarm_interfaces::action::MoveJoints_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_interfaces::action::MoveJoints_GetResult_Request>()
{
  return roarm_interfaces::action::builder::Init_MoveJoints_GetResult_Request_goal_id();
}

}  // namespace roarm_interfaces


namespace roarm_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveJoints_GetResult_Response_result
{
public:
  explicit Init_MoveJoints_GetResult_Response_result(::roarm_interfaces::action::MoveJoints_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::roarm_interfaces::action::MoveJoints_GetResult_Response result(::roarm_interfaces::action::MoveJoints_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_GetResult_Response msg_;
};

class Init_MoveJoints_GetResult_Response_status
{
public:
  Init_MoveJoints_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJoints_GetResult_Response_result status(::roarm_interfaces::action::MoveJoints_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveJoints_GetResult_Response_result(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_interfaces::action::MoveJoints_GetResult_Response>()
{
  return roarm_interfaces::action::builder::Init_MoveJoints_GetResult_Response_status();
}

}  // namespace roarm_interfaces


namespace roarm_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveJoints_FeedbackMessage_feedback
{
public:
  explicit Init_MoveJoints_FeedbackMessage_feedback(::roarm_interfaces::action::MoveJoints_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::roarm_interfaces::action::MoveJoints_FeedbackMessage feedback(::roarm_interfaces::action::MoveJoints_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_FeedbackMessage msg_;
};

class Init_MoveJoints_FeedbackMessage_goal_id
{
public:
  Init_MoveJoints_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJoints_FeedbackMessage_feedback goal_id(::roarm_interfaces::action::MoveJoints_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveJoints_FeedbackMessage_feedback(msg_);
  }

private:
  ::roarm_interfaces::action::MoveJoints_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_interfaces::action::MoveJoints_FeedbackMessage>()
{
  return roarm_interfaces::action::builder::Init_MoveJoints_FeedbackMessage_goal_id();
}

}  // namespace roarm_interfaces

#endif  // ROARM_INTERFACES__ACTION__DETAIL__MOVE_JOINTS__BUILDER_HPP_
