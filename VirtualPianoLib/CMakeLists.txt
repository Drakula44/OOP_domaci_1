cmake_minimum_required(VERSION 3.8)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

ADD_LIBRARY(VirtualPianoLib STATIC
    "src/AudioEditor.cpp" "src/list.cpp" "src/Note.cpp"
    "include/AudioEditor.h" "include/list.h" "include/Note.h"
    "include/Acord.h" "include/MusicSymbol.h" "include/Pause.h" "include/Convertions.h"
    "include/std.h")

target_include_directories(VirtualPianoLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")