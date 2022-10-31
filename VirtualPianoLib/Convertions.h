#pragma once
#include "enums.h"



string getNoteFromCharacter(char c)
{
	return C2STR[c - '!'];
}

char getCharacterFromNote(NOTE note, OCTAVE octave)
{
	return STR2C[octave][note]
}



