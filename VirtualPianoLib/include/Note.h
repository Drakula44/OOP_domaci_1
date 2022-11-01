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

public:
    static Note* getNote(char c);
    static Note* getNote(NOTE note, OCTAVE octave);
    static Note* getNote(string note);

    Note* shiftOctave(int shift) override;
    Note* shiftNote(int shift);

    static string char2string(char c);
    static NOTE string2note(string note);
    static OCTAVE string2octave(string note);

    string getSymbol() override {
        return C2STR[static_cast<int>(STR2C[octave][note] - '!')];
    };
    string getString() override { return string(1, STR2C[octave][note]); };

private:
    Note(NOTE note, OCTAVE octave)
        : MusicSymbol(MusicSymbol::NOTE), note(note), octave(octave){};
};

#endif