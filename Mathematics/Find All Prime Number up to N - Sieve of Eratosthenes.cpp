// Problem: Print all prime numbers up to n
// Topic: Prime Numbers

// ------------------------------------------------------------
// Approach 1: Brute Force (Check each number)
// ------------------------------------------------------------

// Steps:
// 1. For each number from 2 to n
// 2. Check if it is prime by dividing from 2 to num-1
// 3. If no divisor found → print it

// Time Complexity: O(n^2)
// For each number, we check all numbers before it

// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

bool isPrimeBrute(int num) {
    if (num <= 1) return false;

    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void printPrimesBrute(int n) {
    cout << "Brute Force Primes: ";
    for (int i = 2; i <= n; i++) {
        if (isPrimeBrute(i))
            cout << i << " ";
    }
    cout << endl;
}

// ------------------------------------------------------------
// Approach 2: Optimized (Sieve of Eratosthenes)
// ------------------------------------------------------------

// Steps:
// 1. Create array isPrime[0..n] = true
// 2. Mark 0 and 1 as false
// 3. For i = 2 to sqrt(n):
//      if isPrime[i]:
//          mark multiples of i from i*i to n as false
// 4. Print all i where isPrime[i] == true

// Time Complexity: O(n log log n)
// Much faster than brute force

// Space Complexity: O(n)

void sieve(int n) {
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    cout << "Sieve Primes: ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            cout << i << " ";
    }
    cout << endl;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    printPrimesBrute(n);
    sieve(n);

    return 0;
}
