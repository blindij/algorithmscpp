cmake_minimum_required(VERSION 3.7)
project(algorithms)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
if (DEFINED ENV{HOME})
   set( HOME $ENV{HOME}) 
endif()
#set(GMOCK_HOME "${HOME}/local/googletest")
#message("GMOCK_HOME: ${GMOCK_HOME}")

#include_directories(${GMOCK_HOME}/include)
#include_directories(${CMAKE_SOURCE_DIR})

#link_directories(${GMOCK_HOME}/lib)
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

if(ENABLE_UNIT_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.8.0
  )
  FetchContent_GetProperties(googletest)
  if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    # add the targets: gtest, gtest_main, gmock, gmock_main
    add_subdirectory(
      ${googletest_SOURCE_DIR}
      ${googletest_BINARY_DIR}
    )
  endif()
endif()

include_directories(src)
add_subdirectory(test)


enable_testing()

add_test(
 NAME unit.x
 COMMAND $<TARGET_FILE:unit.x>
)
