cmake_minimum_required(VERSION 3.7)

set( PROJECT_NAME "tests" )
project(${PROJECT_NAME})
FILE(GLOB TESTSSRCS "*.cpp" "*.hpp")

set(BOOST_INSTALLATION "../../boost/installation")
include_directories(${BOOST_INSTALLATION}/include)
add_executable(${PROJECT_NAME} ${TESTSSRCS} $<TARGET_OBJECTS:objsrcs>)

find_library(BOOST_TEST NAMES boost_unit_test_framework PATHS ${BOOST_INSTALLATION}/lib)
find_library(BOOST_SYST NAMES boost_system PATHS ${BOOST_INSTALLATION}/lib)
find_library(THREAD NAMES pthread PATHS /usr/lib)
find_library(SSL NAMES ssl PATHS /usr/lib)
find_library(CRYPTO NAMES crypto PATHS /usr/lib)
find_library(BOOST_FILE_SYST NAMES boost_filesystem PATHS ${BOOST_INSTALLATION}/lib)
find_library(BOOST_TIMER NAMES boost_timer PATHS ${BOOST_INSTALLATION}/lib)
find_library(BOOST_CHRONO NAMES boost_chrono PATHS ${BOOST_INSTALLATION}/lib)
target_link_libraries(${PROJECT_NAME} ${BOOST_TEST} ${BOOST_CHRONO} ${BOOST_SYST} ${BOOST_FILE_SYST} ${BOOST_TIMER} ${THREAD} ${SSL} ${CRYPTO})