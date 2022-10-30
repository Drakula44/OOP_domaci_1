# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED on)
set (CMAKE_CXX_EXTENSIONS on)
project ("OOP_domaci_1")

# Include sub-projects.
add_subdirectory ("VirtualPianoLib")
add_subdirectory ("Test_app")