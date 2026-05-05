// Problem: Pow(x, n)
// Platform: LeetCode
// Link: https://leetcode.com/problems/powx-n/
// Difficulty: Medium

// Description:
// Implement pow(x, n), which calculates x raised to the power n.

// ------------------------------------------------------------
// Approach 1: Brute Force
// ------------------------------------------------------------

// Steps:
// 1. Multiply x with itself n times
// 2. If n is negative → take reciprocal

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

double myPowBrute(double x, int n) {
    long long N = n;
    double result = 1;

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    for (long long i = 0; i < N; i++) {
        result *= x;
    }

    return result;
}

// ------------------------------------------------------------
// Approach 2: Optimized (Binary Exponentiation)
// ------------------------------------------------------------

// Key Idea:
// Reduce exponent by half each time

// Steps:
// 1. If n is negative → convert to positive and take reciprocal
// instead of x × x × x × x × x × x ... , I am using 
//x^n = (x^(n/2))^2   if n is even
//x^n = x * (x^(n/2))^2   if n is odd : This (even & odd) reduces problem size by half each step.
// 2. While n > 0:
//      - If n is odd → multiply result by x
//      - Square x
//      - Divide n by 2

// Time Complexity: O(log n)
// Each step halves n

// Space Complexity: O(1)

double myPow(double x, int n) {
    long long N = n;
    double result = 1;

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    while (N > 0) {
        if (N % 2 == 1) {
            result *= x;
        }
        x *= x;
        N /= 2;
    }

    return result;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    double x;
    int n;

    cout << "Enter x and n: ";
    cin >> x >> n;

    cout << "Brute Result: " << myPowBrute(x, n) << endl;
    cout << "Optimized Result: " << myPow(x, n) << endl;

    return 0;
}
