
// This was a challenge from hacker rank which was an exciting experience with full of challenges and it was fun to figure them out along the way

#include <stdio.h>


void reverseArray(int arr[],int size){
    for (int i=size-1;i>=0;i--){
            printf(" %d ",arr[i]);
        }
}


int main() {
    // Write C code here
    int arr[50],i,size;
    printf("Enter the size of our array: ");
    scanf("%d",&size);
    if(size>50){
        printf("Sorry but the size cant exceed 50 ");
    }
    else{
   
    printf("Enter the values of our array: ");
   
    for(int i=0;i<size;i++){
         scanf("%d",&arr[i]);
        }
        printf("The input values of our array are: ");
        for(int i=0;i<size;i++){
         printf(" %d ",arr[i]);  
        }
        
        // the logic to reverse the array
        printf("\n The reversed array would be printed as : ");
        
        reverseArray(arr,size);
    
    }
    return 0;
}
