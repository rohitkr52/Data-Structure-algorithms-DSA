// Problem: Add Digits (LeetCode 258)
// Difficulty: Easy

// Description:
// Repeatedly add digits until the number becomes a single digit.

// Example:
// num = 38
// → 3 + 8 = 11
// → 1 + 1 = 2 → answer

#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Approach 1: Simulation (Loop)
// ------------------------------------------------------------

// Steps:
// 1. While num >= 10
// 2. Extract digits using %10
// 3. Add them and form new number
// 4. Repeat

// Time Complexity: O(log n)
// Space Complexity: O(1)

// Dry Run (num = 38):
// Step 1: 38 → sum = 3+8 = 11
// Step 2: 11 → sum = 1+1 = 2
// Step 3: 2 → stop

int addDigits(int num) {
    while (num >= 10) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        num = sum;
    }

    return num;
}

// ------------------------------------------------------------
// Approach 2: Optimized (Digital Root)
// ------------------------------------------------------------

// Key Idea:
// Digital Root Formula
// Repeat operation on digits until one digit remains

// If num == 0 → return 0
// else → return 1 + (num - 1) % 9

// Time Complexity: O(1)
// Space Complexity: O(1)

// Dry Run (num = 38):
// 1 + (38 - 1) % 9
// = 1 + 37 % 9
// = 1 + 1 = 2

int addDigitsOptimized(int num) {
    if (num == 0) return 0;
    return 1 + (num - 1) % 9;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int num;

    cout << "Enter number: ";
    cin >> num;

    cout << "Simulation: " << addDigits(num) << endl;
    cout << "Optimized: " << addDigitsOptimized(num) << endl;

    return 0;
}
