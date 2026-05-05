// Problem: Check if K-th bit is set or not
// Platform: GFG / LeetCode style
// Difficulty: Easy

// Description:
// Given a number n and an integer k, check whether the k-th bit (0-based index)
// in the binary representation of n is set (1) or not.

// ------------------------------------------------------------
// Approach 1: Brute Force (Using Division)
// ------------------------------------------------------------

// Steps:
// 1. Divide number by 2, k times (right shift manually)
// 2. Check last bit using (n % 2)
// 3. If 1 → bit is set, else not

// Time Complexity: O(k)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

bool isKthBitSetBrute(int n, int k) {
    for (int i = 0; i < k; i++) {
        n = n / 2;
    }
    return (n % 2 == 1);
}

// ------------------------------------------------------------
// Approach 2: Optimized (Bit Manipulation)
// ------------------------------------------------------------

// Key Idea:
// Shift 1 to k-th position → (1 << k)
// Perform AND with n
// If result != 0 → bit is set

// Time Complexity: O(1)
// Space Complexity: O(1)

bool isKthBitSet(int n, int k) {
    return (n & (1 << k)) != 0;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int n, k;

    cout << "Enter number and k: ";
    cin >> n >> k;

    cout << "Brute Result: ";
    if (isKthBitSetBrute(n, k))
        cout << "SET" << endl;
    else
        cout << "NOT SET" << endl;

    cout << "Optimized Result: ";
    if (isKthBitSet(n, k))
        cout << "SET" << endl;
    else
        cout << "NOT SET" << endl;

    return 0;
}
