// Problem: Prime Number
// Platform: GeeksforGeeks
// Link: https://www.geeksforgeeks.org/problems/prime-number2314/1
// Difficulty: Easy

// Description:
// Check whether a given number n is prime.
// A prime number has only 2 divisors: 1 and itself.

// ------------------------------------------------------------
// Approach 1: Brute Force
// ------------------------------------------------------------

// Steps:
// 1. If n <= 1 → not prime
// 2. Loop from i = 2 to n-1
// 3. If n % i == 0 → not prime
// 4. If no divisor found → prime

// Time Complexity: O(n)
// We check all numbers from 2 to n-1

// Space Complexity: O(1)

#include <iostream>
using namespace std;

bool isPrimeBrute(int n) {
    if (n <= 1) return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// ------------------------------------------------------------
// Approach 2: Optimized (Check till √n)
// ------------------------------------------------------------

// Key Idea:
// If n = a × b, then one of the factors must be ≤ √n

// Steps:
// 1. If n <= 1 → not prime
// 2. Loop from i = 2 to sqrt(n)
// 3. If n % i == 0 → not prime
// 4. Else → prime

// Time Complexity: O(√n)
// We reduce iterations from n to √n
//For example, for n = 36, √36 = 6 ,After 6, factor pairs repeat (like 4×9 and 9×4), so checking beyond √n is redundant.

// Space Complexity: O(1)

bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Brute Result: ";
    if (isPrimeBrute(n))
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;

    cout << "Optimized Result: ";
    if (isPrime(n))
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;

    return 0;
}
