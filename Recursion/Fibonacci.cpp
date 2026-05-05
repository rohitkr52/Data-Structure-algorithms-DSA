// Problem: Nth Fibonacci Number
// Difficulty: Easy

// Fibonacci Series:
// F(0) = 0
// F(1) = 1
// F(n) = F(n-1) + F(n-2)

// ------------------------------------------------------------
// Approach 1: Recursion (Brute Force)
// ------------------------------------------------------------

// Steps:
// 1. Base case: n == 0 → 0, n == 1 → 1
// 2. Return fib(n-1) + fib(n-2)

// Time Complexity: O(2^n)
// Space Complexity: O(n)

// Dry Run (n = 5):
// fib(5)
// = fib(4) + fib(3)
// = (fib(3)+fib(2)) + (fib(2)+fib(1))
// = ... → repeated calls

#include <iostream>
using namespace std;

int fibRecursive(int n) {
    if (n <= 1)
        return n;

    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// ------------------------------------------------------------
// Approach 2: Iterative (Optimized)
// ------------------------------------------------------------

// Steps:
// 1. Initialize a = 0, b = 1
// 2. Loop from 2 to n
// 3. c = a + b
// 4. Update a = b, b = c

// Time Complexity: O(n)
// Space Complexity: O(1)

// Dry Run (n = 5):
// a=0, b=1
// i=2 → c=1 → a=1, b=1
// i=3 → c=2 → a=1, b=2
// i=4 → c=3 → a=2, b=3
// i=5 → c=5 → a=3, b=5

int fibIterative(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1;

    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Recursive: " << fibRecursive(n) << endl;
    cout << "Iterative: " << fibIterative(n) << endl;

    return 0;
}
