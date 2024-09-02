#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA 
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_EQ(soundex,"A200");

  generateSoundex("Robert", soundex);
  ASSERT_EQ(soundex, "R163");

  generateSoundex("Rupert", soundex);
  ASSERT_EQ(soundex, "R163");

  generateSoundex("Rubin", soundex);
  ASSERT_EQ(soundex, "R150");

  generateSoundex("Ashcraft", soundex);
  ASSERT_EQ(soundex, "A261");

  generateSoundex("Tymczak", soundex);
  ASSERT_EQ(soundex, "T522");

  generateSoundex("Pfister", soundex);
  ASSERT_EQ(soundex, "P236");

  generateSoundex("", soundex);
  ASSERT_EQ(soundex, "");

  generateSoundex(NULL, soundex);
  ASSERT_EQ(soundex, "");
}
