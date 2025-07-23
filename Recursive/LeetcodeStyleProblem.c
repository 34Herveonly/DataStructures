/* Problem: Subsets (Power Set)
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.*/

#include <stdio.h>

void print(int nums[], int index, int length, int subset[], int subsetSize) {
    // Base case: reached the end of the array
    if (index == length) {
        // Print current subset
        printf("{ ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    // Case 1: Include current element
    subset[subsetSize] = nums[index];
    print(nums, index + 1, length, subset, subsetSize + 1);

    // Case 2: Exclude current element
    print(nums, index + 1, length, subset, subsetSize);
}

int main() {    
    int nums[] = {1, 3, 4, 6, 8, 10};
    int length = sizeof(nums) / sizeof(nums[0]);
    int subset[50]; // temp array to build subsets

    print(nums, 0, length, subset, 0);

    return 0;
}

/*
// Going to make a revision about this leetcode kinda question of printing out all of the possible sub-arrays from our array 

# include <stdio.h>

void print(int arr[],int index,int subset[],int length,int subsetSize){

    if(index==length){
        printf(" { ");
        for(int i=0;i<subsetSize;i++){
            printf("%d ",subset[i]);
        }
            printf(" } \n");
            return;
    }
        subset[subsetSize]=arr[index];
        print(arr,index+1,subset,length,subsetSize+1);
        
        // Then backtrack the subsetSize
        print(arr,index+1,subset,length,subsetSize);
   
}
    int main(){
     int arr[]={1,3,4,6,7,8};
     int length=sizeof(arr)/sizeof(arr[0]);
     int subset[50];
     int index;
     
     print(arr,0,subset,length,0);    
    }

*/ 