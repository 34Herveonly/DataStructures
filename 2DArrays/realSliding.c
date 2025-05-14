#include <stdio.h>

int main() {
    int arr[5][5];
    float maxAvg = -1.0, currentAvg;
    int size = 9; // 3x3 = 9 elements

    // Taking input for our 5x5 array
    printf("Enter the values of our 5x5 array:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Displaying the entered values
    printf("The entered values are:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Calculating the average using optimized sliding window
    for (int i = 0; i <= 5 - 3; i++) {
        // Calculate the sum of the first 3x3 window in this row
        int sum = 0;
        for (int x = i; x < i + 3; x++) {
            for (int y = 0; y < 3; y++) {
                sum += arr[x][y];
            }
        }
        // Initial average for the first 3x3 window
        currentAvg = (float)sum / size;
        if (currentAvg > maxAvg) {
            maxAvg = currentAvg;
        }

        // Sliding the window right
        for (int j = 1; j <= 5 - 3; j++) {
            // Subtract the left column values
            for (int x = i; x < i + 3; x++) {
                sum -= arr[x][j - 1];
            }
            // Add the right column values
            for (int x = i; x < i + 3; x++) {
                sum += arr[x][j + 2];
            }

            // Calculate the new average
            currentAvg = (float)sum / size;
            if (currentAvg > maxAvg) {
                maxAvg = currentAvg;
            }
        }
    }

    // Displaying the result
    printf("\nThe maximum average of any 3x3 window is: %.2f\n", maxAvg);

    return 0;
}
