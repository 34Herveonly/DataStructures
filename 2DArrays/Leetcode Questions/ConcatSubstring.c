/*
Leetcode #30 - Substring with Concatenation of All Words
Different twist: Combines sliding window with hashmap and fixed-length word tracking.

Description:

Given a string s and a list of words, return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Why it's hard:

Requires managing multiple word boundaries, hashmap tracking, and sliding window logic in tandem.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold word and its frequency count
typedef struct {
    char word[32];
    int count;
} WordEntry;

// Helper function to find index of a word in the list
int findWordIndex(WordEntry* list, int listSize, const char* word) {
    for (int i = 0; i < listSize; i++) {
        if (strcmp(list[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Main logic function
int* findSubstring(char* s, char** words, int wordsSize, int wordLen, int* returnSize) {
    int sLen = strlen(s);
    int windowSize = wordLen * wordsSize;
    int* result = (int*)malloc(sizeof(int) * sLen);
    *returnSize = 0;

    // Step 1: Build the word frequency map
    WordEntry wordMap[wordsSize];
    int wordMapSize = 0;

    for (int i = 0; i < wordsSize; i++) {
        int idx = findWordIndex(wordMap, wordMapSize, words[i]);
        if (idx == -1) {
            strcpy(wordMap[wordMapSize].word, words[i]);
            wordMap[wordMapSize].count = 1;
            wordMapSize++;
        } else {
            wordMap[idx].count++;
        }
    }

    // Step 2: Slide the window through string s
    for (int i = 0; i <= sLen - windowSize; i++) {
        WordEntry seen[wordsSize];
        int seenSize = 0;
        int j = 0;

        for (; j < wordsSize; j++) {
            // Extract a word from the string at the current position
            char currentWord[32];
            strncpy(currentWord, s + i + j * wordLen, wordLen);
            currentWord[wordLen] = '\0';  // Null-terminate

            // Check if it's in the target word list
            int mapIdx = findWordIndex(wordMap, wordMapSize, currentWord);
            if (mapIdx == -1) break;

            // Track how many times we've seen it
            int seenIdx = findWordIndex(seen, seenSize, currentWord);
            if (seenIdx == -1) {
                strcpy(seen[seenSize].word, currentWord);
                seen[seenSize].count = 1;
                seenSize++;
            } else {
                seen[seenIdx].count++;
            }

            // If a word appears too many times, it's invalid
            if (seen[seenIdx].count > wordMap[mapIdx].count) break;
        }

        // If all words matched correctly, record the starting index
        if (j == wordsSize) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }

    return result;
}

// Driver code to test the function
int main() {
    char s[] = "barfoothefoobarman";
    char* words[] = {"foo", "bar"};
    int wordsSize = 2;
    int wordLen = 3;
    int returnSize;

    int* result = findSubstring(s, words, wordsSize, wordLen, &returnSize);

    // Output the result
    printf("Starting indices: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}


/*
          The pattern explanation is described below

We're given a long string and a set of smaller words, all of the same length. Somewhere in that long string, those smaller words appear next to each other, possibly in any order, but used only once each.

What we do is:

Slide a window from left to right across the string.

The window size is equal to the total length of all the words combined.

At each position, we check if the substring in that window:

Can be broken into words of the same length

Contains exactly the same words from the given list (same frequency too)

If it matches, we save the starting index.

Then we continue sliding the window forward to find other possible matches.

In the end, we return or print all the starting indexes where the correct combination of words appeared.
*/