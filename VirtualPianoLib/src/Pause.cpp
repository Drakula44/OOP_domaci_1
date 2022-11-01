#include "../include/Pause.h"

Pause* Pause::pauses[3] = {0};

Pause* Pause::getPause(string pause) { return getPause(string2enum(pause)); }

Pause* Pause::getPause(PAUSE pause) {
    MusicSymbol::TYPE type;
    if (pauses[pause])
        return pauses[pause];
    switch (pause) {
    case f8:
        type = MusicSymbol::PAUSE8;
        break;
    case f4:
        type = MusicSymbol::PAUSE4;
        break;
    case f2:
        type = MusicSymbol::PAUSE2;
        break;
    }
    return pauses[pause] = new Pause(pause, type);
}

Pause::PAUSE Pause::string2enum(string pause) {
    if (pause == " ")
        return f8;
    else if (pause == "|")
        return f4;
    else if (pause == "||")
        return f2;
    throw "Invalid pause";
}

string Pause::enum2string(PAUSE pause) {
    switch (pause) {
    case f8:
        return " ";
    case f4:
        return "|";
    case f2:
        return "||";
    }
    throw "Invalid pause";
}