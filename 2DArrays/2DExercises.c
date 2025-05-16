// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int farm[5][5] = {
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1}
    };
    
    int maxSquare = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int size = 1; // Start with a 1x1 window
            
            // Expand the window using a while loop
            while (i + size <= 5 && j + size <= 5) { // Ensure the window stays in bounds
                // Check if the current size window is valid
                int isSquare = 1; // Assume it is a square of 1s
                
                // Check the new row and column of the expanding square
                for (int x = 0; x < size; x++) {
                    if (farm[i + size - 1][j + x] == 0 || farm[i + x][j + size - 1] == 0) {
                        isSquare = 0; // Not a square
                        break;
                    }
                }
                
                // If it's still a valid square, update maxSquare
                if (isSquare) {
                    if (size * size > maxSquare) {
                        maxSquare = size * size;
                    }
                    size++; // Expand the square
                } else {
                    break; // Stop expanding if it's invalid
                }
            }
        }
    }
    
    printf("Largest Square of 1s: %d\n", maxSquare);
    return 0;
}
