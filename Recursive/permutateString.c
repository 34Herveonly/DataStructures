// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

// Recursive function to print all permutations of a string
int print(char word[], int index, int length) {

    // Base case: if current index reaches the end, print the permutation
    if (index == length) {
        printf("%s \n", word);
    }

    // Recursive case: swap each character with the current index
    else {
        for (int i = index; i < length; i++) {

            // Swap current character with character at position i
            char temp = word[index];
            word[index] = word[i];
            word[i] = temp;

            // Recurse for the next index
            print(word, index + 1, length);

            // Backtrack: undo the swap to restore original state
            word[i] = word[index];
            word[index] = temp;
        }
    }
}

int main() {
    char word[] = "ABC";                 // The input string to permute
    int index = 0;                       // Start from index 0
    int length = strlen(word);          // Calculate the length of the string
    print(word, index, length);         // Generate and print all permutations

    return 0;
}
