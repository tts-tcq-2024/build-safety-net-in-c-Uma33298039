#include <gtest/gtest.h> 
#include "Soundex.h" // Test fixture class for Soundex tests 
class SoundexTest : public ::testing::Test 
{ protected: char soundex[5]; 
 void assertSoundex(const char* name, const char* expected) 
{ generateSoundex(name, soundex); 
ASSERT_STREQ(soundex, expected); } }; 
TEST_F(SoundexTest, EmptyName)
 { assertSoundex("", "0000"); } 
TEST_F(SoundexTest, ShortName) 
{ assertSoundex("Bob", "B000"); } 
TEST_F(SoundexTest, LongName) 
{ assertSoundex("Washington", "W252"); } 
TEST_F(SoundexTest, RepeatedCharacters) 
{ assertSoundex("Johnson", "J525"); } 
TEST_F(SoundexTest, MixedCase) 
{ assertSoundex("McDonald", "M235"); }
 int main(int argc, char **argv) { ::testing::InitGoogleTest(&argc, argv); return RUN_ALL_TESTS(); } 
