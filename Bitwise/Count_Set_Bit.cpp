// Problem: Count Set Bits (Number of 1s in binary)
// Topic: Bit Manipulation

// Example for Dry Run:
// n = 13 → binary = 1101 → answer = 3

// ------------------------------------------------------------
// Method 1: Simple Method (Right Shift)
// ------------------------------------------------------------

// Steps:
// 1. While n > 0
// 2. Check last bit using (n & 1)
// 3. Increment count if 1
// 4. Right shift n

// Dry Run (n = 13 → 1101):
// Step 1: n = 1101 → (n & 1) = 1 → count = 1
// Step 2: n = 0110 → (n & 1) = 0 → count = 1
// Step 3: n = 0011 → (n & 1) = 1 → count = 2
// Step 4: n = 0001 → (n & 1) = 1 → count = 3
// Step 5: n = 0000 → stop

// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int countBitsSimple(int n) {
    int count = 0;

    while (n > 0) {
        if (n & 1)
            count++;
        n = n >> 1;
    }

    return count;
}

// ------------------------------------------------------------
// Method 2: Brian Kernighan’s Algorithm (Optimized)
// ------------------------------------------------------------

// Key Idea:
// n & (n - 1) removes the last set bit

// Dry Run (n = 13 → 1101):
// Step 1: 1101 & 1100 = 1100 → count = 1
// Step 2: 1100 & 1011 = 1000 → count = 2
// Step 3: 1000 & 0111 = 0000 → count = 3
// Stop

// Time Complexity: O(number of set bits)
// Space Complexity: O(1)

int countBitsKernighan(int n) {
    int count = 0;

    while (n > 0) {
        n = n & (n - 1);
        count++;
    }

    return count;
}

// ------------------------------------------------------------
// Method 3: Lookup Table (Fastest for multiple queries)
// ------------------------------------------------------------

// Idea:
// Break number into 4 bytes (8 bits each)
// Use precomputed table

// Dry Run (n = 13 → binary: 00000000 00000000 00000000 00001101):
// Byte 1: n & 0xff → 13 → table[13] = 3
// Byte 2: (n >> 8)  → 0 → table[0] = 0
// Byte 3: (n >> 16) → 0 → table[0] = 0
// Byte 4: (n >> 24) → 0 → table[0] = 0
// Total = 3 + 0 + 0 + 0 = 3

int table[256];

// Precompute table
void initialize() {
    table[0] = 0;
    for (int i = 1; i < 256; i++) {
        table[i] = (i & 1) + table[i / 2];
    }
}

int countBitsLookup(int n) {
    return table[n & 0xff] +
           table[(n >> 8) & 0xff] +
           table[(n >> 16) & 0xff] +
           table[(n >> 24) & 0xff];
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int n;

    cout << "Enter number: ";
    cin >> n;

    initialize();

    cout << "Simple Method: " << countBitsSimple(n) << endl;
    cout << "Kernighan Method: " << countBitsKernighan(n) << endl;
    cout << "Lookup Table Method: " << countBitsLookup(n) << endl;

    return 0;
}
