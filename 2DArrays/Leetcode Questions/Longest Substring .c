// Today we're going to be taking on a challenge from a leetcode question namely ->     "Longest Substring Without Repeating Characters"

#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256  // Total number of ASCII characters

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);

    // s used in the logic above is just a name we gave to a pointer that points to the first character of our string, and in C, a string is just an array of characters.

    int lastSeen[MAX_CHARS];
    
    // Initialize all characters as not seen yet (-1)
    for (int i = 0; i < MAX_CHARS; i++) {
        lastSeen[i] = -1;
    }

    int maxLen = 0;     // Stores the maximum length found
    int start = 0;      // Start of current substring window

    for (int end = 0; end < n; end++) {
        char currentChar = s[end];

        // If the character was seen and is inside the current window
        if (lastSeen[currentChar] >= start) {
            // Move the window's start past the previous occurrence
            start = lastSeen[currentChar] + 1;
        }

        // Update the last seen index for the current character
        lastSeen[currentChar] = end;

        // Update maxLen if current window is longer
        int windowLen = end - start + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}

// Main function to test with different examples
int main() {
    char input[] = "household";

    printf("Test 1: \"%s\" → %d\n", input, lengthOfLongestSubstring(input)); // 5 ("house")

    return 0;
}

/*

so the way this logic flows is we first create a sliding window that is starting at index 0 and extends our width and each time we extend our window our hashmap will check whether the values in our window have a duplicate.if yes we shift our starting point from start of i to i+1 or simply shifting our point to the value on the right of our starting point and we again check for a duplicate in our new window and if not we keep expanding/extending our window length and while we're doing this we keep track of our maximum lenght of our unique substring and then later we print the number of unique strings we found.      

*/