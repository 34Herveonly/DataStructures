/*  “Fruit Into Two Baskets – Variant”
 (With One Unlimited Basket + One Limited to 2 Fruits) */

#include <stdio.h>
#include <string.h>

#define MAX_FRUITS 100005  // Adjust as needed
#define MAX_TYPES 1001     // Assuming fruit types are integers < 1000

int maxFruitsWithTwoBaskets(int* fruits, int n) {
    int count[MAX_TYPES] = {0};  // Frequency map
    int start = 0, maxLen = 0;
    int types = 0;               // Current number of fruit types
    int limitedType = -1;        // The fruit type in Basket B (limited to 2)

    for (int end = 0; end < n; end++) {
        int fruit = fruits[end];

        // New fruit type?
        if (count[fruit] == 0) {
            types++;
        }

        count[fruit]++;

        // Assign or update limitedType if needed
        if (limitedType == -1 || (fruit != limitedType && count[fruit] <= 2)) {
            limitedType = fruit;
        }

        // Now check if this fruit violates Basket B rule
        while (types > 2 || (fruit == limitedType && count[fruit] > 2)) {
            int leftFruit = fruits[start];
            count[leftFruit]--;
            if (count[leftFruit] == 0) {
                types--;
                if (leftFruit == limitedType) {
                    // Reset limitedType because we just removed it
                    limitedType = -1;
                    // Recalculate which remaining fruit might be the new limited one
                    for (int i = 0; i < MAX_TYPES; i++) {
                        if (count[i] > 0 && count[i] <= 2) {
                            limitedType = i;
                            break;
                        }
                    }
                }
            }
            start++; // Shrink window from the left
        }

        int windowLen = end - start + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}

// Main for testing
int main() {
    int fruits[] = {1, 2, 2, 1, 3, 1, 1, 2};
    int size = sizeof(fruits) / sizeof(fruits[0]);

    int result = maxFruitsWithTwoBaskets(fruits, size);
    printf("Maximum number of fruits collected: %d\n", result);

    return 0;
}

/*

For this case it kinda works like the logic from longest sub-array where we will need to use a sliding window to be able to traverse through our given stall of fruits or array of integers and then as we traverse from left to right of our array we will use a hashmap to keep track of types of fruits counted so that they wont exceed our conditions and whenever we find one of the fruits in our array to be making our logic be false we will stop right there and remove one type from the left and as we do so we must makesure also that in the second basket there is only 2fruits of same type as we were told in instructions    

*/