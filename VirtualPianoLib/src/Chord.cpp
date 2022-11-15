#include "Chord.h"

Chord::Chord(string chord) : MusicSymbol(TYPE::NOTE) {
    for (size_t i = 0; i < chord.size(); i++) {
        if (chord[i] == ' ' || chord[i] == '|' || chord[i] == '[' ||
            chord[i] == ']')
            continue;
        else
            notes.push_back(Note::getNote(chord.substr(i, 1)));
    }
}

MusicSymbol* Chord::deleteSymbol() {
    for (auto note : notes)
        note->deleteSymbol();
    delete this;
    return nullptr;
}

Chord* Chord::shiftOctave(int shift) {
    for (auto& note : notes)
        note = note->shiftOctave(shift);
    return this;
}

string Chord::getString() const {
    string str = "[";
    for (const auto& note : notes)
        str += note->getString();
    return str + "]";
}

string Chord::getAudio() const {
    string str = "[";
    for (const auto& note : notes)
        str += note->getAudio();
    return str + "]";
}