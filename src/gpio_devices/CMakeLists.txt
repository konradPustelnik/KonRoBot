#required cmake version and project name
cmake_minimum_required(VERSION 3.10)

#definition of SOURCES parameter using wildcards
file(GLOB_RECURSE SOURCES src/*.cpp)

#create gpiodevices static library
add_library(gpiodevices STATIC ${SOURCES})

#include header
#target_include_directories(gpiodevices PUBLIC include ../pin/include)
include_directories(include ../pin/include)

#add cpp17 support
target_compile_features(gpiodevices PRIVATE cxx_std_17)
