//  Problem Title: Maximum Product Subarray

/*Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.*/
// What to note from this is that we needed to initialise product to 1 so that 

#include <stdio.h>

int main() {
    int nums[]={1,3,-5,7,-9};
    int maxProduct=nums[0],product;
    int length=sizeof(nums)/sizeof(nums[0]);
    //  printf("%d",length);
        
    for(int i=0;i<length;i++){
        product=1;
    for(int j=i;j<length;j++){
    
          product*=nums[j];
      
       if(product>maxProduct){
           maxProduct=product;
    }
      }
    }
      printf("%d \n",maxProduct);
    
    return 0;
}