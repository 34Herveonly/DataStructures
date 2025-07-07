// Online C compiler to run C program online

// Using Hashmaps to find duplicates in a user-input array

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // Size of our hashmap (acts as hash table slots)

// Structure to represent each hashmap entry
typedef struct {
    int key;         // Actual value from the array
    int is_present;  // Flag to indicate if this key has been stored already
} hashMap;

// Hash function to map a value to an index in the hashmap
int hash(int key) {
    return abs(key) % MAX;
}

int main() {
    int arr[50], size, i;

    // Step 1: Get the size of the array from the user
    printf("Enter the size of array: ");
    scanf("%d", &size);

    // Step 2: Get array elements from the user
    printf("Enter the values of array:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Display the entered array
    printf("The added values are:\n");
    for(int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }

    // Step 4: Create and initialize the hashmap to track seen elements
    hashMap map[MAX] = {0};  // All entries default to key = 0, is_present = 0

    // Step 5: Traverse the array and check for duplicates using the hashmap
    for(int i = 0; i < size; i++) {
        int current = arr[i];           // Current value
        int index = hash(current);      // Hash it to find the corresponding index

        // If the slot is already used and matches our current value, it's a duplicate
        if(map[index].is_present && map[index].key == current) {
            printf("\n  the duplicated value is: %d\n", current);
            // We could break or return if we only care about the first duplicate
            // return 0;
        }

        // Otherwise, store this value in the hashmap
        map[index].is_present = 1;
        map[index].key = current;
    }

    // Optional: print message if no duplicates were found
    // printf("No duplicates found in the array.");

    return 0;
}
