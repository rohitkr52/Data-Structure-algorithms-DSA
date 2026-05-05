// Problem: GCD of Two Numbers
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1
// Difficulty: Basic

// Description:
// Given two numbers a and b, find their GCD (Greatest Common Divisor).
// GCD is the largest number that divides both numbers. :contentReference[oaicite:0]{index=0}

// ------------------------------------------------------------
// Approach 1: Euclidean Algorithm (Optimized)
// ------------------------------------------------------------

// Steps:
// 1. While b is not 0
// 2. Replace a with b
// 3. Replace b with (a % b)
// 4. Repeat until b becomes 0
// 5. Return a as GCD

// Key Idea:
// gcd(a, b) = gcd(b, a % b) :contentReference[oaicite:1]{index=1}

// Time Complexity: O(log(min(a, b)))
// Each step reduces the problem size using modulo.

// Space Complexity: O(1)

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ------------------------------------------------------------
// Approach 2: Recursive Euclidean (Interview)
// ------------------------------------------------------------

int gcdRecursive(int a, int b) {
    if (b == 0) return a;
    return gcdRecursive(b, a % b);
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD (Iterative): " << gcd(a, b) << endl;
    cout << "GCD (Recursive): " << gcdRecursive(a, b) << endl;

    return 0;
}
