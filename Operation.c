// In These sets of codes there's logic to find sum,product,difference and Average of your values in an array.

#include <stdio.h>

int main() {
    
   int arr[50],size,sum=0,product,difference,current;
    float avg;
    printf("Enter the size of an array");
     scanf("%d",&size);
    printf("Enter the values in an array");
     for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
     }
     
     printf("The entered Values are: \n");
     for(int i=0;i<size; i++){
         printf("%d\n",arr[i]);
     }
     
  //  Calculating the Sum
     
     for(int i=0; i<size; i++){
         sum=sum+arr[i];
     }
     printf("the sum is %d",sum);
     
    // // Calculating the Product
        // product=1;
        // for(int i=0;i<size; i++){
        //     product*=arr[i];
        // }
        //     printf("The product is %d",product);    
        
        
     // Calculating the difference
    //     int start=arr[0];
    //     int min=arr[0];
    //     for(int i=0;i<size;i++){
    //          current=arr[i];
    //         if(current>start){
    //             start=current;
    //         }
    //         if(current<min){
    //             min=current;
    //         }
    //     }
    //     difference=start-min;

    //  printf("The difference is %d",difference);
     
     avg=sum/size;
     printf("\n The Average is:%2f",avg);

     
    return 0;
}










