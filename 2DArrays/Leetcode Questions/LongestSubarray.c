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

if (count[fruit] == 0)  "Is this fruit new?" → If yes, add it to types and keep counting it.

if (count[leftFruit] == 0)   "Did we fully remove this fruit type from the window?" → If yes, drop it from our arrays/baskets adn after its size iz equal to zero we decrease the types from 3 back to 2.

// so here what we were trying to do was to traverse through our array and find 2 unique types of fruits that will be added to our baskets and as we traverse and add those fruits if we encounter any new type of fruit that we didnt previously have in our baskets we will go back and remove some type of fruits from the left until when we remain with only 2 types of fruits in our baskets because our condition says atmost 2 types of fruits! and while we do that we will track the max length we traverelled collecting other fruits with solely 2 types of fruits in our baskets without meeting a new type and thats what we will return      


*/