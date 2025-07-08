// I came up with an idea to check wether an input value is an even value or odd by first asking the user to input that value we eould like to check then we divide it by 2 and its remainder is zero then its an even else it would be an odd

// Online C compiler to run C program online
// #include <stdio.h>

// int isEven(int value){
//     if(value%2==0){
//         printf("This value is an even number.");
// }else{
// printf("This value is an odd number.");
//     }
// }
// int main() {
//     int value;
    
//     printf("Enter the value to check its type :");
//     scanf("%d",&value);
// isEven(value);
//     return 0;
// }


// Below i just added some logic where we're now printing the values of our give array which are even but there's also a commented line which was printing the odd ones as well nut since we're trying to find even ones its commented out


#include <stdio.h>

int isEven(int arr[],int size){
    for (int i=0;i<size;i++){
    if(arr[i]%2==0){
        printf("\nThis value is an even number. %d",arr[i]);
        }
    else{
        // printf("\nThis value is an odd number. %d",arr[i]);
        continue;
        }
    }
}
int main() {
    int arr[]={1,3,5,2,4,6,8,29,24,56,78},i;
    int size=sizeof(arr)/sizeof(arr[0]);
    
    // printf("Enter the value to check its type :");
    // scanf("%d",&value);
isEven(arr,size);
    return 0;
}

