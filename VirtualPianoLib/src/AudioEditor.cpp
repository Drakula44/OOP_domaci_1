#include "AudioEditor.h"

int AudioEditor::importAudio(string audio) {
    bool chord = false;
    int start_chord = 0;
    for (size_t i = 0; i < audio.size(); i++) {
        try {
            if (!chord && audio[i] == ']')
                throw "Invalid input";
            if (chord && audio[i] == '[')
                throw "Invalid input";
        } catch (...) {
            cout << "Error" << '\n';
        }

        if (audio[i] == '[')
            chord = true, start_chord = i;
        else if (chord && audio[i] == ']') {
            chord = false;
            try {
                music.push_back(
                    new Chord(audio.substr(start_chord, i - start_chord + 1)));
            } catch (...) {
                cout << "Error parsing chord" << endl;
            }
        }
        else if (chord)
            continue;
        else if (audio[i] == ' ')
            try {
                music.push_back(Pause::getPause(" "));
            } catch (...) {
                cout << "Error parsing pause" << endl;
            }
        else if (audio[i] == '|') {
            try {
                if (i + 1 < audio.size() && audio[i + 1] == '|') {
                    music.push_back(Pause::getPause("||"));
                    i++;
                }
                else
                    music.push_back(Pause::getPause("|"));
            } catch (...) {
                cout << "Error parsing pause" << endl;
            }
        }
        else
            try {
                music.push_back(Note::getNote(audio.substr(i, 1)));
            } catch (...) {
                cout << "Error parsing note" << endl;
            }
    }
    return -1;
}

string AudioEditor::exportAudio() {
    string audio = "";
    for (auto symbol : music) {
        audio += symbol->getAudio();
    }
    return audio;
}

string AudioEditor::exportNotes() {
    string audio = "";
    int count = 0;
    for (auto it = music.begin(); it != music.end(); ++it) {
        auto sym = (*it)->getString();
        ++it;
        int rep = 1;
        if (it != music.end())
            rep = static_cast<int>((*it)->checkType());
        else {
            audio += sym;
            break;
        }

        for (; rep > 0; rep--) {
            audio += sym;
            count++;
            if (count == 8) {
                count = 0;
                audio += "\n";
            }
        }
        count += static_cast<int>((*it)->checkType()) - 1;
        --it;
    }
    return audio;
};

void AudioEditor::insertSymbol(string symbol, int position) {
    try {
        if (position < 0 || position > music.size())
            throw "Invalid position";
    } catch (...) {
        cout << "Invalid position";
        return;
    }
    auto it = music.begin();
    for (int i = 0; i < position; i++)
        ++it;
    try{
        if (symbol == " " || symbol == "|" || symbol == "||")
            music.insert(it, Pause::getPause(symbol));
        else if (symbol[0] == '[')
            music.insert(it, new Chord(symbol));
        else
            music.insert(it, Note::getNote(symbol));
    }
    catch (...) {
        cout << "Invalid position";
        return;
    }
}
void AudioEditor::deleteSymbol(int position) {
    try {
        if (position < 0 || position > music.size())
            throw "Invalid position";
    } catch (...) {
        cout << "Invalid position";
        return;
    }
    auto it = music.begin();
    for (int i = 0; i < position; i++)
        ++it;
    *it = (*it)->deleteSymbol();
    music.erase(it);
}
void AudioEditor::replaceSymbol(string symbol, int position) {
    try {
        if (position < 0 || position > music.size())
            throw "Invalid position";
    } catch (...) {
        cout << "Invalid position";
        return;
    }
    auto it = music.begin();
    for (int i = 0; i < position; i++)
        ++it;
    MusicSymbol* tmp;
    try {
        if (symbol == " " || symbol == "|" || symbol == "||")
            tmp = Pause::getPause(symbol);
        else if (symbol[0] == '[')
            tmp = new Chord(symbol);
        else
            tmp = Note::getNote(symbol);
    } catch (...) {
        cout << "Error parsing symbol to be replaced";
        return;
    }
    *it = (*it)->deleteSymbol();
    *it = tmp;
}
void AudioEditor::changeOctave(int step) {
    if (step > 0) {
        for (int i = 5 - step; i < 5; i++) {
            if (Note::checkOctaveCount(i) > 0) {
                cout << "Octave shift out of range";
                return;
            }
        }
    }
    else {
        for (int i = 0; i < -step; i++)
            if (Note::checkOctaveCount(i) > 0) {
                cout << "Octave shift out of range";
                return;
            }
    }

    for (auto& symbol : music)
        symbol = symbol->shiftOctave(step);
}

AudioEditor::~AudioEditor() {
    while (music.size() != 0) {
        deleteSymbol(0);
    }
    Note::deleteSingletons();
    Pause::deleteSingletons();
}