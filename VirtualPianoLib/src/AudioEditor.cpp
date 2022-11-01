#include "../include/AudioEditor.h"

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
            std::cerr << "Error" << '\n';
        }

        cout << audio[i] << " _ " << i << endl;
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
            cout << endl << audio.size() << " " << i + 1 << endl;
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
        cout << "testtt" << endl;
        cout << symbol->checkType() << endl;
        audio += symbol->getString();
    }
    return audio;
}
string AudioEditor::exportNotes() { return ""; };

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
