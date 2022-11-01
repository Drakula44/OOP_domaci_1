cmake_minimum_required(VERSION 3.8)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB VirtualLib_src
    "include/*.h"
    "src/*.cpp"
)

ADD_LIBRARY(VirtualPianoLib STATIC
    ${VirtualLib_src}
)

target_include_directories(VirtualPianoLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")