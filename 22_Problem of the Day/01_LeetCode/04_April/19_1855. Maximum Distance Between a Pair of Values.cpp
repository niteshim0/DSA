// LC 1855. Maximum Distance Between a Pair of Values
// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
// Concept :: Two Pointers
//Utilizing two pointers on sorted arrays to find maximum distance under constraints.


class Solution {
public:                                                                  
    int maxDistance(vector<int>& A, vector<int>& B) {
    int i = 0, j = 0; // initialize both pointers at the 0th index.

    while (i < A.size() && j < B.size()) {
        // If invalid:
        // move i right to restore a valid pair.
        if (A[i] > B[j])
            i++;

        // Move j right to maximize j - i.
        j++;
    }

    // j - i is the farthest gap reached so far;
    // subtract 1 since j is one step past it.
    return max(0, j - i - 1); // Distance cannot be negative.
}
};