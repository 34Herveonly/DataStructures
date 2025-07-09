
// Online C compiler to run C program online
// #include <stdio.h>

// int main() {

// int arr[3][3];
// printf("Enter the values of our 2D arrays \n");
// for(int i=0; i<3; i++){
//     for(int j=0;j<3;j++){
//         scanf("%d ",&arr[i][j]);
//     }
// }

// printf("The entered values are : \n");
// for(int i=0;i<3;i++){
//     for(int j=0;j<3;j++){
//         printf("%d ",arr[i][j]);
//     }
// }
//     return 0;
// }


// This is a newly updated array which is a 2d array, this program asks for a user to input the values and then prints them it takes calculates sizes of rows and columns because not all the times we will have the initialised sizes of our 2d arrays  

#include <stdio.h>

int main() {
int arr[3][3];
int row=sizeof(arr)/sizeof(arr[0]);
int col=sizeof(arr[0])/sizeof(arr[0][0]);

printf("Enter the values of array: ");
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        scanf("%d",&arr[i][j]);
    }
}
  printf("The added array is: \n");
  for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
          printf("%d ",arr[i][j]);
      }
      printf("\n");
  }

    return 0;
}