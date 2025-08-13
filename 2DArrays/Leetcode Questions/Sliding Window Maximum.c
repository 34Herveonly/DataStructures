/*
Leetcode #239 - Sliding Window Maximum
Different twist: focuses on numerical values instead of substrings.

Description:

You are given an array of integers nums, and an integer k. Return the maximum value in every window of size k.

Why it's hard:

You need an efficient data structure (like a deque) to maintain the max in O(n) time.
*/

#include <stdio.h>
#include <stdlib.h>

// ====== Deque Implementation ======
typedef struct {
    int *data;
    int front;
    int rear;
} Deque;

// Create a new deque
Deque* createDeque(int size) {
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(sizeof(int) * size);
    dq->front = 0;
    dq->rear = -1;
    return dq;
}

// Check if deque is empty
int isEmpty(Deque *dq) {
    return dq->front > dq->rear;
}

// Push to back
void pushBack(Deque *dq, int value) {
    dq->rear++;
    dq->data[dq->rear] = value;
}

// Pop from front
void popFront(Deque *dq) {
    dq->front++;
}

// Pop from back
void popBack(Deque *dq) {
    dq->rear--;
}

// Get front element
int front(Deque *dq) {
    return dq->data[dq->front];
}

// Get back element
int back(Deque *dq) {
    return dq->data[dq->rear];
}

// Free deque
void freeDeque(Deque *dq) {
    free(dq->data);
    free(dq);
}

// ====== Sliding Window Max Function ======
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = 0;

    Deque *dq = createDeque(numsSize);

    for (int i = 0; i < numsSize; i++) {
        // Remove indexes that are out of the current window
        if (!isEmpty(dq) && front(dq) <= i - k) {
            popFront(dq);
        }

        // Remove smaller values from the back
        while (!isEmpty(dq) && nums[back(dq)] < nums[i]) {
            popBack(dq);
        }

        // Add current index to the deque
        pushBack(dq, i);

        // Save the max value when the window is full
        if (i >= k - 1) {
            result[*returnSize] = nums[front(dq)];
            (*returnSize)++;
        }
    }

    freeDeque(dq);
    return result;
}

// ====== Main Function ======
int main() {
    int nums[] = {3, 0, 1, 5, 2, 1, 9, 3, 6, 8, 2, 4};
    int k = 3;
    int returnSize;

    int* result = maxSlidingWindow(nums, sizeof(nums)/sizeof(nums[0]), k, &returnSize);

    printf("Sliding window maximums: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // Free memory allocated for result
    return 0;
}
