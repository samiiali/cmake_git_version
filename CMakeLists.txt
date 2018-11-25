cmake_minimum_required(VERSION 3.2)
project(auto_mapped)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(git_ver)
git_ver(GIT_TAG GIT_BRANCH GIT_COMMIT_HASH)

message ("++ Git current tag: ${GIT_TAG}")
message ("++ Git current branch: ${GIT_BRANCH}")
message ("++ Git commit hash: ${GIT_COMMIT_HASH}")
 
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

if (${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
    message(STATUS "Prodcusing profiling and coverage info.")
    add_compile_options(-g --coverage)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_C_FLAGS} --coverage")
elseif (${CMAKE_CXX_COMPILER_ID} MATCHES GNU)
    message(STATUS "Prodcusing profiling and coverage info.")
    add_compile_options(-g -fprofile-arcs -ftest-coverage)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_C_FLAGS} --coverage")
endif ()

enable_testing()

add_executable(${PROJECT_NAME} "main.cpp;fruit_factory.cpp")
add_test(test0 ${PROJECT_NAME})

add_executable(test1_exec "wrong_init1.cpp;fruit_factory.cpp")
add_test(test1 test1_exec)
set_property(
    TEST test1
    PROPERTY PASS_REGULAR_EXPRESSION
    " bad initializtion !"
    )