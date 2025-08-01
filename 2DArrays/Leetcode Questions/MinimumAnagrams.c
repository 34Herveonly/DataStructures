/* Leetcode #438 - Find All Anagrams in a String
  Find all substrings in s that are anagrams of p.
  Use sliding window + frequency map.
  [Difficulty: Medium]*/


  
#include <stdio.h>      // Standard input/output
#include <stdlib.h>     // For malloc and free
#include <string.h>     // For strlen
#include <stdbool.h>    // For using true/false in boolean functions

#define CHAR_COUNT 26   // Only lowercase letters 'a' to 'z'

// Function to compare two frequency arrays
bool isSame(int *a, int *b) {
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (a[i] != b[i])   // If any count doesn't match
            return false;
    }
    return true;            // All counts matched → valid anagram
}

// Main function to find all anagram start indices
int* findAnagrams(char* s, char* p, int* returnSize) {
    int lenS = strlen(s);   // Length of the main string
    int lenP = strlen(p);   // Length of the pattern string
    int *res = (int *)malloc(sizeof(int) * lenS); // Allocate memory to store results
    *returnSize = 0;        // Initialize count of results

    // If the pattern is longer than the main string, return empty
    if (lenS < lenP) return res;

    int pFreq[CHAR_COUNT] = {0};       // Frequency map for string p
    int windowFreq[CHAR_COUNT] = {0};  // Frequency map for current window in s

    // Build the initial frequency maps for p and first window in s
    for (int i = 0; i < lenP; i++) {
        pFreq[p[i] - 'a']++;           // Count character in p
        windowFreq[s[i] - 'a']++;      // Count character in first window of s
    }

    // Check if first window is an anagram
    if (isSame(pFreq, windowFreq)) {
        res[(*returnSize)++] = 0;      // If yes, store starting index 0
    }

    // Slide the window one char at a time
    for (int i = lenP; i < lenS; i++) {
        windowFreq[s[i] - 'a']++;                  // Add new character to right of window
        windowFreq[s[i - lenP] - 'a']--;           // Remove old character from left of window

        // If after update, window is an anagram of p
        if (isSame(pFreq, windowFreq)) {
            res[(*returnSize)++] = i - lenP + 1;   // Store starting index
        }
    }

    return res; // Return the result array
}

// Example usage
int main() {
    char *s = "cbaebabacd";       // Main string
    char *p = "abc";              // Pattern string
    int returnSize;               // Will store number of matches
    int *result = findAnagrams(s, p, &returnSize); // Call the function

    // Print all found indices
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result); // Free allocated memory
    return 0;
}


  /*Two strings are anagrams if they have the same letters with the same count.

"abc" and "bca" → anagrams
"aabc" and "abca" → anagrams */