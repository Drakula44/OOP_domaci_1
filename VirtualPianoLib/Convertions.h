#include <string>
using std::string;

enum NOTE = { C, C#, D, D#, E, F, F#, G, G#, A, A#, B };
enum OCTAVE = { 2, 3, 4, 5, 6 };

int STR2C[5][12] = {{'1', '!', '2', '@', '3', '4', '$', '5', '%', '6', '^', '7'},
					{'8', '*', '9', '(', '0', 'q', 'Q', 'w', 'W', 'e', 'E', 'r'},
					{'t', 'T', 'y', 'Y', 'u', 'i', 'I', 'o', 'O', 'p', 'P', 'a'},
					{'s', 'S', 'd', 'D', 'f', 'g', 'G', 'h', 'H', 'j', 'J', 'k'},
					{'l', 'L', 'z', 'Z', 'x', 'c', 'C', 'v', 'V', 'b', 'B', 'n'} };

string C2STR[] = {"C#2", "", "", "F#2", "G#2", "", "", "D#3", "", "C#3", "", "", "", "", "", "E3", "C2", "D2", "E2", "F2", "G2", "A2", "B2", "C3", "D3", "", "", "", "", "", "", "D#2", "", "A#6", "F#6", "D#5", "A#3", "", "F#5", "G#5", "F#4", "A#5", "", "C#6", "", "", "G#4", "A#4", "F#3", "", "C#5", "C#4", "", "G#6", "G#3", "", "D#4", "D#6", "", "", "", "A#2", "", "", "B4", "A6", "F6", "D5", "A3", "E5", "F5", "G5", "F4", "A5", "B5", "C6", "", "B6", "G4", "A4", "F3", "B3", "C5", "C4", "E4", "G6", "G3", "E6", "D4", "D6"}

char getCharacterFromNote(NOTE note, OCTAVE octave)
{
	return STR2C[octave][note]
}

string getNoteFromCharacter(char c)
{
	return C2STR[c - '!'];
}
