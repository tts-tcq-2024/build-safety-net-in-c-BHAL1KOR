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

void generateSoundex(const char *name, char *soundex) {
    if (name == NULL || soundex == NULL) {
        return;
    }

    int len = strlen(name);
    if (len == 0) {
        soundex[0] = '\0';
        return;
    }

    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    char lastCode = getSoundexCode(soundex[0]);

    for (int i = 1; i < len && sIndex < MAX_CODE_LENGTH; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != lastCode) {
            soundex[sIndex++] = code;
            lastCode = code;
        }
    }

    while (sIndex < MAX_CODE_LENGTH) {
        soundex[sIndex++] = '0';
    }

    soundex[MAX_CODE_LENGTH] = '\0';
}
#endif
