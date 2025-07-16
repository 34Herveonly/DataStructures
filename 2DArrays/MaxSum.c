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
/*

in this newly added lines of codes in comments we revised about maxSum possible of a 3x3 array from a 5x5 given array and then added a new logic that will print that 3x3 which had max sum

#include <stdio.h>

int main() {
    int maxSum = 0;
    int maxRow = 0, maxCol = 0;  // To track the top-left index of the max 3x3 submatrix

    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    // Print the full array (optional)
    printf("Our Given Array:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0;i<row-2;i++){
        for(int j=0;j<col-2;j++){
            int sum=0;
            
            for(int x=i;x<=i+2;x++){
                for(int y=j;y<=j+2;y++){
                    sum+=arr[x][y];
                }
            }
            printf("\nThe sum of 3x3 at(%d,%d) is: %d",i,j,sum);
            if(sum>maxSum){
                maxSum=sum;
               maxRow=i;
               maxCol=j;
            }
        }
    }
    printf("\n\nThe MaxSum is: %d",maxSum);
    
    printf("\nFrom this array: \n");
    for(int i=maxRow;i<maxRow+3;i++){
        for(int j=maxCol;j<maxCol+3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


*/ 