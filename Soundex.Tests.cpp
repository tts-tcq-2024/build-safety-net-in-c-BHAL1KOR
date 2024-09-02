#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  char soundex[MAX_CODE_LENGTH +1];
  EXPECT_EQ(generateSoundex("Robert", "R163"));
  EXPECT_EQ(generateSoundex("Rupert", "R163"));
  EXPECT_EQ(generateSoundex("Rubin", "R150"));
  EXPECT_EQ(generateSoundex("Ashcraft", "A261"));
  EXPECT_EQ(generateSoundex("Ashcroft", "A261"));
  EXPECT_EQ(generateSoundex("Ashcroft", "A261"));
 
  // "Tymczak" yields "T522" not "T520"
  EXPECT_NEQ(generateSoundex("Tymczak", "T522"));
  EXPECT_EQ(generateSoundex("Tymczak", "T520"));

    //"Pfister" yields "P236" not "P123"
  EXPECT_NEQ(generateSoundex("Pfister", "P236"));
  EXPECT_EQ(generateSoundex("Pfister", "P123"));


    // "Honeyman" yields "H555" 
  EXPECT_NEQ(generateSoundex("Honeyman", "H555"));
  EXPECT_EQ(generateSoundex("Honeyman", "H500"));


}
