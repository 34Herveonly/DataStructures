// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Declare a 5x5 array and variables for maximum sum and current sum
    int arr[5][5], maxSum = -1, sum; 

    // Prompt user to enter values for the 5x5 array
    printf("Enter the values of our array :\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    // Display the entered values in a 5x5 matrix format
    printf("\n The entered values are : \n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Initialize sum to 0
    sum = 0;

    // Iterate to find the maximum sum of any 3x3 sub-matrix
    for(int i = 0; i <= 5 - 3; i++){
        // Calculate the sum of the first 3x3 block in the row
        for(int x = i; x < i + 3; x++){
            for(int y = 0; y < 3; y++){
                sum += arr[x][y];
            }
        }

        // Update maxSum if current sum is greater
        if(sum > maxSum){
            maxSum = sum;
        }

        // Slide the 3x3 window horizontally
        for(int j = 1; j <= 2; j++) {
            // Subtract the leftmost column values of the previous 3x3 block
            for(int x = i; x < i + 3; x++){
                sum -= arr[x][j - 1];
            }

            // Add the rightmost column values of the current 3x3 block
            for(int x = i; x < i + 3; x++){
                sum += arr[x][j + 2];
            }

            // Update maxSum if the new sum is greater
            if(sum > maxSum){
                maxSum = sum;
            }
        }
    }

    // Display the result: the maximum sum of any 3x3 sub-matrix
    printf("The maximum sum of our 3x3 Matrix is: %d", maxSum);
    return 0;
}
