#include <stdio.h>

int main(){
    int arr[30], size;          // Declare an integer array 'arr' with max size 30 and an integer 'size' for actual array size
    double value, ratio[30];    // Declare a double 'value' for temporary calculations and a double array 'ratio' to store results
    
    // Prompt user to enter the size of the array
    printf("Enter the size of your array: ");
    scanf("%d", &size);
     
    // Prompt user to input the elements of the array
    printf("Enter the elements of our array:\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);   // Read each element into the array
    }
    
    // Display the entered values
    printf("The added values are:");
    for(int i = 0; i < size; i++){
        printf(" %d ", arr[i]);
    }
    
    // Calculate the ratio for each element by dividing it by the size of the array
    // Multiplying by 1.0 ensures floating-point division instead of integer division
    for(int i = 0; i < size; i++){
        value = arr[i] * 1.0 / size;
        ratio[i] = value;       // Store the result in the ratio array
    }
    
    // Print the calculated ratios
    printf("\nThe ratios of our values are:\n");
    for(int i = 0; i < size; i++){
        printf("%6f ", ratio[i]);  // Print each ratio with 6 decimal places
    }

    return 0;
}
