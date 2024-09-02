#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

#define MAX_CODE_LENGTH 4

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };

    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return soundexTable[c - 'A'];
    }
    return '0'; // For non-alphabetic characters
}

void initializeSoundex(char *soundex, char firstLetter) {
    soundex[0] = toupper(firstLetter);
    for (int i = 1; i < MAX_CODE_LENGTH; i++) {
        soundex[i] = '0';
    }
    soundex[MAX_CODE_LENGTH] = '\0';
}

void processCharacters(const char *name, char *soundex) {
    int sIndex = 1;
    char lastCode = getSoundexCode(soundex[0]);

    for (int i = 1; name[i] != '\0' && sIndex < MAX_CODE_LENGTH; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != lastCode) {
            soundex[sIndex++] = code;
            lastCode = code;
        }
    }
}

void generateSoundex(const char *name, char *soundex) {
    if (name == NULL || soundex == NULL || name[0] == '\0') {
        if (soundex != NULL) {
            soundex[0] = '\0';
        }
        return;
    }

    initializeSoundex(soundex, name[0]);
    processCharacters(name, soundex);
}
#endif
