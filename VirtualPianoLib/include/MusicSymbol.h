#ifndef _music_symbol_h_
#define _music_symbol_h_

#include "std.h"
class MusicSymbol {
public:
    enum TYPE { NOTE =1, PAUSE8=1, PAUSE4=2, PAUSE2=4 };

protected:
    TYPE type;
    MusicSymbol(TYPE type) : type(type){};

public:
    virtual string getString() = 0;
    virtual string getSymbol() = 0;
    virtual MusicSymbol* shiftOctave(int step) = 0;
    virtual TYPE checkType() { return type; };

    virtual ~MusicSymbol(){};

    // friend ostream& operator<<(ostream& os, MusicSymbol& ms);
};

#endif