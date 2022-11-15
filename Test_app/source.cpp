#include "../VirtualPianoLib/include/AudioEditor.h"
// <- ovde idu include-ovi implementiranih klasa
#include "tst.h"
#include <iostream>
using namespace std;
// forward declare tested types
// class AudioEditor;
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    using namespace std;

    int pts = 0;
    pts += Test1::tst<AudioEditor>();
    pts += Test2::tst<AudioEditor>();
    pts += Test3::tst<AudioEditor>();
    pts += Test4::tst<AudioEditor>();
    pts += Test5::tst<AudioEditor>();
    pts += Test6::tst<AudioEditor>();
    pts += Test7::tst<AudioEditor>();
    pts += Test8::tst<AudioEditor>();
    pts += Test9::tst<AudioEditor>();
    pts += Test10::tst<AudioEditor>();
    pts += Test11::tst<AudioEditor>();
    pts += Test12::tst<AudioEditor>();
    pts += Test13::tst<AudioEditor>();
    pts += Test14::tst<AudioEditor>();
    std::cout << "Percentage: " << pts << "%" << std::endl;

    return 0;
}
