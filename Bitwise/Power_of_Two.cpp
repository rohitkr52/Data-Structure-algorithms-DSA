// Problem: Check if a number is Power of 2
// Platform: LeetCode / GFG
// Difficulty: Easy

// Description:
// A number is a power of 2 if it has exactly one set bit in binary.

// ------------------------------------------------------------
// Approach 1: Brute Force (Divide by 2)
// ------------------------------------------------------------

// Steps:
// 1. If n <= 0 → return false
// 2. Keep dividing n by 2
// 3. If at any step n % 2 != 0 → not power of 2
// 4. If n becomes 1 → power of 2

// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

bool isPowerOfTwoBrute(int n) {
    if (n <= 0) return false;

    while (n % 2 == 0) {
        n = n / 2;
    }

    return n == 1;
}

// ------------------------------------------------------------
// Approach 2: Optimized (Bit Manipulation)
// ------------------------------------------------------------

// Key Idea:
// Power of 2 numbers have exactly one set bit

// Trick:
// n & (n - 1) removes the lowest set bit

// What it does:
// If n has only one set bit → result becomes 0
// If n has more than one set bit → result ≠ 0

// Dry Run 1:
// n = 8 → 1000
// n-1 = 7 → 0111
// 1000 & 0111 = 0000 → TRUE (power of 2)

// Dry Run 2:
// n = 6 → 110
// n-1 = 5 → 101
// 110 & 101 = 100 → NOT 0 → FALSE

// Time Complexity: O(1)
// Space Complexity: O(1)

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int n;

    cout << "Enter number: ";
    cin >> n;

    cout << "Brute Result: ";
    cout << (isPowerOfTwoBrute(n) ? "YES" : "NO") << endl;

    cout << "Optimized Result: ";
    cout << (isPowerOfTwo(n) ? "YES" : "NO") << endl;

    return 0;
}
