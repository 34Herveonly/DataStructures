// Requesting array size and values from user then reversing that array and printing it 
#include <stdio.h>

int main() {

int arr[50],rev[50],size,i;

printf("Enter the size of an array:");
scanf("%d",&size);

printf("Enter the values of our array :");
for( i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
printf("The Added values are\n");
for(i=0;i<size;i++){
printf("%d ",arr[i]);
}

int index=0;

for(i=size-1;i>=0;i--) {
// printf("\n%d\b",arr[i]);
int current=arr[i];
    if(index<size){
        rev[index]=current;
        index++;
    }
}
printf("\nThe Reversed Array is\n");
for(i=0;i<size;i++){
    printf("%d ",rev[i]);
}
    return 0;
}












