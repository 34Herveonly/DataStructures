/*
Leetcode #42 - Trapping Rain Water
Different twist: Simulates physical intuition using two pointers and pre-processing.

Description:

Given n non-negative integers representing an elevation map, compute how much water it can trap after raining.

Why it's hard:

Needs careful use of two pointers or precomputed max arrays to achieve O(n) time and O(1)/O(n) space.
*/

#include <stdio.h>

// Function to compute the trapped rainwater
int trap(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int left_max = 0, right_max = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                water += left_max - height[left];
            }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                water += right_max - height[right];
            }
            right--;
        }
    }

    return water;
}

// Helper function to run test case
void runTest(int* height, int size) {
    int result = trap(height, size);
    printf("Trapped water: %d\n", result);
}

// Main function to test the code
int main() {
    int height1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size1 = sizeof(height1) / sizeof(height1[0]);

    runTest(height1, size1);

    // Add more test cases if needed
    int height2[] = {4,2,0,3,2,5};
    int size2 = sizeof(height2) / sizeof(height2[0]);
    runTest(height2, size2);

    return 0;
}
