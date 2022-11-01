#include "../include/AudioEditor.h"

int AudioEditor::importAudio(string audio) {
    bool chord = false;
    int start_chord = 0;
    //MusicSymbol* test = nullptr;
    //cout << static_cast<void*>(test) << " ";

    //test = Note::getNote(Note::A, Note::_2);
    //cout << static_cast<void*>(test) << " ";
    //cout << test->getString() << endl;

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
                cout << "Error in chord" << endl;
            }
        }
        else if (chord)
            continue;
        else if (audio[i] == ' ')
            try {
                music.push_back(Pause::getPause(" "));
            } catch (...) {
                cout << "Error in pause" << endl;
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
                cout << "Error in pause" << endl;
            }
        }
        else
            try {
                music.push_back(Note::getNote(audio.substr(i, 1)));
            } catch (...) {
                cout << "Error in note" << endl;
            }
    }
    return -1;
}

string AudioEditor::exportAudio() {
    string audio = "";
    for (auto symbol : music) {
        audio += symbol->getString();
    }
    return audio;
}

// improve this
string AudioEditor::exportNotes() {
    string audio = "";
    int count = 0;
    for (auto it = music.begin(); it != music.end();++it) {
        auto sym = (*it)->getSymbol();
        ++it;
        int rep = 1;
        if (it != music.end())
            rep = (*it)->checkType();
            
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
        count += (*it)->checkType()-1;
        --it;

    }
    return audio;
};

void AudioEditor::insertSymbol(string symbol, int position) {
    if (position < 0 || position > music.size())
        throw "Invalid position";
    auto it = music.begin();
    for (int i = 0; i < position; i++)
        ++it;
    if (symbol == " " || symbol == "|" || symbol == "||")
        music.insert(it, Pause::getPause(symbol));
    else if (symbol[0] == '[')
        music.insert(it, new Chord(symbol));
    else
        music.insert(it, Note::getNote(symbol));
}
void AudioEditor::deleteSymbol(int position) {
    auto it = music.begin();
    for (int i = 0; i < position; i++)
        ++it;
    music.erase(it);
}
void AudioEditor::replaceSymbol(string symbol, int position) {
    auto it = music.begin();
    for (int i = 0; i < position; i++)
        ++it;
    MusicSymbol* tmp;
    if (symbol == " " || symbol == "|" || symbol == "||")
        tmp = Pause::getPause(symbol);
    else if (symbol[0] == '[')
        tmp = new Chord(symbol);
    else
        tmp = Note::getNote(symbol);
    *it = tmp;
}
void AudioEditor::changeOctave(int step) {
    for (auto& symbol : music)
        symbol = symbol->shiftOctave(step);
}
