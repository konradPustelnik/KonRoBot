#required cmake version and project name
cmake_minimum_required(VERSION 3.10)

#definition of SOURCES parameter using wildcards
file(GLOB_RECURSE SOURCES src/*.cpp)

#create pin static library
add_library(pin STATIC ${SOURCES})

#include header
#target_include_directories(pin PUBLIC include ../file_manager/include)
include_directories(include ../file_manager/include)

#add cpp17 support
target_compile_features(pin PRIVATE cxx_std_17)
