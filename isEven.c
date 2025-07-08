// I came up with an idea to check wether an input value is an even value or odd by first asking the user to input that value we eould like to check then we divide it by 2 and its remainder is zero then its an even else it would be an odd

// Online C compiler to run C program online
#include <stdio.h>

int isEven(int value){
    if(value%2==0){
        printf("This value is an even number.");
}else{
printf("This value is an odd number.");
    }
}
int main() {
    int value;
    
    printf("Enter the value to check its type :");
    scanf("%d",&value);
isEven(value);
    return 0;
}