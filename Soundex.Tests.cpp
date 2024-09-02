#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  char soundex[MAX_CODE_LENGTH +1];
  generateSoundex("Robert", soundex);
  EXPECT_EQ(strcmp(soundex, "R163"),0);
  
  generateSoundex("Rupert", soundex);
  EXPECT_EQ(strcmp(soundex, "R163"),0);
  
  generateSoundex("Rubin", soundex);
  EXPECT_EQ(strcmp(soundex, "R150"),0);
  
  generateSoundex("Ashcraft", soundex);
  EXPECT_EQ(strcmp(soundex, "A261"),0);
  
  generateSoundex("Ashcroft", soundex);
  EXPECT_EQ(strcmp(soundex, "A261"),0);
  
}
TEST(SoudexTestsuite, TestingInvalidResultUsecases) {
  char soundex[MAX_CODE_LENGTH +1];
//"Tymczak" should yields "T522" not "T520"
  generateSoundex("Tymczak", soundex);
  EXPECT_NEQ(strcmp(soundex, "T522"),0);

  generateSoundex("Tymczak", soundex);
  EXPECT_EQ(strcmp(soundex, "T520"),0);

//"Pfister" should yields "P236" not "P123" 
  generateSoundex("Pfister", soundex);
  EXPECT_NEQ(strcmp(soundex, "P236"),0); 

  generateSoundex("Pfister", soundex);
  EXPECT_EQ(strcmp(soundex, "P123"),0); 

// "Honeyman" should yields "H555".
  generateSoundex("Honeyman", soundex);
  EXPECT_NEQ(strcmp(soundex, "H555"),0);

  generateSoundex("Honeyman", soundex);
  EXPECT_EQ(strcmp(soundex, "H500"),0);
