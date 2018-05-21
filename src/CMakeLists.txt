cmake_minimum_required(VERSION 3.7)

project(objsrcs)
FILE(GLOB OBJSRCS "*.cpp" "*.hpp")
include_directories(../../boost/installation/include)
add_library(objsrcs OBJECT ${OBJSRCS})
add_definitions(-std=c++11)