#required cmake version and project name
cmake_minimum_required(VERSION 3.10)
project(KonRoBot)

#definition of MAIN parameter 
set(MAIN src/main.cpp)

#definition of LIBS and SOURCES parameters using wildcards
file(GLOB LIBS lib/*.a)
file(GLOB_RECURSE SOURCES src/*.cpp)

#setting of output directory for KonRoBot binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

#executable command
add_executable(KonRoBot ${MAIN} ${SOURCES})

#include directories
#target_include_directories(KonRoBot PRIVATE src/file_manager/include src/gpio_devices/include src/pin/include src/robot/include)
include_directories(src/file_manager/include src/gpio_devices/include src/pin/include src/robot/include)

#added cpp17 support
target_compile_features(KonRoBot PRIVATE cxx_std_17)

#added wiringPi support
find_library(wiringPi_LIB wiringPi)
target_link_libraries(KonRoBot ${wiringPi_LIB})