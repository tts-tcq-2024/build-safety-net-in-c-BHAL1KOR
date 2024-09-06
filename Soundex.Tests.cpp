#include "Soundex.h"
char soundex[MAX_CODE_LENGTH + 1];

TEST(SoudexTestsuite, EncodeCharacterWithEquivalentNumber) {  
    generateSoundex("Ashcraft", soundex);
    EXPECT_EQ(strcmp(soundex, "A261"), 0);
    generateSoundex("Bach", soundex);
    EXPECT_EQ(strcmp(soundex, "B200"), 0);
    generateSoundex("Pfister", soundex);
    EXPECT_EQ(strcmp(soundex, "P236"), 0);
    generateSoundex("Honeyman", soundex);
    EXPECT_EQ(strcmp(soundex, "H555"), 0);
}

TEST(SoudexTestsuite, DroppingOccurrencesOfVowelsAndSpecificConsonants) {
    generateSoundex("Aeiouyhw", soundex);
    EXPECT_EQ(strcmp(soundex, "A000"), 0);
    generateSoundex("Hello", soundex);
    EXPECT_EQ(strcmp(soundex, "H400"), 0);
    generateSoundex("Soundex", soundex);
    EXPECT_EQ(strcmp(soundex, "S532"), 0);
    generateSoundex("Algorithm", soundex);
    EXPECT_EQ(strcmp(soundex, "A426"), 0);
}

TEST(SoudexTestsuite, ReplacingConsonantsWithDigits) {
    char soundex[MAX_CODE_LENGTH + 1];
    generateSoundex("Bfpv", soundex);
    EXPECT_EQ(strcmp(soundex, "B110"), 0);
    generateSoundex("Cgjkqsxz", soundex);
    EXPECT_EQ(strcmp(soundex, "C222"), 0);
    generateSoundex("Algorithm", soundex);
    EXPECT_EQ(strcmp(soundex, "A426"), 0);
    generateSoundex("Soundex", soundex);
    EXPECT_EQ(strcmp(soundex, "S532"), 0);
}

TEST(SoundexTestsuite, SimilarSoundingWordsHaveSameSoundexOutput) {
    generateSoundex("Robert", soundex);
    EXPECT_EQ(strcmp(soundex, generateSoundex("Rupert")), 0);
    generateSoundex("Rubin", soundex);
    EXPECT_EQ(strcmp(soundex, generateSoundex("Rabin")), 0);
    generateSoundex("Ashcraft", soundex);
    EXPECT_EQ(strcmp(soundex, generateSoundex("Ashcroft")), 0);
    generateSoundex("Jackson", soundex);
    EXPECT_EQ(strcmp(soundex, generateSoundex("Jaxen")), 0);
}

TEST(SoundexTestsuite, EmptyInputReturnsEmptyOutput) {
    generateSoundex("", soundex);
    EXPECT_EQ(strcmp(soundex, ""), 0);
    generateSoundex(NULL, soundex);
    EXPECT_EQ(strcmp(soundex, ""), 0);
}


TEST(SoundexTestsuite, PadsWithZerosIfInputLessThanFourCharacters) {
    generateSoundex("A", soundex);
    EXPECT_EQ(strcmp(soundex, "A000"), 0);
    generateSoundex("AB", soundex);
    EXPECT_EQ(strcmp(soundex, "A100"), 0);
    generateSoundex("ABC", soundex);
    EXPECT_EQ(strcmp(soundex, "A120"), 0);
    generateSoundex("D", soundex);
    EXPECT_EQ(strcmp(soundex, "D000"), 0);
}

