#ifndef _chord_h
#define _chord_h

#include "Note.h"
#include "list.h"
#include "std.h"

class Chord : public MusicSymbol {
private:
    list<Note*> notes;

public:
    Chord(list<Note*>);
    Chord(string);

    Chord* shiftOctave(int shift) override;
    MusicSymbol* deleteSymbol() override;
    string getString() const override;
    string getAudio() const override;

    ~Chord() {notes.clear();};
};

#endif