#include "../include/Chord.h"

Chord::Chord(string chord) : MusicSymbol(NOTE) {
    for (size_t i = 0; i < chord.size(); i++) {
        if (chord[i] == ' ')
            continue;
        else
            notes.push_back(Note::getNote(chord.substr(i, 1)));
    }
}

Chord* Chord::shiftNote(int shift) {
    for (auto& note : notes)
        note = note->shiftNote(shift);
    return this;
}
Chord* Chord::shiftOctave(int shift) {
    for (auto& note : notes)
        note = note->shiftOctave(shift);
    return this;
}

string Chord::getString() {
    string str = "[";
    for (auto& note : notes)
        str += note->getString() + " ";
    return str + "]";
}
string Chord::getSymbol() {
    string str = "[";
    for (auto& note : notes)
        str += note->getSymbol() + " ";
    return str + "]";
}