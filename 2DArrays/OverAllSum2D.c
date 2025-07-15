// Online C compiler to run C program online
#include <stdio.h>

int main()
{
    // Declaring a 5x5 matrix and variables for sum calculations
    int arr[5][5], sum, totalSum = 0;

    // Taking user input to fill the 5x5 matrix
    printf("Enter the values of our array:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &arr[i][j]); // Reading each value
        }
    }

    // Displaying the entered 5x5 matrix
    printf("\nThe entered values are: \n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); // New line after each row
    }

    // Calculating the total sum of all possible 3x3 submatrices
    printf("\nCalculating the sum of all 3x3 submatrices:\n");
    for (int i = 0; i <= 5 - 3; i++)
    { // Row range for 3x3 window
        for (int j = 0; j <= 5 - 3; j++)
        {            // Column range for 3x3 window
            sum = 0; // Reset sum for each new window

            // Calculating the sum of the current 3x3 window
            for (int x = i; x < i + 3; x++)
            {
                for (int y = j; y < j + 3; y++)
                {
                    sum += arr[x][y]; // Adding each value within the window
                }
            }

            // Adding the sum of this 3x3 window to totalSum
            totalSum += sum;
            printf("Sum of 3x3 starting at (%d,%d): %d\n", i, j, sum);
        }
    }

    // Displaying the total sum of all 3x3 windows
    printf("\nThe Overall sum of all 3x3 window matrices is: %d\n", totalSum);
    return 0;
}

/*

just did a revision of how to approach this question and did a lil bit of advancements on it by using the rows and cols for the size of our arrays and then printed all sums of our 3x3 arrays and then added them together

#include <stdio.h>

int main() {
    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int totalSum=0;
    int row=sizeof(arr)/sizeof(arr[0]);
    int col=sizeof(arr[0])/sizeof(arr[0][0]);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

     for(int i=0;i<row-2;i++){
         for(int j=0;j<col-2;j++){
             int sum=0;

             for(int x=i;x<i+3;x++){
                 for(int y=j;y<j+3;y++){
                     sum+=arr[x][y];
                 }
          }
          totalSum+=sum;
          printf("The Sum of our 3x3 array starting at(%d,%d): %d\n",i,j,sum);

         }
     }
         printf("\nThe Overall sum of all 3x3 window matrices is: %d\n", totalSum);

    return 0;
}

*/
