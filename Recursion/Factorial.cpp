// Problem: Factorial using Recursion
// Difficulty: Easy

// Description:
// n! = n × (n-1) × (n-2) × ... × 1
// Base cases: 0! = 1, 1! = 1

// ------------------------------------------------------------
// Approach: Recursion
// ------------------------------------------------------------

// Steps:
// 1. If n == 0 or n == 1 → return 1 (base case)
// 2. Else return n * factorial(n - 1)

// Time Complexity: O(n)
// Space Complexity: O(n) (recursion stack)

// Dry Run (n = 5):
// factorial(5)
// = 5 * factorial(4)
// = 5 * 4 * factorial(3)
// = 5 * 4 * 3 * factorial(2)
// = 5 * 4 * 3 * 2 * factorial(1)
// = 5 * 4 * 3 * 2 * 1
// = 120

#include <iostream>
using namespace std;

long long factorial(int n) {
    // Base case
    if (n == 0 || n == 1)
        return 1;

    // Recursive call
    return n * factorial(n - 1);
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial: " << factorial(n) << endl;

    return 0;
}
