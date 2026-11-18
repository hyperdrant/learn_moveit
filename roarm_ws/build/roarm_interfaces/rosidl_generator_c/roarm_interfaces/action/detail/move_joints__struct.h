// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roarm_interfaces:action/MoveJoints.idl
// generated code does not contain a copyright notice

#ifndef ROARM_INTERFACES__ACTION__DETAIL__MOVE_JOINTS__STRUCT_H_
#define ROARM_INTERFACES__ACTION__DETAIL__MOVE_JOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_names'
#include "rosidl_runtime_c/string.h"
// Member 'positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/MoveJoints in the package roarm_interfaces.
typedef struct roarm_interfaces__action__MoveJoints_Goal
{
  /// ===== Goal：客户端发来的请求 =====
  /// 关节名，必须是驱动认识的名字：base_joint, shoulder_joint, elbow_joint, hand_joint
  /// 可以只给其中一部分，没给的关节保持不动
  rosidl_runtime_c__String__Sequence joint_names;
  /// 目标角度，单位 rad，和 joint_names 一一对应
  rosidl_runtime_c__double__Sequence positions;
  /// 期望用时，单位 s；<= 0 表示由驱动按参数 default_speed 自动计算
  double duration;
} roarm_interfaces__action__MoveJoints_Goal;

// Struct for a sequence of roarm_interfaces__action__MoveJoints_Goal.
typedef struct roarm_interfaces__action__MoveJoints_Goal__Sequence
{
  roarm_interfaces__action__MoveJoints_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_interfaces__action__MoveJoints_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'final_positions'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/MoveJoints in the package roarm_interfaces.
typedef struct roarm_interfaces__action__MoveJoints_Result
{
  bool success;
  rosidl_runtime_c__String message;
  /// 结束时各关节的实际角度（顺序同 joint_names）
  rosidl_runtime_c__double__Sequence final_positions;
  /// 结束时与目标的最大误差，单位 rad
  double max_error;
} roarm_interfaces__action__MoveJoints_Result;

// Struct for a sequence of roarm_interfaces__action__MoveJoints_Result.
typedef struct roarm_interfaces__action__MoveJoints_Result__Sequence
{
  roarm_interfaces__action__MoveJoints_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_interfaces__action__MoveJoints_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_positions'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/MoveJoints in the package roarm_interfaces.
typedef struct roarm_interfaces__action__MoveJoints_Feedback
{
  rosidl_runtime_c__double__Sequence current_positions;
  /// 进度 0.0 ~ 1.0
  double progress;
} roarm_interfaces__action__MoveJoints_Feedback;

// Struct for a sequence of roarm_interfaces__action__MoveJoints_Feedback.
typedef struct roarm_interfaces__action__MoveJoints_Feedback__Sequence
{
  roarm_interfaces__action__MoveJoints_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_interfaces__action__MoveJoints_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "roarm_interfaces/action/detail/move_joints__struct.h"

/// Struct defined in action/MoveJoints in the package roarm_interfaces.
typedef struct roarm_interfaces__action__MoveJoints_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  roarm_interfaces__action__MoveJoints_Goal goal;
} roarm_interfaces__action__MoveJoints_SendGoal_Request;

// Struct for a sequence of roarm_interfaces__action__MoveJoints_SendGoal_Request.
typedef struct roarm_interfaces__action__MoveJoints_SendGoal_Request__Sequence
{
  roarm_interfaces__action__MoveJoints_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_interfaces__action__MoveJoints_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MoveJoints in the package roarm_interfaces.
typedef struct roarm_interfaces__action__MoveJoints_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} roarm_interfaces__action__MoveJoints_SendGoal_Response;

// Struct for a sequence of roarm_interfaces__action__MoveJoints_SendGoal_Response.
typedef struct roarm_interfaces__action__MoveJoints_SendGoal_Response__Sequence
{
  roarm_interfaces__action__MoveJoints_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_interfaces__action__MoveJoints_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MoveJoints in the package roarm_interfaces.
typedef struct roarm_interfaces__action__MoveJoints_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} roarm_interfaces__action__MoveJoints_GetResult_Request;

// Struct for a sequence of roarm_interfaces__action__MoveJoints_GetResult_Request.
typedef struct roarm_interfaces__action__MoveJoints_GetResult_Request__Sequence
{
  roarm_interfaces__action__MoveJoints_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_interfaces__action__MoveJoints_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "roarm_interfaces/action/detail/move_joints__struct.h"

/// Struct defined in action/MoveJoints in the package roarm_interfaces.
typedef struct roarm_interfaces__action__MoveJoints_GetResult_Response
{
  int8_t status;
  roarm_interfaces__action__MoveJoints_Result result;
} roarm_interfaces__action__MoveJoints_GetResult_Response;

// Struct for a sequence of roarm_interfaces__action__MoveJoints_GetResult_Response.
typedef struct roarm_interfaces__action__MoveJoints_GetResult_Response__Sequence
{
  roarm_interfaces__action__MoveJoints_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_interfaces__action__MoveJoints_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "roarm_interfaces/action/detail/move_joints__struct.h"

/// Struct defined in action/MoveJoints in the package roarm_interfaces.
typedef struct roarm_interfaces__action__MoveJoints_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  roarm_interfaces__action__MoveJoints_Feedback feedback;
} roarm_interfaces__action__MoveJoints_FeedbackMessage;

// Struct for a sequence of roarm_interfaces__action__MoveJoints_FeedbackMessage.
typedef struct roarm_interfaces__action__MoveJoints_FeedbackMessage__Sequence
{
  roarm_interfaces__action__MoveJoints_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_interfaces__action__MoveJoints_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROARM_INTERFACES__ACTION__DETAIL__MOVE_JOINTS__STRUCT_H_
