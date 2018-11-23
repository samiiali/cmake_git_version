cmake_minimum_required(VERSION 3.2)
project(auto_mapped)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
include(git_ver)
git_ver(GIT_TAG GIT_BRANCH GIT_COMMIT_HASH)

message ("++ Git current tag: ${GIT_TAG}")
message ("++ Git current branch: ${GIT_BRANCH}")
message ("++ Git commit hash: ${GIT_COMMIT_HASH}")
 
#message (STATUS "Generating version.h")
configure_file (
  "${CMAKE_MODULE_PATH}/version.h.in"
  "${CMAKE_BINARY_DIR}/cmake/include/version.h"
)
 include_directories (${CMAKE_BINARY_DIR}/cmake/include)

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
