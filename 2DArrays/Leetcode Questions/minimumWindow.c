/*
Leetcode #76 - Minimum Window Substring

Find the minimum window in s that contains all characters of t.

Classic shrinking/growing window with counter.

[Difficulty: Hard]*/


#include <stdio.h>
#include <string.h>
#include <limits.h>  // For INT_MAX
#include <stdbool.h>

#define CHAR_COUNT 128  // Supports all ASCII characters

// Function to check if window covers all characters in t
bool windowContainsAll(int *windowFreq, int *tFreq) {
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (tFreq[i] > 0 && windowFreq[i] < tFreq[i]) {
            return false;
        }
    }
    return true;
}

char* minWindow(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);
    
    if (lenT > lenS || lenT == 0) return "";

    int tFreq[CHAR_COUNT] = {0};       // Frequency map of t
    int windowFreq[CHAR_COUNT] = {0};  // Frequency map of current window

    // Step 1: Count frequency of characters in t
    for (int i = 0; i < lenT; i++) {
        tFreq[t[i]]++;
    }

    int minLen = INT_MAX;
    int minStart = 0;
    int left = 0;

    // Step 2: Slide right pointer to expand window
    for (int right = 0; right < lenS; right++) {
        char c = s[right];
        windowFreq[c]++;

        // Step 3: Try to shrink from the left if window is valid
        while (windowContainsAll(windowFreq, tFreq)) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            // Shrink window from left
            windowFreq[s[left]]--;
            left++;
        }
    }

    if (minLen == INT_MAX) {
        return "";  // No valid window found
    }

    // Extract and return the minimum window substring
    static char result[1000]; // adjust size as needed
    strncpy(result, s + minStart, minLen);
    result[minLen] = '\0';
    return result;
}
int main() {
    char s[] = "ADOBECODEBANCANIBAL";
    char t[] = "ABC";

    char* result = minWindow(s, t);
    printf("Minimum window substring: %s\n", result);

    return 0;
}

/* We use a growing and shrinking window with 2 frequency maps: one for the goal characters (t) and one for the current window in s.
We expand the window with the right pointer and shrink it with the left pointer to find the smallest window that contains all characters of t.

Right pointer → expands window

Left pointer → shrinks window

tFreq → tells us what characters we need

windowFreq → shows what we have right now

If windowFreq has all characters from tFreq → we found a valid window

Try to shrink the window as much as possible while still valid

Track the shortest one and return it
*/