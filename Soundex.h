//
// pch.cpp
//

#include "pch.h"
#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <gtest/gtest.h>
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

void initializeSoundex(char* soundex, char firstLetter) {
    soundex[0] = toupper(firstLetter);
    for (int i = 1; i < MAX_CODE_LENGTH; i++) {
        soundex[i] = '0';
    }
    soundex[MAX_CODE_LENGTH] = '\0';
}
void processCharacters(const char* name, char* soundex) {
    int len = strlen(name);
    int sIndex = 1;
    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        addSoundexCode(soundex, &sIndex, code, &soundex[sIndex - 1]);

    }
}
int isNullOrEmpty(const char* str) {
    return str == NULL || str[0] == '\0';
}

int isNumeric(const char* str) {
    return getSoundexCode(str[0])';
}
void handleEmptyOrNumericInput(char* soundex) {
    if (soundex != NULL) {
        soundex[0] = '\0';
    }
}

void generateSoundex(const char* name, char* soundex) {
    if (isNullOrEmpty(name) || isNumeric(name)) {
        handleEmptyOrNumericInput(soundex);
    }
    else{
        initializeSoundex(soundex, name[0]);
        soundex[0] = toupper(name[0]);
        processCharacters(name, soundex);
    }
}

#endif
