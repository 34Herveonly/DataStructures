// This is a dynamic programming exercises from leetcode namely LeetCode 322: Coin Change Question 

#include <stdio.h>
#include <limits.h> // For INT_MAX

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int denominations[] = {1, 4, 5};  // Example coin denominations
    int n = sizeof(denominations) / sizeof(denominations[0]);
    int sum;

    printf("Enter the sum: ");
    scanf("%d", &sum);

    if (sum < 0) {
        printf("Invalid sum\n");
        return 0;
    }

    int dp[sum + 1];  // dp[i] = minimum coins needed for amount i
    dp[0] = 0;        // Base case: 0 coins to make 0 amount

    for (int i = 1; i <= sum; i++) {
        dp[i] = INT_MAX;  // Initialize with a large number
        for (int j = 0; j < n; j++) {
            if (i - denominations[j] >= 0 && dp[i - denominations[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - denominations[j]] + 1);
            }
        }
    }

    if (dp[sum] == INT_MAX) {
        printf("Cannot make sum %d with given coins.\n", sum);
    } else {
        printf("Minimum coins needed for sum %d: %d\n", sum, dp[sum]);
    }

    return 0;
}
