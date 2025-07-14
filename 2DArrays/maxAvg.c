#include <stdio.h>

int main() {
    int arr[5][5], size = 9; 
    float Avg, maxAvg = -1.0;

    printf("Enter the values of our array:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The entered values are:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nCalculating the overall maximum average...\n");

    for (int i = 0; i <= 5 - 3; i++) {
        for (int j = 0; j <= 5 - 3; j++) {
            Avg = 0.0;
            int sum = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    sum += arr[x][y];
                }
            }
            Avg = (float)sum / size;  // ✅ Use float division

            if (Avg > maxAvg) {
                maxAvg = Avg;
            }
        }
    }

    printf("The maximum average of a 3x3 submatrix is: %.2f\n", maxAvg);  // ✅ Use float format

    return 0;
}

/*

in the comments below the codes we had previously i just added a more simpler logic where user didn't even add the input we had it initially and then we calculated the highest sum possible and then used it to find the biggest avg possible  


#include <stdio.h>

int main() {
    int size = 9; 
    float Avg, maxAvg = -1.0;
    
    int arr[5][5]={1,2,3,4,5
    ,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
    ,21,22,23,24,25};

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
since we're tryna find the biggest avg of a 3x3 square so thats why we use this logic below to make sure we stay in bounds that satisfy the 3x3 and do not exceed 5 becaus its our array's limit
    
    for(int i=0;i<5-2;i++){
        for(int j=0;j<5-2;j++){
            
            int sum=0;
This below is responsible for traversing through our newly created 3x3 square and make the additions and ot starts at position x=i so that it wont go beyond our 3x3 bounds that's why it should be less than i+3 

            for(int x=i;x<i+3;x++){
                for(int y=j;y<j+3;y++){
                    sum+=arr[x][y];
                }
            }
            Avg=(float)sum/size;
            
            if(Avg>maxAvg){
                maxAvg=Avg;
            }
        }
    }
        printf(" The maximum Avg overall is: %2f",maxAvg);
    return 0;
}

*/