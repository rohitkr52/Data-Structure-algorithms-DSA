/**
 * Problem: Tower of Hanoi
 * Description:
 * Move n disks from source rod to destination rod using an auxiliary rod.
 * Only one disk can be moved at a time and a larger disk cannot be placed on a smaller disk.
 *
 * Approach:
 * 1. Move (n-1) disks from source → auxiliary
 * 2. Move nth disk from source → destination
 * 3. Move (n-1) disks from auxiliary → destination
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) (recursion stack)
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // Base case
        if (n == 0) return 0;

        int moves = 0;

        // Step 1: Move n-1 disks to auxiliary
        moves += towerOfHanoi(n - 1, from, aux, to);

        // Step 2: Move nth disk
        cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
        moves++;

        // Step 3: Move n-1 disks to destination
        moves += towerOfHanoi(n - 1, aux, to, from);

        return moves;
    }
};

int main() {
    Solution obj;
    int n = 3;

    int totalMoves = obj.towerOfHanoi(n, 1, 3, 2);
    cout << "Total moves: " << totalMoves << endl;

    return 0;
}
