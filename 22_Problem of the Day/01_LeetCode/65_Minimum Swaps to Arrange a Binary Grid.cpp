// LC 1536. Minimum Swaps to Arrange a Binary Grid
// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/
// Concepts :: Greedy + Strategy + Simple Maths + Simulation

// Intuition
// In a valid grid:

// Row 0 must have ≥ n-1 trailing zeros
// Row 1 must have ≥ n-2 trailing zeros
// Row 2 must have ≥ n-3 trailing zeros
// ...
// Row i must have ≥ n-i-1 trailing zeros
// Because all elements above the main diagonal must be 0.
// So the task becomes:

// "Bring a row with enough trailing zeros to position i using minimum adjacent swaps".

// Strategy (Greedy)
// Count trailing zeros in every row.
// For position i:
// Required zeros = n - i - 1
// Find the nearest row j ≥ i with enough zeros.
// If none exists → return -1
// Bring that row to position i using adjacent swaps
// (cost = j - i)
// We simulate swaps by shifting the array.




class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeroSuffixCount(n,0);

        for(int i = 0;i<n;i++){
            for(int j = n-1;j>0 && grid[i][j] == 0 ; j--){
                zeroSuffixCount[i]++;
            }
        }

        int ans = 0;

        for(int i = 0;i<n;i++){
            // finding the valid row to swap with row i
            int j = i;
            while(j<n && zeroSuffixCount[j] < (n-i-1)){
                j++;
            }

            if(j == n) return -1 ;// no valid row to replace

            ans+=(j-i);

            // simulating the row swaps
            while(j>i){
                swap(zeroSuffixCount[j],zeroSuffixCount[j-1]);
                j--;
            }
        }

        return ans;
    }
};

// Time Complexity : O(N*N) // suffix + O(2*N*N) = O(N*N) // findinin small j and simulating swap
// Space Complexity : O(N)