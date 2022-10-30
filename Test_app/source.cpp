#include "AudioEditor.h"
// <- ovde idu include-ovi implementiranih klasa
#include "tst.h"
#include <iostream>
using namespace std;

// forward declare tested types
// class AudioEditor;

int main(int argc, char const* argv[]) {
	using namespace std;
	int pts = 0;
	pts += Test1::tst<AudioEditor>(); 
	pts += Test2::tst<AudioEditor>();
	pts += Test3::tst<AudioEditor>();
	pts += Test4::tst<AudioEditor>();
	pts += Test5::tst<AudioEditor>();
	pts += Test6::tst<AudioEditor>();
	std::cout << "Percentage: " << pts << "%" << std::endl;

	return 0;
}
