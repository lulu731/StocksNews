cmake_minimum_required(VERSION 3.7)
set( PROJECT_NAME "stocksnews" )
project(${PROJECT_NAME})

SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_subdirectory(tests)
add_subdirectory(src)

FILE(GLOB SRCS "main.cpp")
add_executable(${PROJECT_NAME} ${SRCS}  $<TARGET_OBJECTS:objsrcs>)
add_definitions(-std=c++11 -Wall -Wextra)

set(BOOST_INSTALLATION "../boost/installation")
include_directories(${BOOST_INSTALLATION}/include)
find_library(BOOST_TEST NAMES boost_unit_test_framework PATHS ${BOOST_INSTALLATION}/lib)
find_library(BOOST_SYST NAMES boost_system PATHS ${BOOST_INSTALLATION}/lib)
find_library(THREAD NAMES pthread PATHS /usr/lib)
find_library(SSL NAMES ssl PATHS /usr/lib)
find_library(CRYPTO NAMES crypto PATHS /usr/lib)
find_library(BOOST_FILE_SYST NAMES boost_filesystem PATHS ${BOOST_INSTALLATION}/lib)
find_library(BOOST_TIMER NAMES boost_timer PATHS ${BOOST_INSTALLATION}/lib)
find_library(BOOST_CHRONO NAMES boost_chrono PATHS ${BOOST_INSTALLATION}/lib)
target_link_libraries(${PROJECT_NAME} ${BOOST_CHRONO} ${BOOST_SYST} ${BOOST_FILE_SYST} ${BOOST_TIMER} ${THREAD} ${SSL} ${CRYPTO})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ~/stocks_news CONFIGURATIONS Release)
#install(FILES ${CMAKE_SOURCE_DIR}/stocks/stocks_database_Paris.csv DESTINATION ~/stocks_news/stocks 
#	CONFIGURATIONS Release)

include(CTest)
add_test(snHelp ${PROJECT_NAME} ForTest)
set_tests_properties(snHelp PROPERTIES PASS_REGULAR_EXPRESSION 
	"usage : ./stocksnews Paris --update\n./stocksnews Paris --maxrate 3\n./stocksnews Paris --maxnumbers 5\n")

add_test(snUpdate ${PROJECT_NAME} ForTest --update)
set_tests_properties(snUpdate PROPERTIES PASS_REGULAR_EXPRESSION "")

add_test(snDisplay ${PROJECT_NAME} ForTest --display 3)