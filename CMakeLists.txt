# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS on)

if(MSVC)
  # warninglevel 4 and all warnings as errors
  add_compile_options(/W4)
else()
  # lotsof warnings and all warnings as errors
  # set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
  # add_compile_options(-std=c++20 -g -O0 -Wall -Wextra -pedantic -Werror -fmodules-ts)
endif()

project("OOP_domaci_1")

# Include sub-projects.
add_subdirectory("VirtualPianoLib")
add_subdirectory("Test_app")

add_custom_command(
  OUTPUT test.lic
  COMMAND Test_app
  COMMENT "Testing....."
  VERBATIM
)

add_custom_target(
  Testingggg ALL
  DEPENDS test.lic
)