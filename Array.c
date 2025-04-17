// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int a[50],size,sum,i,j;
    printf("Enter the size of array");
    scanf("%d",&size);
    printf("Enter the values:");
    for(i=0;i<size;i++){
    scanf("%d",&a[i]);
    }
    for(i=0;i<size;i++){
    printf("%d",a[i]);
    printf("\n");
    }
    printf("Checking sum");
    for(i=0;i<size;i++){
     for(j=i+1;j<size;j++){
         sum=a[i]+a[j];
         if(sum==9){
             printf("\n");
             printf("%d %d",i,j);
            //  printf(a[i],a[j]);
         }
     }   
    }
    return 0;
}