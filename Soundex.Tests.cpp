#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

// Function to test: include the header where your functions are declared
#include "soundex.h"

// Helper function to compare two strings and print result
void assertStringEquals(const char *expected, const char *actual) {
    if (strcmp(expected, actual) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL - Expected: %s, Actual: %s\n", expected, actual);
    }
}

// Unit tests for generateSoundex function
void test_generateSoundex() {
    char soundex[5];

    // Test cases
    generateSoundex("Smith", soundex);
    assertStringEquals("S530", soundex);

    generateSoundex("Johnson", soundex);
    assertStringEquals("J525", soundex);

    generateSoundex("Garcia", soundex);
    assertStringEquals("G620", soundex);

    generateSoundex("Williams", soundex);
    assertStringEquals("W452", soundex);

    generateSoundex("Miller", soundex);
    assertStringEquals("M460", soundex);

    generateSoundex("Davis", soundex);
    assertStringEquals("D120", soundex);

    // Edge cases
    generateSoundex("A", soundex);
    assertStringEquals("A000", soundex);

    generateSoundex("", soundex);
    assertStringEquals("0", soundex); // Assuming an empty string returns "0000"
}

// Main function to run tests
int main() {
    test_generateSoundex();
    return 0;
}
