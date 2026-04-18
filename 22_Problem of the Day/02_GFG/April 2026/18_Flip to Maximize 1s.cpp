// Flip to Maximize 1s
// https://www.geeksforgeeks.org/problems/flip-bits0240/1

// Concept :: Kadane's Algorithm

// Flip the subarray that gives maximum gain of converting 0s to 1s while minimizing loss of 1s


class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int totalOnes = 0;

        // Count original 1s
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }

        // Kadane's algorithm on transformed array
        int curr = 0, best = 0;

        for (int x : arr) {
            int val = (x == 0) ? 1 : -1;

            curr = max(val, curr + val);
            best = max(best, curr);
        }

        return totalOnes + best;
    }
};


// Time Complexity : O(N)
// Space Complexity : O(1)
