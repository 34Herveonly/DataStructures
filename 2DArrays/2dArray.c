
// Online C compiler to run C program online
#include <stdio.h>

int main() {

int arr[3][3];
printf("Enter the values of our 2D arrays \n");
for(int i=0; i<3; i++){
    for(int j=0;j<3;j++){
        scanf("%d ",&arr[i][j]);
    }
}

printf("The entered values are : \n");
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        printf("%d ",arr[i][j]);
    }
}
    return 0;
}