#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    if (len == 0) {
        strcpy(soundex, "0000");
        return;
    }

    soundex[0] = toupper(name[0]);
    char previousCode = getSoundexCode(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != previousCode) {
            soundex[sIndex++] = previousCode = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
