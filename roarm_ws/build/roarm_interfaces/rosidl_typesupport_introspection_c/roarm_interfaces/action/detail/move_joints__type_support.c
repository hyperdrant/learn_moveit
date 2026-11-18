// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from roarm_interfaces:action/MoveJoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
#include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "roarm_interfaces/action/detail/move_joints__functions.h"
#include "roarm_interfaces/action/detail/move_joints__struct.h"


// Include directives for member types
// Member `joint_names`
#include "rosidl_runtime_c/string_functions.h"
// Member `positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roarm_interfaces__action__MoveJoints_Goal__init(message_memory);
}

void roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_fini_function(void * message_memory)
{
  roarm_interfaces__action__MoveJoints_Goal__fini(message_memory);
}

size_t roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__size_function__MoveJoints_Goal__joint_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Goal__joint_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_function__MoveJoints_Goal__joint_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__fetch_function__MoveJoints_Goal__joint_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Goal__joint_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__assign_function__MoveJoints_Goal__joint_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_function__MoveJoints_Goal__joint_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__resize_function__MoveJoints_Goal__joint_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__size_function__MoveJoints_Goal__positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Goal__positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_function__MoveJoints_Goal__positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__fetch_function__MoveJoints_Goal__positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Goal__positions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__assign_function__MoveJoints_Goal__positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_function__MoveJoints_Goal__positions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__resize_function__MoveJoints_Goal__positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_message_member_array[3] = {
  {
    "joint_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_Goal, joint_names),  // bytes offset in struct
    NULL,  // default value
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__size_function__MoveJoints_Goal__joint_names,  // size() function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Goal__joint_names,  // get_const(index) function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_function__MoveJoints_Goal__joint_names,  // get(index) function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__fetch_function__MoveJoints_Goal__joint_names,  // fetch(index, &value) function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__assign_function__MoveJoints_Goal__joint_names,  // assign(index, value) function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__resize_function__MoveJoints_Goal__joint_names  // resize(index) function pointer
  },
  {
    "positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_Goal, positions),  // bytes offset in struct
    NULL,  // default value
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__size_function__MoveJoints_Goal__positions,  // size() function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Goal__positions,  // get_const(index) function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__get_function__MoveJoints_Goal__positions,  // get(index) function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__fetch_function__MoveJoints_Goal__positions,  // fetch(index, &value) function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__assign_function__MoveJoints_Goal__positions,  // assign(index, value) function pointer
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__resize_function__MoveJoints_Goal__positions  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_Goal, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_message_members = {
  "roarm_interfaces__action",  // message namespace
  "MoveJoints_Goal",  // message name
  3,  // number of fields
  sizeof(roarm_interfaces__action__MoveJoints_Goal),
  roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_message_member_array,  // message members
  roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_message_type_support_handle = {
  0,
  &roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_Goal)() {
  if (!roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_message_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roarm_interfaces__action__MoveJoints_Goal__rosidl_typesupport_introspection_c__MoveJoints_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__functions.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `final_positions`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roarm_interfaces__action__MoveJoints_Result__init(message_memory);
}

void roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_fini_function(void * message_memory)
{
  roarm_interfaces__action__MoveJoints_Result__fini(message_memory);
}

size_t roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__size_function__MoveJoints_Result__final_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Result__final_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__get_function__MoveJoints_Result__final_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__fetch_function__MoveJoints_Result__final_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Result__final_positions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__assign_function__MoveJoints_Result__final_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__get_function__MoveJoints_Result__final_positions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__resize_function__MoveJoints_Result__final_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_message_member_array[4] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_Result, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_Result, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "final_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_Result, final_positions),  // bytes offset in struct
    NULL,  // default value
    roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__size_function__MoveJoints_Result__final_positions,  // size() function pointer
    roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Result__final_positions,  // get_const(index) function pointer
    roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__get_function__MoveJoints_Result__final_positions,  // get(index) function pointer
    roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__fetch_function__MoveJoints_Result__final_positions,  // fetch(index, &value) function pointer
    roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__assign_function__MoveJoints_Result__final_positions,  // assign(index, value) function pointer
    roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__resize_function__MoveJoints_Result__final_positions  // resize(index) function pointer
  },
  {
    "max_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_Result, max_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_message_members = {
  "roarm_interfaces__action",  // message namespace
  "MoveJoints_Result",  // message name
  4,  // number of fields
  sizeof(roarm_interfaces__action__MoveJoints_Result),
  roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_message_member_array,  // message members
  roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_message_type_support_handle = {
  0,
  &roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_Result)() {
  if (!roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_message_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roarm_interfaces__action__MoveJoints_Result__rosidl_typesupport_introspection_c__MoveJoints_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__functions.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__struct.h"


// Include directives for member types
// Member `current_positions`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roarm_interfaces__action__MoveJoints_Feedback__init(message_memory);
}

void roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_fini_function(void * message_memory)
{
  roarm_interfaces__action__MoveJoints_Feedback__fini(message_memory);
}

size_t roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__size_function__MoveJoints_Feedback__current_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Feedback__current_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__get_function__MoveJoints_Feedback__current_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__fetch_function__MoveJoints_Feedback__current_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Feedback__current_positions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__assign_function__MoveJoints_Feedback__current_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__get_function__MoveJoints_Feedback__current_positions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__resize_function__MoveJoints_Feedback__current_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_message_member_array[2] = {
  {
    "current_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_Feedback, current_positions),  // bytes offset in struct
    NULL,  // default value
    roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__size_function__MoveJoints_Feedback__current_positions,  // size() function pointer
    roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__get_const_function__MoveJoints_Feedback__current_positions,  // get_const(index) function pointer
    roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__get_function__MoveJoints_Feedback__current_positions,  // get(index) function pointer
    roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__fetch_function__MoveJoints_Feedback__current_positions,  // fetch(index, &value) function pointer
    roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__assign_function__MoveJoints_Feedback__current_positions,  // assign(index, value) function pointer
    roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__resize_function__MoveJoints_Feedback__current_positions  // resize(index) function pointer
  },
  {
    "progress",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_Feedback, progress),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_message_members = {
  "roarm_interfaces__action",  // message namespace
  "MoveJoints_Feedback",  // message name
  2,  // number of fields
  sizeof(roarm_interfaces__action__MoveJoints_Feedback),
  roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_message_member_array,  // message members
  roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_message_type_support_handle = {
  0,
  &roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_Feedback)() {
  if (!roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_message_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roarm_interfaces__action__MoveJoints_Feedback__rosidl_typesupport_introspection_c__MoveJoints_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__functions.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "roarm_interfaces/action/move_joints.h"
// Member `goal`
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roarm_interfaces__action__MoveJoints_SendGoal_Request__init(message_memory);
}

void roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_fini_function(void * message_memory)
{
  roarm_interfaces__action__MoveJoints_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_members = {
  "roarm_interfaces__action",  // message namespace
  "MoveJoints_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(roarm_interfaces__action__MoveJoints_SendGoal_Request),
  roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_member_array,  // message members
  roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_type_support_handle = {
  0,
  &roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_SendGoal_Request)() {
  roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_Goal)();
  if (!roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roarm_interfaces__action__MoveJoints_SendGoal_Request__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__functions.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roarm_interfaces__action__MoveJoints_SendGoal_Response__init(message_memory);
}

void roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_fini_function(void * message_memory)
{
  roarm_interfaces__action__MoveJoints_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_members = {
  "roarm_interfaces__action",  // message namespace
  "MoveJoints_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(roarm_interfaces__action__MoveJoints_SendGoal_Response),
  roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_member_array,  // message members
  roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_type_support_handle = {
  0,
  &roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_SendGoal_Response)() {
  roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roarm_interfaces__action__MoveJoints_SendGoal_Response__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_service_members = {
  "roarm_interfaces__action",  // service namespace
  "MoveJoints_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_service_type_support_handle = {
  0,
  &roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_SendGoal)() {
  if (!roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_service_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_SendGoal_Response)()->data;
  }

  return &roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__functions.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roarm_interfaces__action__MoveJoints_GetResult_Request__init(message_memory);
}

void roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_fini_function(void * message_memory)
{
  roarm_interfaces__action__MoveJoints_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_members = {
  "roarm_interfaces__action",  // message namespace
  "MoveJoints_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(roarm_interfaces__action__MoveJoints_GetResult_Request),
  roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_member_array,  // message members
  roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_type_support_handle = {
  0,
  &roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_GetResult_Request)() {
  roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roarm_interfaces__action__MoveJoints_GetResult_Request__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__functions.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "roarm_interfaces/action/move_joints.h"
// Member `result`
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roarm_interfaces__action__MoveJoints_GetResult_Response__init(message_memory);
}

void roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_fini_function(void * message_memory)
{
  roarm_interfaces__action__MoveJoints_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_members = {
  "roarm_interfaces__action",  // message namespace
  "MoveJoints_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(roarm_interfaces__action__MoveJoints_GetResult_Response),
  roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_member_array,  // message members
  roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_type_support_handle = {
  0,
  &roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_GetResult_Response)() {
  roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_Result)();
  if (!roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roarm_interfaces__action__MoveJoints_GetResult_Response__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_GetResult_service_members = {
  "roarm_interfaces__action",  // service namespace
  "MoveJoints_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_GetResult_service_type_support_handle = {
  0,
  &roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_GetResult)() {
  if (!roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_GetResult_service_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_GetResult_Response)()->data;
  }

  return &roarm_interfaces__action__detail__move_joints__rosidl_typesupport_introspection_c__MoveJoints_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"
// already included above
// #include "roarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__functions.h"
// already included above
// #include "roarm_interfaces/action/detail/move_joints__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "roarm_interfaces/action/move_joints.h"
// Member `feedback`
// already included above
// #include "roarm_interfaces/action/detail/move_joints__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roarm_interfaces__action__MoveJoints_FeedbackMessage__init(message_memory);
}

void roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_fini_function(void * message_memory)
{
  roarm_interfaces__action__MoveJoints_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roarm_interfaces__action__MoveJoints_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_members = {
  "roarm_interfaces__action",  // message namespace
  "MoveJoints_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(roarm_interfaces__action__MoveJoints_FeedbackMessage),
  roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_member_array,  // message members
  roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_type_support_handle = {
  0,
  &roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_FeedbackMessage)() {
  roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roarm_interfaces, action, MoveJoints_Feedback)();
  if (!roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &roarm_interfaces__action__MoveJoints_FeedbackMessage__rosidl_typesupport_introspection_c__MoveJoints_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
