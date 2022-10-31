cmake_minimum_required (VERSION 3.8)

ADD_LIBRARY( VirtualPianoLib STATIC
             "AudioEditor.cpp" "AudioEditor.h"  "list.h"  "Convertions.h" "list.cpp" "MusicSymbol.h" "enums.h")

target_include_directories(VirtualPianoLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}) 