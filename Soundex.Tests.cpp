#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  char soundex[MAX_CODE_LENGTH +1];
  generateSoundex("Robert", soundex)
  EXPECT_EQ(strcmp(soundex, "R163"),0);


}
