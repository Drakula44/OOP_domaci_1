#ifndef PAUSE_H
#define PAUSE_H

# include "MusicSymbol.h"
#include "std.h"

class Pause: public MusicSymbol{
public:
    enum PAUSE {f8,f4,f2};
private:
    PAUSE pause;
public:
    Pause* getPause(string pause);
    Pause* getPause(PAUSE pause);
    PAUSE string2enum(string pause);
    string enum2string(PAUSE pause);
};

#endif