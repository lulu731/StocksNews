cmake_minimum_required(VERSION 3.7)

## Use the variable PROJECT_NAME for changing the target name
set( PROJECT_NAME "stocksnews" )

## Set our project name
project(${PROJECT_NAME})

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "main.cpp" "src/*.hpp" "src/*.cpp")

## Define the executable
set(BOOST_INSTALLATION "../boost/installation/")
include_directories(../boost/installation/include)
add_executable(${PROJECT_NAME} ${SRCS})
add_definitions(-std=c++11 -O3 -Wall)

find_library(BOOST_SYST NAMES boost_system PATHS ${BOOST_INSTALLATION}lib)
find_library(THREAD NAMES pthread PATHS /usr/lib)
find_library(SSL NAMES ssl PATHS /usr/lib)
find_library(CRYPTO NAMES crypto PATHS /usr/lib)
find_library(BOOST_FILE_SYST NAMES boost_filesystem PATHS ${BOOST_INSTALLATION}lib)
find_library(BOOST_TIMER NAMES boost_timer PATHS ${BOOST_INSTALLATION}lib)
find_library(BOOST_CHRONO NAMES boost_chrono PATHS ${BOOST_INSTALLATION}lib)
target_link_libraries(${PROJECT_NAME} ${BOOST_CHRONO} ${BOOST_SYST} ${BOOST_FILE_SYST} ${BOOST_TIMER} ${THREAD} ${SSL} ${CRYPTO})