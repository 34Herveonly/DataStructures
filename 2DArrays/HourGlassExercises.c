// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int sum=0,maxSum=-63;
    int arr[6][6] = {
    {1, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0},
    {0, 0, 2, 4, 4, 0},
    {0, 0, 0, 2, 0, 0},
    {0, 0, 1, 2, 4, 0}
};

    // Write C code here
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    for (int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] 
                       + arr[i+1][j+1] +
                 arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
                 
                 printf("\n %d \n",sum);
                 
                if(sum>maxSum){
                    maxSum=sum;
                }
                printf("\n %d \n",maxSum);
        }
    }
    printf("\n The Max HourGlass from our array is : %d", maxSum);

    return 0;
}






