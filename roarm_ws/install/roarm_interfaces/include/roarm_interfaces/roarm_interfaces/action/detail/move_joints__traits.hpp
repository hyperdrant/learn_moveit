// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roarm_interfaces:action/MoveJoints.idl
// generated code does not contain a copyright notice

#ifndef ROARM_INTERFACES__ACTION__DETAIL__MOVE_JOINTS__TRAITS_HPP_
#define ROARM_INTERFACES__ACTION__DETAIL__MOVE_JOINTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "roarm_interfaces/action/detail/move_joints__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace roarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveJoints_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint_names
  {
    if (msg.joint_names.size() == 0) {
      out << "joint_names: []";
    } else {
      out << "joint_names: [";
      size_t pending_items = msg.joint_names.size();
      for (auto item : msg.joint_names) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: positions
  {
    if (msg.positions.size() == 0) {
      out << "positions: []";
    } else {
      out << "positions: [";
      size_t pending_items = msg.positions.size();
      for (auto item : msg.positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJoints_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint_names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_names.size() == 0) {
      out << "joint_names: []\n";
    } else {
      out << "joint_names:\n";
      for (auto item : msg.joint_names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions.size() == 0) {
      out << "positions: []\n";
    } else {
      out << "positions:\n";
      for (auto item : msg.positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJoints_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace roarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use roarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roarm_interfaces::action::MoveJoints_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  roarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const roarm_interfaces::action::MoveJoints_Goal & msg)
{
  return roarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_Goal>()
{
  return "roarm_interfaces::action::MoveJoints_Goal";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_Goal>()
{
  return "roarm_interfaces/action/MoveJoints_Goal";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roarm_interfaces::action::MoveJoints_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace roarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveJoints_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: final_positions
  {
    if (msg.final_positions.size() == 0) {
      out << "final_positions: []";
    } else {
      out << "final_positions: [";
      size_t pending_items = msg.final_positions.size();
      for (auto item : msg.final_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: max_error
  {
    out << "max_error: ";
    rosidl_generator_traits::value_to_yaml(msg.max_error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJoints_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: final_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.final_positions.size() == 0) {
      out << "final_positions: []\n";
    } else {
      out << "final_positions:\n";
      for (auto item : msg.final_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: max_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_error: ";
    rosidl_generator_traits::value_to_yaml(msg.max_error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJoints_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace roarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use roarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roarm_interfaces::action::MoveJoints_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  roarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const roarm_interfaces::action::MoveJoints_Result & msg)
{
  return roarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_Result>()
{
  return "roarm_interfaces::action::MoveJoints_Result";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_Result>()
{
  return "roarm_interfaces/action/MoveJoints_Result";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roarm_interfaces::action::MoveJoints_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace roarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveJoints_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_positions
  {
    if (msg.current_positions.size() == 0) {
      out << "current_positions: []";
    } else {
      out << "current_positions: [";
      size_t pending_items = msg.current_positions.size();
      for (auto item : msg.current_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: progress
  {
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJoints_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current_positions.size() == 0) {
      out << "current_positions: []\n";
    } else {
      out << "current_positions:\n";
      for (auto item : msg.current_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJoints_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace roarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use roarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roarm_interfaces::action::MoveJoints_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  roarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const roarm_interfaces::action::MoveJoints_Feedback & msg)
{
  return roarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_Feedback>()
{
  return "roarm_interfaces::action::MoveJoints_Feedback";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_Feedback>()
{
  return "roarm_interfaces/action/MoveJoints_Feedback";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roarm_interfaces::action::MoveJoints_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "roarm_interfaces/action/detail/move_joints__traits.hpp"

namespace roarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveJoints_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJoints_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJoints_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace roarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use roarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roarm_interfaces::action::MoveJoints_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  roarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const roarm_interfaces::action::MoveJoints_SendGoal_Request & msg)
{
  return roarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_SendGoal_Request>()
{
  return "roarm_interfaces::action::MoveJoints_SendGoal_Request";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_SendGoal_Request>()
{
  return "roarm_interfaces/action/MoveJoints_SendGoal_Request";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<roarm_interfaces::action::MoveJoints_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<roarm_interfaces::action::MoveJoints_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<roarm_interfaces::action::MoveJoints_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace roarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveJoints_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJoints_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJoints_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace roarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use roarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roarm_interfaces::action::MoveJoints_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  roarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const roarm_interfaces::action::MoveJoints_SendGoal_Response & msg)
{
  return roarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_SendGoal_Response>()
{
  return "roarm_interfaces::action::MoveJoints_SendGoal_Response";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_SendGoal_Response>()
{
  return "roarm_interfaces/action/MoveJoints_SendGoal_Response";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<roarm_interfaces::action::MoveJoints_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_SendGoal>()
{
  return "roarm_interfaces::action::MoveJoints_SendGoal";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_SendGoal>()
{
  return "roarm_interfaces/action/MoveJoints_SendGoal";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<roarm_interfaces::action::MoveJoints_SendGoal_Request>::value &&
    has_fixed_size<roarm_interfaces::action::MoveJoints_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<roarm_interfaces::action::MoveJoints_SendGoal_Request>::value &&
    has_bounded_size<roarm_interfaces::action::MoveJoints_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<roarm_interfaces::action::MoveJoints_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<roarm_interfaces::action::MoveJoints_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<roarm_interfaces::action::MoveJoints_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace roarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveJoints_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJoints_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJoints_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace roarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use roarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roarm_interfaces::action::MoveJoints_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  roarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const roarm_interfaces::action::MoveJoints_GetResult_Request & msg)
{
  return roarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_GetResult_Request>()
{
  return "roarm_interfaces::action::MoveJoints_GetResult_Request";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_GetResult_Request>()
{
  return "roarm_interfaces/action/MoveJoints_GetResult_Request";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<roarm_interfaces::action::MoveJoints_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "roarm_interfaces/action/detail/move_joints__traits.hpp"

namespace roarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveJoints_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJoints_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJoints_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace roarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use roarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roarm_interfaces::action::MoveJoints_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  roarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const roarm_interfaces::action::MoveJoints_GetResult_Response & msg)
{
  return roarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_GetResult_Response>()
{
  return "roarm_interfaces::action::MoveJoints_GetResult_Response";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_GetResult_Response>()
{
  return "roarm_interfaces/action/MoveJoints_GetResult_Response";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<roarm_interfaces::action::MoveJoints_Result>::value> {};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<roarm_interfaces::action::MoveJoints_Result>::value> {};

template<>
struct is_message<roarm_interfaces::action::MoveJoints_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_GetResult>()
{
  return "roarm_interfaces::action::MoveJoints_GetResult";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_GetResult>()
{
  return "roarm_interfaces/action/MoveJoints_GetResult";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<roarm_interfaces::action::MoveJoints_GetResult_Request>::value &&
    has_fixed_size<roarm_interfaces::action::MoveJoints_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<roarm_interfaces::action::MoveJoints_GetResult_Request>::value &&
    has_bounded_size<roarm_interfaces::action::MoveJoints_GetResult_Response>::value
  >
{
};

template<>
struct is_service<roarm_interfaces::action::MoveJoints_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<roarm_interfaces::action::MoveJoints_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<roarm_interfaces::action::MoveJoints_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "roarm_interfaces/action/detail/move_joints__traits.hpp"

namespace roarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveJoints_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveJoints_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveJoints_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace roarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use roarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const roarm_interfaces::action::MoveJoints_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  roarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use roarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const roarm_interfaces::action::MoveJoints_FeedbackMessage & msg)
{
  return roarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<roarm_interfaces::action::MoveJoints_FeedbackMessage>()
{
  return "roarm_interfaces::action::MoveJoints_FeedbackMessage";
}

template<>
inline const char * name<roarm_interfaces::action::MoveJoints_FeedbackMessage>()
{
  return "roarm_interfaces/action/MoveJoints_FeedbackMessage";
}

template<>
struct has_fixed_size<roarm_interfaces::action::MoveJoints_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<roarm_interfaces::action::MoveJoints_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<roarm_interfaces::action::MoveJoints_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<roarm_interfaces::action::MoveJoints_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<roarm_interfaces::action::MoveJoints_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<roarm_interfaces::action::MoveJoints>
  : std::true_type
{
};

template<>
struct is_action_goal<roarm_interfaces::action::MoveJoints_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<roarm_interfaces::action::MoveJoints_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<roarm_interfaces::action::MoveJoints_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ROARM_INTERFACES__ACTION__DETAIL__MOVE_JOINTS__TRAITS_HPP_
