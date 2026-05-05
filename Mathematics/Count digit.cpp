// Problem: Count the Digits That Divide a Number
// Platform: LeetCode
// Link: https://leetcode.com/problems/count-the-digits-that-divide-a-number/
// Difficulty: Easy

// Approach:
// 1. Store the original number
// 2. Extract each digit using modulo (num % 10)
// 3. Check if digit is non-zero and divides the original number
// 4. If yes, increment count
// 5. Remove the last digit (num = num / 10)
// 6. Repeat until number becomes 0

// Time Complexity: O(log n)
// Each iteration removes one digit (n → n/10), so loop runs equal to number of digits.

// Space Complexity: O(1)

#include <iostream>
using namespace std;

int countDigits(int num) {
    int count = 0;
    int original = num;

    while (num != 0) {
        int rem = num % 10;

        if (rem != 0 && original % rem == 0) {
            count++;
        }

        num /= 10;
    }

    return count;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int result = countDigits(num);

    cout << "Count of digits that divide the number: " << result << endl;

    return 0;
}
