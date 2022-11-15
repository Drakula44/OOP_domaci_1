#ifndef _music_symbol_h_
#define _music_symbol_h_

#include "std.h"
class MusicSymbol {
public:
    enum TYPE { NOTE = 1, PAUSE8 = 1, PAUSE4 = 2, PAUSE2 = 4 };

protected:
    TYPE type;
    MusicSymbol(TYPE type) : type(type){};

public:
    virtual string getString() const = 0;
    virtual string getSymbol() const = 0;
    virtual MusicSymbol* shiftOctave(int step) = 0;
    virtual void deleteSymbol() = 0;
    virtual TYPE checkType() const { return type; };
    virtual ~MusicSymbol(){};
};

#endif