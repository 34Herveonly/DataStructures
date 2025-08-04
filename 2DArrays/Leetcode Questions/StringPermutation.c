/*  Leetcode #567 - Permutation in String

  Check if one string is a permutation of a substring of another.

  classic fixed-size sliding window + hash maps.
  
  [Difficulty: Medium]
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to compare two frequency arrays of size 26
bool areSame(int* arr1, int* arr2) {
    for (int i = 0; i < 26; i++) {
        if (arr1[i] != arr2[i]) {
            return false;  // mismatch in any character frequency
        }
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Quick check: if s1 is longer than s2, it's impossible
    if (len1 > len2) {
        return false;
    }

    // Frequency arrays for s1 and for the current window in s2
    int s1_count[26] = {0};
    int s2_count[26] = {0};

    // Step 1: Count frequencies of s1 and first window in s2
    for (int i = 0; i < len1; i++) {
        s1_count[s1[i] - 'a']++;      // increment for s1
        s2_count[s2[i] - 'a']++;      // first window of s2
    }

    // Step 2: Start sliding the window over s2
    for (int i = 0; i <= len2 - len1; i++) {
        // Compare current window with s1 frequency
        if (areSame(s1_count, s2_count)) {
            return true;  // Found a permutation
        }

        // Slide the window: remove leftmost and add rightmost
        if (i + len1 < len2) {
            s2_count[s2[i] - 'a']--;               // remove char going out
            s2_count[s2[i + len1] - 'a']++;        // add new char coming in
        }
    }

    // After the loop, still check the last window
    return areSame(s1_count, s2_count);
}
int main() {
    char s1[] = "ab";
    char s2[] = "eidbaooo";

    if (checkInclusion(s1, s2)) {
        printf("Permutation exists!\n");
    } else {
        printf("No permutation found.\n");
    }

    return 0;
}
