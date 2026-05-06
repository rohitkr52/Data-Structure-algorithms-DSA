// Problem: Left Rotation of Array by K positions
// Topic: Array

#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Description
// ------------------------------------------------------------
// Rotate array to the left by k positions.
//
// Example:
// Input:  [1, 2, 3, 4, 5], k = 2
// Output: [3, 4, 5, 1, 2]

// ------------------------------------------------------------
// Approach 1: Brute Force (Rotate one-by-one k times)
// ------------------------------------------------------------
// Idea:
// Perform left rotation by 1 → k times
//
// Time Complexity: O(n * k)
// Space Complexity: O(1)

void leftRotateByOne(int arr[], int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

void leftRotateBrute(int arr[], int n, int k) {
    k = k % n;  // handle k > n
    for (int i = 0; i < k; i++) {
        leftRotateByOne(arr, n);
    }
}

// ------------------------------------------------------------
// Approach 2: Better (Using Extra Array)
// ------------------------------------------------------------
// Idea:
// Store first k elements, shift rest, then append stored elements
//
// Time Complexity: O(n)
// Space Complexity: O(k)

void leftRotateBetter(int arr[], int n, int k) {
    k = k % n;

    int temp[k];

    // Store first k elements
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    // Shift remaining elements
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    // Put stored elements at end
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

// ------------------------------------------------------------
// Approach 3: Optimal (Reversal Algorithm)
// ------------------------------------------------------------
// Idea:
// 1. Reverse first k elements
// 2. Reverse remaining elements
// 3. Reverse whole array
//
// Time Complexity: O(n)
// Space Complexity: O(1)

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void leftRotateOptimal(int arr[], int n, int k) {
    k = k % n;

    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
    reverseArray(arr, 0, n - 1);
}

// ------------------------------------------------------------
// Utility Function
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
    int arr3[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;

    // Brute
    leftRotateBrute(arr1, n, k);
    cout << "Brute: ";
    printArray(arr1, n);

    // Better
    leftRotateBetter(arr2, n, k);
    cout << "Better: ";
    printArray(arr2, n);

    // Optimal
    leftRotateOptimal(arr3, n, k);
    cout << "Optimal: ";
    printArray(arr3, n);

    return 0;
}
