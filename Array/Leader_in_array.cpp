// Problem: Leaders in Array
// Topic: Array

#include <iostream>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// Description
// ------------------------------------------------------------
// An element is called a "leader" if it is greater than or equal
// to all elements to its right.
//
// The rightmost element is always a leader.
//
// Example:
// Input:  [16, 17, 4, 3, 5, 2]
// Output: [17, 5, 2]

// ------------------------------------------------------------
// Why this problem?
// ------------------------------------------------------------
// It tests:
// - Traversal thinking
// - Optimization from O(n^2) → O(n)
// - Right-to-left intuition (very important)

// ------------------------------------------------------------
// Approach 1: Brute Force
// ------------------------------------------------------------
// Idea:
// For each element, check all elements to its right.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1) (excluding output)

vector<int> leadersBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        bool isLeader = true;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                isLeader = false;
                break;
            }
        }

        if (isLeader) {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

// ------------------------------------------------------------
// Approach 2: Optimal (Right-to-Left Traversal)
// ------------------------------------------------------------
// Idea:
// Traverse from right and keep track of max so far.
//
// If current >= max → leader
//
// Time Complexity: O(n)
// Space Complexity: O(n) (for result)

vector<int> leadersOptimal(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;

    int maxRight = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            ans.push_back(arr[i]);
            maxRight = arr[i];
        }
    }

    // Reverse to maintain order
    reverse(ans.begin(), ans.end());

    return ans;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};

    // Brute
    vector<int> brute = leadersBrute(arr);
    cout << "Brute: ";
    for (int x : brute) cout << x << " ";
    cout << endl;

    // Optimal
    vector<int> opt = leadersOptimal(arr);
    cout << "Optimal: ";
    for (int x : opt) cout << x << " ";
    cout << endl;

    return 0;
}
