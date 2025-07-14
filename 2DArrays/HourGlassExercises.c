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

/*

here in this comments i just added a logic that will check the hourglass with greatest sum based on the calculations same as the above logic the only difference is that in this case we used rows and columns to find the size of our arrays and honestly its pointless since our arrays had sizes but its good for educational purposes 

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
int row=sizeof(arr)/sizeof(arr[0]);
int col=sizeof(arr[0])/sizeof(arr[0][0]);

for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}

for(int i=0;i<=3;i++){
    for(int j=0;j<=3;j++){
        sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]
        + arr[i+1][j+1] +
    
        arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
        
        if(sum>maxSum){
            maxSum=sum;
        }
        
    }
}

    printf("\nfrom our array the hourglass with great sum is: %d ",maxSum);
    return 0;
}
*/






