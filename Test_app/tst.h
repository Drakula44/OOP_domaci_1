#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
using namespace std;

// check if type is defined, forward declarations are not definitions
template <class, class = void>
struct is_defined : std::false_type {};
template <class T>
struct is_defined<
	T, std::enable_if_t<std::is_object<T>::value &&
	!std::is_pointer<T>::value && (sizeof(T) > 0)>>
	: std::true_type {};


namespace Test1 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h|h|f|g|h|[hh]|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			std::stringstream output;
			output << "f|g|h|h|f|g|h|[hh]|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 20;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}


namespace Test2 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportNotes()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			std::stringstream output;
			output << "E5E5__F5F5__\nG5G5__G5G5__\nE5E5__F5F5__\nG5G5__G5G5__\nE5E5__F5F5__\nG5G5G5G5____\nE5E5__F5F5__\nG5G5__G5G5__\nE5E5__F5F5__\nG5G5G5G5____\nG5G5__G5G5__\nF5F5__F5F5__\nE5E5E5E5____";

			std::cout << editor.exportNotes() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportNotes()) {
				std::cout << "Test passed" << std::endl;
				return 10;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}


namespace Test3 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().insertSymbol(std::declval<string>(), std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.insertSymbol("f", 5);

			std::stringstream output;
			output << "f|g|hf|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 10;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}


namespace Test4 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().deleteSymbol(std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.deleteSymbol(5);

			std::stringstream output;
			output << "f|g|hh|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 10;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return -30;
	}
}


namespace Test5 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().replaceSymbol(std::declval<string>(), std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h[hfg]|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.replaceSymbol("f", 5);

			std::stringstream output;
			output << "f|g|hf|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 15;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}


namespace Test6 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().changeOctave(std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.changeOctave(1);

			std::stringstream output;
			output << "x|c|v|v|x|c|v|v|x|c|v||x|c|v|v|x|c|v||v|v|c|c|x||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 15;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}

namespace Test7 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().insertSymbol(std::declval<string>(), std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "[fg]|[gg]|gg";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.insertSymbol("[fg]", 1);

			std::stringstream output;
			output << "[fg][fg]|[gg]|gg";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 15;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}

namespace Test8 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().deleteSymbol(std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|gh[gh]h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.deleteSymbol(5);

			std::stringstream output;
			output << "f|g|g[gh]h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 15;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}

namespace Test9 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().changeOctave(std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "1|f|g|h|h|f|g|[hhfk]|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.changeOctave(1);

			std::stringstream output;
			output << "8|x|c|v|v|x|c|[vvxn]|c|v||x|c|v|v|x|c|v||v|v|c|c|x||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 69;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}

namespace Test10 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().changeOctave(std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "1|f|g|h|h|f|g|[hhfk]|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.changeOctave(2);

			std::stringstream output;
			output << "1|f|g|h|h|f|g|[hhfk]|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 21;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}

}

namespace Test11 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().replaceSymbol(std::declval<string>(), std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.replaceSymbol("1", 6);
			editor.changeOctave(-1);

			std::stringstream output;
			output << "f|g|h|1|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";
                        std::cout << "Test11" << std::endl;
			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 100;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}


namespace Test12 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().replaceSymbol(std::declval<string>(), std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "1|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.deleteSymbol(5);
			//editor.changeOctave(-1);

			std::stringstream output;
			output << "1|g|hh|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 100;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}

namespace Test13 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().replaceSymbol(std::declval<string>(), std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h[hfg]|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.replaceSymbol("1", 5);
			editor.changeOctave(-1);

			std::stringstream output;
			output << "f|g|h1|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 15;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}

namespace Test14 { // provera za '|' na pocetku u string

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "|f|g|h|h|f|g|h|[hh]|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			std::stringstream output;
			output << "|f|g|h|h|f|g|h|[hh]|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 20;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}

namespace Test15 { // provera za '|' na pocetku u note

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "|f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			std::stringstream output;
			output << "__E5E5__F5F5\n__G5G5__G5G5\n__E5E5__F5F5\n__G5G5__G5G5\n__E5E5__F5F5\n__G5G5G5G5__\n__E5E5__F5F5\n__G5G5__G5G5\n__E5E5__F5F5\n__G5G5G5G5__\n__G5G5__G5G5\n__F5F5__F5F5\n__E5E5E5E5__\n__";

			std::cout << editor.exportNotes() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportNotes()) {
				std::cout << "Test passed" << std::endl;
				return 20;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}

namespace Test16 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().insertSymbol(std::declval<string>(), std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.insertSymbol("||", 0);

			std::stringstream output;
			output << "||f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 10;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}

namespace Test17 {

	template <class, class = void>
	struct is_defined_method : std::false_type {};

	template <class AudioEditor>
	struct is_defined_method<
		AudioEditor,
		std::enable_if_t<
		std::is_same<decltype(AudioEditor()), AudioEditor>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().importAudio(std::declval<string>())), int>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().insertSymbol(std::declval<string>(), std::declval<int>())), void>::value&&
		std::is_same<decltype(std::declval<AudioEditor>().exportAudio()), string>::value
		>
	> : std::true_type {};

	template <class AudioEditor>
	int tst() {
		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.insertSymbol("|", 1);

			std::stringstream output;
			output << "f|g||h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			std::cout << editor.exportAudio() << std::endl;
			std::cout << "-------------------------------------" << endl;
			std::cout << output.str() << std::endl;

			if (output.str() == editor.exportAudio()) {
				std::cout << "Test passed" << std::endl;
				return 10;
			}
			else {
				std::cout << "Test failed" << std::endl;
			}
		}
		else {
			std::cout << "Interface failed" << std::endl;
		}
		return 0;
	}
}