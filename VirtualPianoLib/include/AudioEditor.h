#ifndef _audio_editor_h
#define _audio_editor_h

#include "Chord.h"
#include "MusicSymbol.h"
#include "Note.h"
#include "Pause.h"
#include "list.h"

#include "std.h"

class AudioEditor {
private:
    string data;
    list<MusicSymbol*> music;

public:
    int importAudio(string audio);
    string exportAudio();
    string exportNotes();

    void insertSymbol(string symbol, int position);
    void deleteSymbol(int position);
    void replaceSymbol(string symbol, int position);
    void changeOctave(int step);
};

#endif