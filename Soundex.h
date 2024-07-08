#include "soundex.h"
#include <ctype.h> 
#include <string.h> // Helper function to get Soundex code for a character 
static char getSoundexCode(char c) 
{ static const char Map[26] = { 
'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2' }; 
return isalpha(c) ? Map[toupper(c) - 'A'] : '0';
 } // Function to generate Soundex code for a given name 
void generateSoundex(const char *name, char *soundex)
{ 
    if (name[0] == '\0') 
    { 
        strcpy(soundex, "0000"); return; 
    } 
soundex[0] = toupper(name[0]);
int index = 1; // Start after the initial character 
for (int i = 1; name[i] != '\0' && index < 4; i++) 
{ char code = getSoundexCode(name[i]);
 if (code != '0' && code != soundex[index - 1]) 
{ soundex[index++] = code; } } 
while (index < 4) { soundex[index++] = '0'; } 
soundex[4] = '\0'; // Null terminate the string
 } 
