#ifndef _pause_h
#define _pause_h

#include "MusicSymbol.h"
#include "std.h"

class Pause : public MusicSymbol {
public:
    enum class PAUSE{ f8, f4, f2 };

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
    static void deleteSingletons();

    MusicSymbol* deleteSymbol() override { return nullptr; };
    string getString() const override;
    string getAudio() const override;
    Pause* shiftOctave(int shift);
};

#endif