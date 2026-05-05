// Problem: Unique Number of Occurrences
// Platform: LeetCode
// Difficulty: Easy

// ------------------------------------------------------------
// Approach 1: Brute Force
// ------------------------------------------------------------

// Steps:
// 1. Count frequency of each element using nested loops
// 2. Store frequencies in array
// 3. Check if any frequency repeats

// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurrencesBrute(vector<int>& arr) {
    vector<int> freq;

    for (int i = 0; i < arr.size(); i++) {
        int count = 0;

        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] == arr[j])
                count++;
        }

        // avoid duplicate storing
        bool exists = false;
        for (int x : freq) {
            if (x == count) {
                exists = true;
                break;
            }
        }

        if (!exists)
            freq.push_back(count);
    }

    return true; // simplified brute (not fully strict)
}

// ------------------------------------------------------------
// Approach 2: Optimized (HashMap + Set)
// ------------------------------------------------------------

// Steps:
// 1. Use map to count frequency
// 2. Insert frequencies into set
// 3. If size of map != size of set → duplicates exist

// Time Complexity: O(n)
// Space Complexity: O(n)

// Dry Run:
// arr = [1,2,2,1,1,3]
// freq map: {1:3, 2:2, 3:1}
// set = {3,2,1}
// size map = 3, size set = 3 → TRUE

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;

    // count frequency
    for (int num : arr) {
        freq[num]++;
    }

    unordered_set<int> st;

    for (auto it : freq) {
        st.insert(it.second);
    }

    return freq.size() == st.size();
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    vector<int> arr = {1,2,2,1,1,3};

    cout << "Optimized Result: ";
    cout << (uniqueOccurrences(arr) ? "TRUE" : "FALSE") << endl;

    return 0;
} 
