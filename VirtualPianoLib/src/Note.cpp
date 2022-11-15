#include "Note.h"

Note* Note::getNote(NOTE note, OCTAVE octave) {
    if (notes[octave][note] != nullptr)
        return notes[octave][note];
    return notes[octave][note] = new Note(note, octave);
}

Note* Note::getNote(char c) {
    auto tmp = char2string(c);
    return getNote(string2note(tmp), string2octave(tmp));
}

Note* Note::getNote(string note) {
    return getNote(string2note(C2STR[static_cast<int>(note[0] - '!')]),
                   string2octave(C2STR[static_cast<int>(note[0] - '!')]));
}

Note* Note::shiftOctave(int shift) {
    if (octave + shift < 0 || octave + shift > 4)
        return nullptr;
    return getNote(note, (OCTAVE)(octave + shift));
}

Note* Note::shiftNote(int shift) {
    if (note + shift < 0 || note + shift > 11)
        return nullptr;
    return getNote((NOTE)(note + shift), octave);
}

string Note::char2string(char c) {
    if (c < '!' || c > '{')
        throw "Invalid note";
    auto tmp = C2STR[c - '!'];
    if (tmp == "")
        throw "Invalid note";
    return tmp;
}

void Note::deleteSymbol() { count[octave]--; }

string Note::getSymbol() const {
    return C2STR[static_cast<int>(STR2C[octave][note] - '!')];
};

string Note::getString() const { return string(1, STR2C[octave][note]); };

Note::NOTE Note::string2note(string note) {
    if (note.length() == 2) {
        switch (note[0]) {
        case 'C':
            return C;
        case 'D':
            return D;
        case 'E':
            return E;
        case 'F':
            return F;
        case 'G':
            return G;
        case 'A':
            return A;
        case 'B':
            return B;
        default:
            break;
        }
    }
    if (note.length() == 3) {
        switch (note[0]) {
        case 'C':
            return CS;
        case 'D':
            return DS;
        case 'F':
            return FS;
        case 'G':
            return GS;
        case 'A':
            return AS;
        default:
            throw "INVALID NOTE";
        }
    }
    else
        throw "Invalid note";
}

Note::OCTAVE Note::string2octave(string note) {
    int oct = note[note.length() - 1] - '0';
    if (oct < 2 || oct > 6)
        throw "Invalid note";
    return static_cast<OCTAVE>(oct - 2);
}

char Note::STR2C[5][12] = {
    {'1', '!', '2', '@', '3', '4', '$', '5', '%', '6', '^', '7'},
    {'8', '*', '9', '(', '0', 'q', 'Q', 'w', 'W', 'e', 'E', 'r'},
    {'t', 'T', 'y', 'Y', 'u', 'i', 'I', 'o', 'O', 'p', 'P', 'a'},
    {'s', 'S', 'd', 'D', 'f', 'g', 'G', 'h', 'H', 'j', 'J', 'k'},
    {'l', 'L', 'z', 'Z', 'x', 'c', 'C', 'v', 'V', 'b', 'B', 'n'}};

string Note::C2STR[] = {
    "C#2", "",    "",   "F#2", "G#2", "",    "",    "D#3", "",    "C#3",
    "",    "",    "",   "",    "",    "E3",  "C2",  "D2",  "E2",  "F2",
    "G2",  "A2",  "B2", "C3",  "D3",  "",    "",    "",    "",    "",
    "",    "D#2", "",   "A#6", "F#6", "D#5", "A#3", "",    "F#5", "G#5",
    "F#4", "A#5", "",   "C#6", "",    "",    "G#4", "A#4", "F#3", "",
    "C#5", "C#4", "",   "G#6", "G#3", "",    "D#4", "D#6", "",    "",
    "",    "A#2", "",   "",    "B4",  "A6",  "F6",  "D5",  "A3",  "E5",
    "F5",  "G5",  "F4", "A5",  "B5",  "C6",  "",    "B6",  "G4",  "A4",
    "F3",  "B3",  "C5", "C4",  "E4",  "G6",  "G3",  "E6",  "D4",  "D6"};

Note* Note::notes[5][12] = {};

int Note::count[5] = {};