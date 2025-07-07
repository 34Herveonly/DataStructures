// This is a Dsa logic to delete a value from specified position of an array

#include <stdio.h>

int main (){
    int size,arr[50],pos;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    
    printf("Enter the values of array:");
    for(int i=0; i<size;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("The entered values are: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
    printf("\nEnter the position you want to delete from ");
    scanf("%d",&pos);
    
    for(int i=pos-1;i<size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    
    printf("The updated array is :");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}  