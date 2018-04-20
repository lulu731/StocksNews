cmake_minimum_required(VERSION 3.7)

set( PROJECT_NAME "tests" )

## Set our project name
project(${PROJECT_NAME})

FILE(GLOB SRCS "*.cpp" "../src/*.cpp" "../src/*.hpp")

add_executable(${PROJECT_NAME} ${SRCS})

find_library(BOOST_TEST NAMES boost_unit_test_framework PATHS /usr/lib)
target_link_libraries(tests ${BOOST_TEST})

find_library(BOOST_SYST NAMES boost_system PATHS /usr/lib)
target_link_libraries(${PROJECT_NAME} ${BOOST_SYST})

find_library(THREAD NAMES pthread PATHS /usr/lib)
target_link_libraries(${PROJECT_NAME} ${THREAD})

find_library(SSL NAMES ssl PATHS /usr/lib)
target_link_libraries(${PROJECT_NAME} ${SSL})

find_library(CRYPTO NAMES crypto PATHS /usr/lib)
target_link_libraries(${PROJECT_NAME} ${CRYPTO})

find_library(FILE_SYST NAMES boost_filesystem PATHS /usr/lib)
target_link_libraries(${PROJECT_NAME} ${FILE_SYST})

#add_custom_target(run ./tests DEPENDS tests)
