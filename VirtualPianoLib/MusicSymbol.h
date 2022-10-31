#pragma once
#include "enums.h"
class MusicSymbol
{

};

class Note : public MusicSymbol
{
private:
	NOTE note;
	OCTAVE oct;

	void string2enums(string note)
	{

	}

};

// creirati singletone za 

class Pause : public MusicSymbol
{
private:
	PAUSE pause;
};

class Acord : public Note
{
private:
	list<Note> notes;
};