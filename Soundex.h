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

void generateSoundex(const char* name, char* soundex){
    int i, j = 1;
    char lastCode, currentCode;

    soundex[0] = toupper(name[0]);
    lastCode = getSoundexCode(name[0]);

    for (i = 1; name[i] != '\0' && j < 4; i++) {
        currentCode = getSoundexCode(name[i]);
        if (currentCode != 0 && currentCode != lastCode) {
            soundex[j++] = '0' + currentCode;
        }
        lastCode = currentCode;
    }

    while (j < 4) {
        soundex[j++] = '0';
    }
    soundex[j] = '\0';
}
#endif
