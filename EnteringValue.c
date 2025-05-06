// This is the Dsa logic to enter a certain value at a certain position 
// Online C compiler to run C program online
#include <stdio.h>

int main() {
int arr[50],size,num,pos;

printf("Enter the size of array: ");
scanf("%d",&size);

if(size>50){
    printf("Size cant exceed 50\n");
}

else {
    printf("Enter the values of array:");
    for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
    }
    
    printf("The entered values are:");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
    printf("\nEnter the value you want to add in the array :");
    scanf("%d",&num);
    printf("\nEnter the position you want to add it to :");
    scanf("%d",&pos);
    
    for(int i=size-1;i>=pos-1;i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    size++;
    
    printf("The updated array is:");
    for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
    }
    
}
    return 0;
} 