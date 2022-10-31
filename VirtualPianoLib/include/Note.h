#ifndef NOTE_H
#define NOTE_H

#include "MusicSymbol.h"
#include "std.h"

class Note : public MusicSymbol {
public:
  enum NOTE { C, CS, D, DS, E, F, FS, G, GS, A, AS, B };
  enum OCTAVE { _2, _3, _4, _5, _6 };

private:
  NOTE note;
  OCTAVE octave;

public:
  static Note *getNode(char c);
  static Note *getNode(NOTE note, OCTAVE octave);
  static Note *getNode(string note);

  Note *shiftOctave(int shift);
  Note *shiftNote(int shift);

  string char2string(char c);
  Note *string2note(string note);
  string note2string();

private:
  Note(NOTE note, OCTAVE octave);
};

#endif