#include "Soundex.h"

TEST( SoudexTestsuite, EncodeCharacterWithEquivalentNumber )
{
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Bach"), "B200");
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
    EXPECT_EQ(generateSoundex("Honeyman"), "H555");
}

TEST(SoudexTestsuite, DroppingOccurrencesOfVowelsAndSpecificConsonants) {
    EXPECT_EQ(generateSoundex("Aeiouyhw"), "A000");
    EXPECT_EQ(generateSoundex("Hello"), "H400");
    EXPECT_EQ(generateSoundex("Soundex"), "S532");
    EXPECT_EQ(generateSoundex("Algorithm"), "A426");
}

TEST(SoudexTestsuite, ReplacingConsonantsWithDigits) {
    EXPECT_EQ(generateSoundex("Bfpv"), "B110");
    EXPECT_EQ(generateSoundex("Cgjkqsxz"), "C222");
    EXPECT_EQ(generateSoundex("Algorithm"), "A426");
    EXPECT_EQ(generateSoundex("Soundex"), "S532");
}

TEST(SoundexTestsuite, SimilarSoundingWordsHaveSameSoundexOutput) {
    EXPECT_EQ(generateSoundex("Robert"), generateSoundex("Rupert"));
    EXPECT_EQ(generateSoundex("Rubin"), generateSoundex("Rabin"));
    EXPECT_EQ(generateSoundex("Ashcraft"), generateSoundex("Ashcroft"));
    EXPECT_EQ(generateSoundex("Jackson"), generateSoundex("Jaxen"));
}

TEST(SoundexTestsuite, EmptyInputReturnsEmptyOutput) {
    EXPECT_EQ(generateSoundex(""), ""); 
    EXPECT_EQ(generateSoundex(NULL), "");
}

TEST(SoundexTestsuite, PadsWithZerosIfInputLessThanFourCharacters) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("AB"), "A100");
    EXPECT_EQ(generateSoundex("ABC"), "A120");
    EXPECT_EQ(generateSoundex("D"), "D000");
}
