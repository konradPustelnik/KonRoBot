#required cmake version and project name
cmake_minimum_required(VERSION 3.10)
project(KonRoBot)

#definition of MAIN parameter
set(MAIN src/main.cpp)

#definition of LIBS and TEST_SOURCES parameters using wildcards
#file(GLOB LIBS lib/*.a)
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

#set of output directory for KonRoBot binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

#include libraries
include_directories(robot pin gpiodevices file)
link_directories(robot pin gpiodevices file)

#add subdirectories
add_subdirectory(src/robot)
add_subdirectory(src/pin)
add_subdirectory(src/gpio_devices)
add_subdirectory(src/file_manager)

#executable command
add_executable(KonRoBot ${MAIN})

#include headers
#target_include_directories(KonRoBot PRIVATE src/file_manager/include src/gpio_devices/include src/pin/include src/robot/include)
include_directories(src/file_manager/include src/gpio_devices/include src/pin/include src/robot/include)

#add static library
target_link_libraries(KonRoBot robot pin gpiodevices file)

#add cpp17 support
target_compile_features(KonRoBot PRIVATE cxx_std_17)

#add wiringPi support
find_library(wiringPi_LIB wiringPi)
target_link_libraries(KonRoBot ${wiringPi_LIB})

#add additional flags
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror -Wshadow -pedantic")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

### KonRoBotTests ###
#include GTest and file.cpp
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} "src/file_manager/src/")

#executable command
add_executable(KonRoBotTests ${TEST_SOURCES})

#link KonRoBotTests with what we want to test and the GTest and pthread library
target_link_libraries(KonRoBotTests ${GTEST_LIBRARIES} pthread)
set_property(TARGET KonRoBotTests PROPERTY CXX_STANDARD 17)
