// Problem: Palindrome Number
// Platform: LeetCode
// Link: https://leetcode.com/problems/palindrome-number/
// Difficulty: Easy

// Approach:
// 1. If number is negative, return false (not palindrome)
// 2. Store original number
// 3. Reverse the number using modulo and division
// 4. Compare reversed number with original
// 5. Return true if equal, else false

// Time Complexity: O(log n)
// Each iteration removes one digit (n → n/10), so loop runs equal to number of digits.

// Space Complexity: O(1)

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;

    int original = x;
    long long reversed = 0;

    while (x != 0) {
        int rem = x % 10;
        reversed = reversed * 10 + rem;
        x /= 10;
    }

    return original == reversed;
}

int main() {
    int x;

    cout << "Enter a number: ";
    cin >> x;

    if (isPalindrome(x)) {
        cout << "True (Palindrome)" << endl;
    } else {
        cout << "False (Not Palindrome)" << endl;
    }

    return 0;
}
