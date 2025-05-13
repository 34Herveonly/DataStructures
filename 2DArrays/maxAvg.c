// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int arr[5][5],size=9; 
    float Avg,maxAvg=-1.0;
    printf("Enter the values of our array :");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("The entered values are:\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",arr[i][j]);
        }
    }
    
    printf("\nCalculating The Overall Average is ");
    for(int i=0;i<=5-3;i++){
        for(int j=0;j<=5-3;j++){
            Avg=0.0;
            int sum=0;
            for(int x=i;x<i+3;x++){
                for(int y=j;y<j+3;y++){
                    sum +=arr[x][y];
                }
            }
            Avg=sum/size;
            if(Avg>maxAvg){
                maxAvg=Avg;
            }
        }
    }
    printf("The maximum Average of our 3x3 matrix is");
    printf("%d ",maxAvg);
    return 0;
}