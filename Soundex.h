#ifndef SOUNDEX_H
#define SOUNDEX_H
#include <ctype.h>
#include <string.h>

// Function to generate Soundex code for a given name
void generateSoundex(const char *name, char *soundex)
{
    static const char Map[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4',
        '5', '5', '0', '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2'
    };

    if (name[0] == '\0')
    {
        strcpy(soundex, "0000");
        return;
    }

    soundex[0] = toupper(name[0]);
    int Index = 0;
    char prevCode = soundex[0];

    for (int i = 1; name[i] != '\0' && Index < 4; i++)
    {
        char code = isalpha(name[i]) ? Map[toupper(name[i]) - 'A'] : '0';
        if (code != '0' && code != prevCode)
        {
            soundex[++Index] = code;
            prevCode = code;
        }
    }

    while (++Index < 4)
    {
        soundex[Index] = '0';
    }

    soundex[4] = '\0'; // Null terminate the string
}
#endif 
