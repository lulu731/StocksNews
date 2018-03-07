cmake_minimum_required(VERSION 3.7)

## Use the variable PROJECT_NAME for changing the target name
set( PROJECT_NAME "TestsStockNews" )

## Set our project name
project(${PROJECT_NAME})

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "*.cpp" "*.c" "*.hpp")

## Define the executable
add_executable(${PROJECT_NAME} ${SRCS})

find_library(BOOST_SYST NAMES boost_system PATHS /usr/lib)
target_link_libraries( ${PROJECT_NAME} ${BOOST_SYST})

find_library(THREAD NAMES pthread PATHS /usr/lib)
target_link_libraries( ${PROJECT_NAME} ${THREAD})

find_library(SSL NAMES ssl PATHS /usr/lib)
target_link_libraries( ${PROJECT_NAME} ${SSL})

find_library(CRYPTO NAMES crypto PATHS /usr/lib)
target_link_libraries( ${PROJECT_NAME} ${CRYPTO})
