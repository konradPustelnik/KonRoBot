#required cmake version and project name
cmake_minimum_required(VERSION 3.10)

#definition of SOURCES parameter using wildcards
file(GLOB_RECURSE SOURCES src/*.cpp)

#create robot static library
add_library(robot STATIC ${SOURCES})

#include header
#target_include_directories(robot PUBLIC include ../file_manager/include ../pin/include ../gpio_devices/include)
include_directories(include ../file_manager/include ../pin/include ../gpio_devices/include)

#add cpp17 support
target_compile_features(robot PRIVATE cxx_std_17)
