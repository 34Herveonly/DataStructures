// Online C compiler to run C program online
#include <stdio.h>

int main() {

    // Declaring a 5x5 2D array and variables to track max sum
    int arr[5][5];
    int maxSum = -1, sum = 0;

    // Prompting the user to enter values for the 5x5 matrix
    printf("Enter the values of our 2D arrays \n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &arr[i][j]); // Reading user input for each element
        }
    }

    // Displaying the entered matrix
    printf("The entered values are : \n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", arr[i][j]); // Displaying each element
        }
        printf("\n"); // New line after each row
    }

    // Sliding window logic to calculate max sum of any 3x3 submatrix
    printf("Comparing the sums:\n");
    for(int i = 0; i <= 5 - 3; i++){ // Looping over rows (0 to 2)
        for(int j = 0; j <= 5 - 3; j++){ // Looping over columns (0 to 2)
            
            int sum = 0; // Initializing sum for the current 3x3 window
            
            // Calculating sum of the current 3x3 window
            for(int x = i; x < i + 3; x++){
                for(int y = j; y < j + 3; y++){
                    sum += arr[x][y]; // Adding each element in the 3x3 window
                }
            }

            // Checking if the calculated sum is the largest so far
            if(sum > maxSum){
                maxSum = sum;
            }
        }
    }

    // Displaying the maximum sum found
    printf("The maximum sum of a 3x3 array from a 5x5 matrix is : %d\n", maxSum);

    return 0;
}

/*
I am going to resolve this same finding the maximum sum question but this time instead of using bruteforce im going to use the sliding window technique which is much faster and avoids re-calculating everything instead it removes the previously existed column and then adds the newy added one without having to re-calculate everything  


#include <stdio.h>

int main(){
int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int size=9;
    int maxSum=0;

    for(int i=0;i<5-2;i++){
        int sum=0;

        for(int x=i;x<i+3;x++){
          for(int y=0;y<3;y++){
          sum+=arr[x][y];
          }
        }
          printf("\nThe sum is: %d",sum);
          if(sum>maxSum){
            maxSum=sum;
          }
    
          for(int j=1;j<5-2;j++){
            for(int x=i;x<i+3;x++){
            sum-=arr[x][j-1];
            sum+=arr[x][j+2];    
            }
         }
            printf("\nThe sum is: %d",sum);
            if(sum>maxSum){
            maxSum=sum;
            
        }
      }
    printf("\nThe maximum sum is: %d",maxSum);
      return 0;
}


*/ 