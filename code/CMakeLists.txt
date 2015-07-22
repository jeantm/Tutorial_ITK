# This is the root ITK CmakeList file:
cmake_minimum_required(VERSION 3.1)

project(Test)

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

# Use mainTest.xml file to manage I/O
# set(Threshold_SOURCE mainTest.cpp)
# GENERATECLP(mainTest_SOURCE mainTest.xml)

add_executable(Test mainTest.cpp)

target_link_libraries(Test ${ITK_LIBRARIES})
