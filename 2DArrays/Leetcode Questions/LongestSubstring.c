/*
Leetcode #340 - Longest Substring with At Most K Distinct Characters

Generalizes LC #3 and #159.

Keep track of character counts in window.

[Difficulty: Hard]
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define CHAR_COUNT 128  // We assume standard ASCII chars

int lengthOfLongestSubstringKDistinct(char* s, int k) {
    int len = strlen(s);
    if (k == 0 || len == 0) return 0;

    int left = 0;
    int maxLen = 0;
    int distinct = 0;
    int freq[CHAR_COUNT] = {0}; // frequency map

    for (int right = 0; right < len; right++) {
        char c = s[right];

        // If this character is new to the window
        if (freq[c] == 0) {
            distinct++;
        }
        freq[c]++;

        // If we have more than k distinct chars → shrink window
        while (distinct > k) {
            char leftChar = s[left];
            freq[leftChar]--;
            if (freq[leftChar] == 0) {
                distinct--;  // we completely removed one character type
            }
            left++;
        }

        // Update maxLen after adjusting window
        int windowLen = right - left + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}

int main() {
    char s[] = "eceba";
    int k = 2;
    int result = lengthOfLongestSubstringKDistinct(s, k);
    printf("Longest substring with at most %d distinct characters: %d\n", k, result);
    return 0;
}

