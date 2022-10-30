# CMakeList.txt : CMake project for Test_app, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED True)
set (CMAKE_CXX_EXTENSIONS True)
# Add source to this project's executable.
add_executable (Test_app "tst.h" "source.cpp")

TARGET_LINK_LIBRARIES(Test_app VirtualPianoLib)