//  let’s dive into “Fruits Into Baskets”   also known as the "Longest Subarray with at Most Two Distinct Elements"

#include <stdio.h>

#define MAX_FRUITS 100005

int totalFruit(int* fruits, int fruitsSize) {
    int count[100005] = {0}; // frequency array to simulate map
    int maxLen = 0;
    int start = 0;
    int types = 0;

    for (int end = 0; end < fruitsSize; end++) {
        int fruit = fruits[end];

        // If we see a new fruit type, increase type count
        if (count[fruit] == 0) {
            types++;
        }
        count[fruit]++;

        // If we now have more than 2 types, shrink from the left
        while (types > 2) {
            int leftFruit = fruits[start];
            count[leftFruit]--;

            // If a fruit's count hits zero, we no longer have it in window
            if (count[leftFruit] == 0) {
                types--;
            }
            start++; // shrink the window
        }

        // Update max length of valid window
        int windowLen = end - start + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}

// Test the function
int main() {
    int fruits[] = {1, 2, 1, 2, 3};
    int size = sizeof(fruits) / sizeof(fruits[0]);

    int result = totalFruit(fruits, size);
    printf("Max fruits collected: %d\n", result);  // Should print 4

    return 0;
}

/*

Patterns You’ll Use:
Concept	                  Why?
Sliding Window->	       To scan through the array efficiently
Hash Map / Array->	     To track how many of each fruit type we’re carrying
Two Pointers->	         One for start of the window, one to expand the end

*/