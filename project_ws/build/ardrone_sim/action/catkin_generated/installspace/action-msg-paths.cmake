# generated from genmsg/cmake/pkg-msg-paths.cmake.em

# message include dirs in installspace
_prepend_path("${action_DIR}/.." "msg" action_MSG_INCLUDE_DIRS UNIQUE)
set(action_MSG_DEPENDENCIES actionlib_msgs;std_msgs)