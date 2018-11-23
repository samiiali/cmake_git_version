cmake_minimum_required(VERSION 3.2)
project(auto_mapped)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

if (EXISTS "${CMAKE_SOURCE_DIR}/.git")
  execute_process (
    COMMAND git describe --tags --dirty
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
 
  execute_process (
    COMMAND git rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
 
  execute_process (
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
else (EXISTS "${CMAKE_SOURCE_DIR}/.git")
  set (GIT_TAG "")
  set (GIT_BRANCH "")
  set (GIT_COMMIT_HASH "")
endif (EXISTS "${CMAKE_SOURCE_DIR}/.git")
 
message ("++ Git current tag: ${GIT_TAG}")
message ("++ Git current branch: ${GIT_BRANCH}")
message ("++ Git commit hash: ${GIT_COMMIT_HASH}")
 
message (STATUS "Generating version.h")

configure_file (
  "${CMAKE_MODULE_PATH}/version.h.in"
  "${CMAKE_BINARY_DIR}/cmake/include/version.h"
)
 
include_directories (${CMAKE_BINARY_DIR}/cmake/include)
include_directories (${CMAKE_SOURCE_DIR}/include)

if (MSVC)
    add_compile_options(/W4)
elseif (UNIX)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(${PROJECT_NAME} "main.cpp;fruit_factory.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)

# We add the following line to always run cmake once, prior to make
add_custom_target (do_always ALL COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}
                   COMMENT "Running cmake prior to make.")
