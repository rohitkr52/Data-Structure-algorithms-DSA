// Problem: Rod Cutting (Using Recursion)
// Topic: Recursion

// Description:
// Given a rod of length n and price array,
// find maximum profit by cutting the rod.

// Example:
// n = 4
// price = [2,5,7,8]

// ------------------------------------------------------------
// Approach: Recursion (Brute Force)
// ------------------------------------------------------------

// Steps:
// 1. If length = 0 → return 0
// 2. Try all possible cuts (1 to n)
// 3. Take maximum profit

// Time Complexity: Exponential (O(2^n))
// Space Complexity: O(n) (recursion stack)

// Dry Run (n = 4):
// rodCut(4)
// = max(
//   2 + rodCut(3),
//   5 + rodCut(2),
//   7 + rodCut(1),
//   8 + rodCut(0)
// )

// rodCut(3)
// = max(2 + rodCut(2), 5 + rodCut(1), 7 + rodCut(0))

#include <iostream>
#include <vector>
using namespace std;

int rodCut(int n, vector<int>& price) {
    // Base case
    if (n == 0)
        return 0;

    int maxProfit = 0;

    // Try all possible cuts
    for (int i = 0; i < n; i++) {
        int current = price[i] + rodCut(n - i - 1, price);
        maxProfit = max(maxProfit, current);
    }

    return maxProfit;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    vector<int> price = {2, 5, 7, 8};
    int n = price.size();

    cout << "Maximum Profit: " << rodCut(n, price) << endl;

    return 0;
}
