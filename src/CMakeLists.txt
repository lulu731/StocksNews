FILE(GLOB OBJSRCS "*.cpp" "*.hpp")
include_directories(../../boost/installation/include)
add_library(objsrcs OBJECT ${OBJSRCS})
add_definitions(-std=c++11 -Wall -Wextra)