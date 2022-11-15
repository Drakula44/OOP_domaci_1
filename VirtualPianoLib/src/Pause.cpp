#include "Pause.h"

Pause* Pause::pauses[3] = {0};

Pause* Pause::getPause(string pause) { return getPause(string2enum(pause)); }

Pause* Pause::getPause(PAUSE pause) {
    TYPE type;
    if (pauses[static_cast<int>(pause)])
        return pauses[static_cast<int>(pause)];
    switch (pause) {
    case PAUSE::f8:
        type = TYPE::PAUSE8;
        break;
    case PAUSE::f4:
        type = TYPE::PAUSE4;
        break;
    case PAUSE::f2:
        type = TYPE::PAUSE2;
        break;
    }
    return pauses[static_cast<int>(pause)] = new Pause(pause, type);
}

Pause::PAUSE Pause::string2enum(string pause) {
    if (pause == " ")
        return PAUSE::f8;
    else if (pause == "|")
        return PAUSE::f4;
    else if (pause == "||")
        return PAUSE::f2;
    throw "Invalid pause";
}

string Pause::enum2string(PAUSE pause) {
    switch (pause) {
    case PAUSE::f8:
        return " ";
    case PAUSE::f4:
        return "|";
    case PAUSE::f2:
        return "||";
    }
    throw "Invalid pause";
}

string Pause::getString() const {
    switch (pause) {
    case PAUSE::f4:
        return "__";
    case PAUSE::f2:
        return "____";
    default:
        return "_";
    }
}

string Pause::getAudio() const { 
    return enum2string(pause); 
}

void Pause::deleteSingletons() {
    for (int i = 0; i < 3; i++) {
        if (pauses[i]) {
            delete pauses[i];
            pauses[i] = nullptr;
        }
    }
}

Pause* Pause::shiftOctave(int shift) {
    (void)(shift);
    return this;
};