set( UNITS_TESTS "tests" )

FILE(GLOB TESTSSRCS "*.cpp" "*.hpp")

set(BOOST_INSTALLATION "../../boost/installation")
include_directories(${BOOST_INSTALLATION}/include)
add_executable(${UNITS_TESTS} ${TESTSSRCS} $<TARGET_OBJECTS:objsrcs>)
add_definitions(-std=c++11 -Wall -Wextra)

find_library(BOOST_TEST NAMES boost_unit_test_framework PATHS ${BOOST_INSTALLATION}/lib)
find_library(BOOST_SYST NAMES boost_system PATHS ${BOOST_INSTALLATION}/lib)
find_library(THREAD NAMES pthread PATHS /usr/lib)
find_library(SSL NAMES ssl PATHS /usr/lib)
find_library(CRYPTO NAMES crypto PATHS /usr/lib)
find_library(BOOST_FILE_SYST NAMES boost_filesystem PATHS ${BOOST_INSTALLATION}/lib)
find_library(BOOST_TIMER NAMES boost_timer PATHS ${BOOST_INSTALLATION}/lib)
find_library(BOOST_CHRONO NAMES boost_chrono PATHS ${BOOST_INSTALLATION}/lib)
target_link_libraries(${UNITS_TESTS} ${BOOST_TEST} ${BOOST_CHRONO} ${BOOST_FILE_SYST} ${BOOST_SYST} ${BOOST_TIMER} ${THREAD} ${SSL} ${CRYPTO})