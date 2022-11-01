#ifndef _pause_h
#define _pause_h

#include "MusicSymbol.h"
#include "std.h"

class Pause : public MusicSymbol {
public:
    enum PAUSE { f8, f4, f2 };

private:
    PAUSE pause;
    static Pause* pauses[3];
    Pause(PAUSE pause, MusicSymbol::TYPE type)
        : MusicSymbol(type), pause(pause){};

public:
    static Pause* getPause(string pause);
    static Pause* getPause(PAUSE pause);
    static PAUSE string2enum(string pause);
    static string enum2string(PAUSE pause);

    string getString() override { return enum2string(pause); };
    string getSymbol() override;
    Pause* shiftOctave(int shift) override {
        (void)(shift);
        return this;
    };
};

#endif