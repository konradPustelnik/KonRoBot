#required cmake version and project name
cmake_minimum_required(VERSION 3.10)
project(runTests)

#included file.h and file.cpp
include_directories("../src/file_manager/include/" "../src/file_manager/src/")

#included GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
#linked runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp ${SOURCES})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

#added cpp17 support
set_property(TARGET runTests PROPERTY CXX_STANDARD 17)
