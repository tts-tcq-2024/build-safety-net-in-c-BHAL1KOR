#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

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

void addSoundexCode(char* soundex, int* sIndex, char code, char* lastCode) {
    if (code != '0' && code != *lastCode) {
        soundex[(*sIndex)++] = code;
    }
}

void generateSoundex(const char* name, char* soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        addSoundexCode(soundex, &sIndex, code, &soundex[sIndex - 1]);
       
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
    printf(" soundex= %s \r\n", soundex);
}

#endif
