#include "gtest/gtest.h" 
 #include "Soundex.h"
class SoundexTest : public ::testing::Test {
 protected: 
void SetUp() override { // Initialize any resources needed for tests } 
void TearDown() override { // Clean up any resources allocated in SetUp } }; 
TEST_F(SoundexTest, EmptyName) 
{ char soundex[5]; 
generateSoundex("", soundex); 
EXPECT_STREQ("0000", soundex); 
} 
TEST_F(SoundexTest, SingleCharacterName) 
{ char soundex[5]; 
generateSoundex("A", soundex); 
EXPECT_STREQ("A000", soundex); } 
TEST_F(SoundexTest, NoRepeatedCodes) { 
char soundex[5]; 
generateSoundex("John", soundex); 
EXPECT_STREQ("J500", soundex); } 
TEST_F(SoundexTest, RepeatedCodes) {
 char soundex[5]; 
generateSoundex("Johnson", soundex); 
EXPECT_STREQ("J525", soundex); } 
TEST_F(SoundexTest, LongName) 
{ char soundex[5]; 
generateSoundex("Washington", soundex); 
EXPECT_STREQ("W252", soundex); } 
 int main(int argc, char **argv) 
{ ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS(); } 
