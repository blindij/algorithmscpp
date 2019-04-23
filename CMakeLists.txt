cmake_minimum_required(VERSION 3.7)
project(algorithms)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
if (DEFINED ENV{HOME})
   set( HOME $ENV{HOME}) 
endif()
set(GMOCK_HOME "${HOME}/local/googletest")
message("GMOCK_HOME: ${GMOCK_HOME}")

include_directories(${GMOCK_HOME}/include)
include_directories(${CMAKE_SOURCE_DIR})

link_directories(${GMOCK_HOME}/lib)
include_directories(src)
add_subdirectory(test)
