include_directories(../src)
set(SOURCE_FILES main.cpp )
add_executable(unit.x ${SOURCE_FILES})
target_link_libraries(
    unit.x 
    gtest
    gmock
)

