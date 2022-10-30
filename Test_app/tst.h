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

		std::cout << is_defined<AudioEditor>::value << std::endl;
		std::cout << is_defined_method<AudioEditor>::value << std::endl;

		if constexpr (is_defined<AudioEditor>::value && is_defined_method<AudioEditor>::value) {
			std::stringstream input;
			input << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			std::stringstream output;
			output << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

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
			output << "E5E5__F5F5__G5G5__G5G5__E5E5__F5F5__G5G5__G5G5__E5E5__F5F5__G5G5G5G5____E5E5__F5F5__G5G5__G5G5__E5E5__F5F5__G5G5G5G5____G5G5__G5G5__F5F5__F5F5__E5E5E5E5____";

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
			input << "f|g|h|h|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

			AudioEditor editor;
			editor.importAudio(input.str());

			editor.replaceSymbol("f", 5);

			std::stringstream output;
			output << "f|g|hfh|f|g|h|h|f|g|h||f|g|h|h|f|g|h||h|h|g|g|f||";

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