cmake_minimum_required (VERSION 3.8)

ADD_LIBRARY( VirtualPianoLib STATIC
             "AudioEditor.cpp" "AudioEditor.h"  "list.h" "list.cpp" "Convertions.h")

target_include_directories(VirtualPianoLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}) 