#include <stdio.h>

int main() {

int size,arr[50];

printf("Enter the size of array :");
scanf("%d",&size);

printf("Enter the values of the array:");
for(int i=0;i<size;i++){
scanf("%d",&arr[i]);
}
printf("Entered values are :");
for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
}
// Sorting logic to arrange the values of our array in ascending order
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(arr[j]>arr[j+1]){
            int temp =arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}

printf("\n The sorted array is : \n");
for(int i=0; i<size; i++){
    printf("%d ",arr[i]);
}
    return 0;
}
// 
// Online C compiler to run C program online
// #include <stdio.h>

// int main() {
//     int arr[20],i,j,size;
//     printf("Enter the size: ");
//     scanf("%d",&size);
    
//     printf("enter the values of array :");
//     for(int i=0;i<size;i++){
//     scanf("%d",&arr[i]);
//     }
     
//     printf("\nThe entered values are :");
//     for(int i=0;i<size;i++){
//     printf(" %d ",arr[i]);
//     }
//     printf("\nThe sorted array in descending is :");
//     for(int i=0;i<size;i++){
//         for(int j=0;j<size;j++){
//             if(arr[j+1]>arr[j]){
//                 int temp=arr[j+1];
//                 arr[j+1]=arr[j];
//                 arr[j]=temp;
//             }
//         }
//     }
//     for(int i=0;i<size;i++){
//         printf(" %d ",arr[i]);
//     }
//     return 0;
// }