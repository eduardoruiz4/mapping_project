if("2f987029c55531e4c0119c3600f9c57f935851ed" STREQUAL "")
  message(FATAL_ERROR "Tag for git checkout should not be empty.")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/eduardorz/project_ws/devel/src/ardronelib"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/eduardorz/project_ws/devel/src/ardronelib'")
endif()

execute_process(
  COMMAND "/usr/bin/git" clone "git://github.com/AutonomyLab/ardronelib.git" "ardronelib"
  WORKING_DIRECTORY "/home/eduardorz/project_ws/devel/src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'git://github.com/AutonomyLab/ardronelib.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git" checkout 2f987029c55531e4c0119c3600f9c57f935851ed
  WORKING_DIRECTORY "/home/eduardorz/project_ws/devel/src/ardronelib"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '2f987029c55531e4c0119c3600f9c57f935851ed'")
endif()

execute_process(
  COMMAND "/usr/bin/git" submodule init
  WORKING_DIRECTORY "/home/eduardorz/project_ws/devel/src/ardronelib"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to init submodules in: '/home/eduardorz/project_ws/devel/src/ardronelib'")
endif()

execute_process(
  COMMAND "/usr/bin/git" submodule update --recursive
  WORKING_DIRECTORY "/home/eduardorz/project_ws/devel/src/ardronelib"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/eduardorz/project_ws/devel/src/ardronelib'")
endif()

