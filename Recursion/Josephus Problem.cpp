// Problem: Josephus Problem
// Topic: Recursion

#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Description
// ------------------------------------------------------------
// There are 'n' people standing in a circle.
// Every k-th person is eliminated in a circular manner.
// Find the position of the last remaining (safe position).
//
// Example:
// n = 5, k = 2
// Elimination order: 2 → 4 → 1 → 5
// Safe position = 3

// ------------------------------------------------------------
// Why this approach (Recursion)?
// ------------------------------------------------------------
// The problem reduces in size after each elimination.
//
// If we know the safe position for (n-1) people,
// we can build the answer for n people.
//
// Key idea:
// After removing one person, the circle shifts,
// so we adjust the index using modulo arithmetic.

// ------------------------------------------------------------
// Approach: Recursive (Optimized)
// ------------------------------------------------------------

// Recurrence Relation:
// f(n, k) = (f(n-1, k) + k) % n

// Base Case:
// f(1, k) = 0   (0-based indexing)

// Convert to 1-based answer:
// answer = f(n, k) + 1

// Time Complexity: O(n)
// Space Complexity: O(n)

// ------------------------------------------------------------
// Dry Run (n = 5, k = 2)
// ------------------------------------------------------------
// f(1) = 0
// f(2) = (0 + 2) % 2 = 0
// f(3) = (0 + 2) % 3 = 2
// f(4) = (2 + 2) % 4 = 0
// f(5) = (0 + 2) % 5 = 2
//
// Answer = 2 + 1 = 3

int josephus(int n, int k) {
    // Base case
    if (n == 1)
        return 0;

    return (josephus(n - 1, k) + k) % n;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int n = 5, k = 2;

    int result = josephus(n, k) + 1;

    cout << "Safe Position: " << result << endl;

    return 0;
}
