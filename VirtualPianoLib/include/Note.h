#ifndef _note_h
#define _note_h

#include "MusicSymbol.h"
#include "std.h"

class Note : public MusicSymbol {
public:
    enum NOTE { C, CS, D, DS, E, F, FS, G, GS, A, AS, B };
    enum OCTAVE { o2, o3, o4, o5, o6 };

private:
    NOTE note;
    OCTAVE octave;
    static Note* notes[5][12];
    static char STR2C[5][12];
    static string C2STR[];
    static int count[5];

public:
    static Note* getNote(char c);
    static Note* getNote(NOTE note, OCTAVE octave);
    static Note* getNote(string note);

    static int checkOctaveCount(int octave) { return count[octave]; }

    MusicSymbol* deleteSymbol() override;
    Note* shiftOctave(int shift) override;

    static string char2string(char c);
    static NOTE string2note(string note);
    static OCTAVE string2octave(string note);

    string getAudio() const override;
    string getString() const override;
    
    static void deleteSingletons();

private:
    Note(NOTE note, OCTAVE octave)
        : MusicSymbol(TYPE::NOTE), note(note), octave(octave){};
};

#endif