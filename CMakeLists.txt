cmake_minimum_required(VERSION 3.1)

project(Test)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(Test mainTest.cpp)

target_link_libraries(Test ${ITK_LIBRARIES})
