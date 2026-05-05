// Problem: Factorial of a Number
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/factorial5739/1
// Difficulty: Easy

// Description:
// Given an integer n, find n! (factorial of n).
// Factorial is defined as: n! = n × (n-1) × ... × 1 :contentReference[oaicite:0]{index=0}

// ------------------------------------------------------------
// Approach 1: Iterative (Recommended)
// ------------------------------------------------------------

// Steps:
// 1. Initialize result = 1
// 2. Loop from 1 to n
// 3. Multiply result with current number
// 4. Return result

// Time Complexity: O(n)
// We iterate from 1 to n once.

// Space Complexity: O(1)

#include <iostream>
using namespace std;

long long factorial(int n) {
    long long result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

// ------------------------------------------------------------
// Approach 2: Recursion (Interview Discussion)
// ------------------------------------------------------------

// Steps:
// 1. Base case: if n == 0 or 1 → return 1
// 2. Return n * factorial(n-1)

// Time Complexity: O(n)
// Space Complexity: O(n) (recursion stack)

long long factorialRecursive(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorialRecursive(n - 1);
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial (Iterative): " << factorial(n) << endl;
    cout << "Factorial (Recursive): " << factorialRecursive(n) << endl;

    return 0;
}
