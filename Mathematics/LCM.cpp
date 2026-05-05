// Problem: LCM of Two Numbers
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/lcm-of-two-numbers/1
// Difficulty: Easy

// Description:
// Given two integers a and b, find their LCM (Least Common Multiple).
// LCM is the smallest number divisible by both numbers. :contentReference[oaicite:0]{index=0}

// ------------------------------------------------------------
// Approach 1: Using GCD (Optimized - Recommended)
// ------------------------------------------------------------

// Key Formula:
// LCM(a, b) = (a * b) / GCD(a, b) :contentReference[oaicite:1]{index=1}

// Steps:
// 1. Compute GCD using Euclidean Algorithm
// 2. Apply formula: (a * b) / gcd
// 3. Return result

// Time Complexity: O(log(min(a, b)))  (due to GCD)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

// Function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// ------------------------------------------------------------
// Approach 2: Brute Force (Interview discussion)
// ------------------------------------------------------------

// Steps:
// 1. Start from max(a, b)
// 2. Check each number until divisible by both
// 3. Return first such number

// Time Complexity: O(max(a, b))
// Space Complexity: O(1)

int lcmBrute(int a, int b) {
    int maxVal = max(a, b);

    while (true) {
        if (maxVal % a == 0 && maxVal % b == 0) {
            return maxVal;
        }
        maxVal++;
    }
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "LCM (Optimized): " << lcm(a, b) << endl;
    cout << "LCM (Brute): " << lcmBrute(a, b) << endl;

    return 0;
}
