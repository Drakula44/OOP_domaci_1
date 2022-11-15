#ifndef _chord_h
#define _chord_h

#include "Note.h"
#include "list.h"

class Chord : public MusicSymbol {
private:
    list<Note*> notes;

public:
    Chord(list<Note*>);
    Chord(string);

    Chord* shiftNote(int shift);
    Chord* shiftOctave(int shift) override;
    void deleteSymbol() override;
    string getString() const override;
    string getSymbol() const override;
};

#endif