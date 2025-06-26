// "Write a function to calculate the nth Fibonacci number recursively."
// This program calculates the nth Fibonacci number using recursion.

#include <stdio.h>

// Recursive function to compute the nth Fibonacci number
int fib(int n) {
    // Base Case 1: If n is 0, return 0
    if(n == 0) return 0;

    // Base Case 2: If n is 1, return 1
    if(n == 1) return 1;

    // Recursive Case:
    // Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
    // This function calls itself with smaller values until it hits the base cases
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 10; // We want to find the 10th Fibonacci number

    // Call the recursive fib() function and print the result
    // This will print the 10th Fibonacci number (which is 55)
    printf("%d", fib(n));

    return 0; // Indicate successful program termination
}
