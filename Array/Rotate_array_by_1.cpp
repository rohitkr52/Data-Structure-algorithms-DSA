// Problem: Left Rotation of Array by 1
// Topic: Array

#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Description
// ------------------------------------------------------------
// Given an array, rotate it to the left by 1 position.
//
// Example:
// Input:  [1, 2, 3, 4, 5]
// Output: [2, 3, 4, 5, 1]

// ------------------------------------------------------------
// Approach 1: Brute Force (Using Extra Array)
// ------------------------------------------------------------
// Idea:
// Create a new array and shift elements accordingly.
//
// Steps:
// 1. Copy elements from index 1 → n-1
// 2. Put first element at the end
//
// Time Complexity: O(n)
// Space Complexity: O(n)

void leftRotateBrute(int arr[], int n) {
    int temp[n];

    // Shift elements
    for (int i = 1; i < n; i++) {
        temp[i - 1] = arr[i];
    }

    // Last element
    temp[n - 1] = arr[0];

    // Copy back
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

// ------------------------------------------------------------
// Approach 2: Optimal (In-place)
// ------------------------------------------------------------
// Idea:
// Avoid extra space by storing first element temporarily.
//
// Steps:
// 1. Store arr[0]
// 2. Shift all elements left
// 3. Put stored value at end
//
// Time Complexity: O(n)
// Space Complexity: O(1)

void leftRotateOptimal(int arr[], int n) {
    int temp = arr[0];

    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;
}

// ------------------------------------------------------------
// Utility Function to Print Array
// ------------------------------------------------------------

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int n = 5;

    // Brute
    leftRotateBrute(arr1, n);
    cout << "Brute: ";
    printArray(arr1, n);

    // Optimal
    leftRotateOptimal(arr2, n);
    cout << "Optimal: ";
    printArray(arr2, n);

    return 0;
}
