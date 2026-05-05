// Problem: Generate Power Set using Bit Manipulation
// Topic: Bit Manipulation

#include <iostream>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// Approach: Bit Masking
// ------------------------------------------------------------

// Steps:
// 1. Total subsets = 2^n
// 2. Loop from 0 to (2^n - 1)
// 3. For each number, check bits
// 4. If j-th bit is set → include arr[j]

// Time Complexity: O(n * 2^n)
// Space Complexity: O(1) (excluding output)

// Dry Run:
// arr = [1,2,3], n = 3 → total = 8

// i = 0 → 000 → {}
// i = 1 → 001 → {1}
// i = 2 → 010 → {2}
// i = 3 → 011 → {1,2}
// i = 4 → 100 → {3}
// i = 5 → 101 → {1,3}
// i = 6 → 110 → {2,3}
// i = 7 → 111 → {1,2,3}

void powerSet(vector<int>& arr) {
    int n = arr.size();
    int total = 1 << n;  // 2^n

    for (int i = 0; i < total; i++) {
        cout << "{ ";

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }

        cout << "}" << endl;
    }
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    vector<int> arr = {1, 2, 3};

    powerSet(arr);

    return 0;
}
