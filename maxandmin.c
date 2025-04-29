#include <stdio.h>

int main(){
    int arr[100],i,max=0,size,min;
    
    printf("Enter the size of an array");
    scanf("%d",&size);
    
    printf("Enter the values of an array");
    for(i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    
    printf("the values you added are:");
    for(i=0; i<size;i++){
        printf("%d\n",arr[i]);
    }
    
    // for(int i=0;i<size; i++){   
    // int current=arr[i];
    
    // if(current>max){
    //     max=current;
    //     }
    // }
    //  printf("the max is %d",max);
    
     
     min=arr[0]; 
    for(int i=0;i<size; i++) {
      
    if(min > arr[i]){
        min=arr[i];
        }
    }
     printf("the min is %d",min);


    return 0;
}