#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  char soundex[MAX_CODE_LENGTH +1];
  EXPECT_EQ(generateSoundex("Robert", "R163"),0);
  EXPECT_EQ(generateSoundex("Rupert", "R163"),0);
  EXPECT_EQ(generateSoundex("Rubin", "R150"),0);
  EXPECT_EQ(generateSoundex("Ashcraft", "A261"),0);
  EXPECT_EQ(generateSoundex("Ashcroft", "A261"),0);
  EXPECT_EQ(generateSoundex("Ashcroft", "A261"),0);
 
  // "Tymczak" yields "T522" not "T520"
  EXPECT_NEQ(generateSoundex("Tymczak", "T522"),0);
  EXPECT_EQ(generateSoundex("Tymczak", "T520"),0);

    //"Pfister" yields "P236" not "P123"
  EXPECT_NEQ(generateSoundex("Pfister", "P236"),0);
  EXPECT_EQ(generateSoundex("Pfister", "P123"),0);


    // "Honeyman" yields "H555" 
  EXPECT_NEQ(generateSoundex("Honeyman", "H555"),0);
  EXPECT_EQ(generateSoundex("Honeyman", "H500"),0);


}
