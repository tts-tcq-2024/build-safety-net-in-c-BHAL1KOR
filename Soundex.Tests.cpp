#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA 
  char soundex[MAX_CODE_LENGTH+1];

    generateSoundex("Robert", soundex);
    assert(strcmp(soundex, "R163") == 0);

    generateSoundex("Rupert", soundex);
    assert(strcmp(soundex, "R163") == 0);

    generateSoundex("Rubin", soundex);
    assert(strcmp(soundex, "R150") == 0);

    generateSoundex("Ashcraft", soundex);
    assert(strcmp(soundex, "A261") == 0);

    generateSoundex("Tymczak", soundex);
    assert(strcmp(soundex, "T522") == 0);

    generateSoundex("Pfister", soundex);
    assert(strcmp(soundex, "P236") == 0);

    generateSoundex("AX", soundex);
    assert(strcmp(soundex, "A200") == 0);

    generateSoundex("", soundex);
    assert(strcmp(soundex, "") == 0);

    generateSoundex(NULL, soundex);
    assert(strcmp(soundex, "") == 0);
}
