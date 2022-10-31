#include <string>

using std::string;

class AudioEditor {
private:
	string data;
public:
	int importAudio(string audio);
	string exportAudio() { return data; };
	string exportNotes() { return data; };

	void insertSymbol(string symbol, int position) {};
	void deleteSymbol(int position) {};
	void replaceSymbol(string symbol, int position) {};
	void changeOctave(int step) {};
};