#ifndef ACORD_H
#define ACORD_H


#include "Note.h"
#include "list.h"
class Acord: public Note{
private:
    list<Note> notes;
public:
    Acord(Note);
    Acord(list<Note>);
    Acord();

    Acord* shiftNote(int shift);
    Acord* shiftOctave(int shift);
    
};

#endif