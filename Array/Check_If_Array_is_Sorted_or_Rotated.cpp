// Problem: Check if Array is Sorted and Rotated
// Topic: Array

#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Description
// ------------------------------------------------------------
// Given an array, check whether it is sorted in non-decreasing order
// and then rotated (possibly 0 times).
//
// Examples:
// [3,4,5,1,2] → TRUE
// [1,2,3,4,5] → TRUE
// [2,1,3,4]   → FALSE

// ------------------------------------------------------------
// Why this problem is interesting?
// ------------------------------------------------------------
// A sorted rotated array has a special property:
// 👉 There is at most ONE point where order breaks.
//
// Example:
// [3,4,5,1,2]
// Only one break → 5 > 1
//
// If breaks > 1 → not valid

// ------------------------------------------------------------
// Approach 1: Brute Force (Try all rotations)
// ------------------------------------------------------------
// Idea:
// Rotate array k times and check if any version becomes sorted.
//
// Time Complexity: O(n^2)
// Space Complexity: O(n)

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

void rotateLeftByOne(int arr[], int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

bool checkBrute(int arr[], int n) {
    int temp[n];

    // Copy original array
    for (int i = 0; i < n; i++) temp[i] = arr[i];

    // Try all rotations
    for (int k = 0; k < n; k++) {
        if (isSorted(temp, n))
            return true;

        rotateLeftByOne(temp, n);
    }

    return false;
}

// ------------------------------------------------------------
// Approach 2: Optimal (Count Violations)
// ------------------------------------------------------------
// Idea:
// Count how many times order breaks (arr[i] > arr[i+1])
// Use circular check for last element.
//
// If count <= 1 → valid
//
// Time Complexity: O(n)
// Space Complexity: O(1)

bool checkOptimal(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;

        if (arr[i] > arr[next]) {
            count++;
        }
    }

    return count <= 1;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int n = 5;

    // Brute
    if (checkBrute(arr, n))
        cout << "Brute: YES\n";
    else
        cout << "Brute: NO\n";

    // Optimal
    if (checkOptimal(arr, n))
        cout << "Optimal: YES\n";
    else
        cout << "Optimal: NO\n";

    return 0;
}
