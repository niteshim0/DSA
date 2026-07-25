// Maximum Sum Square Sub-Matrix of Size k
// Problem Statement:
/*Given a matrix mat of size n × m and an integer k, find the maximum sum among all possible k × k submatrices.

Topic: 2D Prefix Sum

Approach

A brute-force approach would calculate the sum of every k × k submatrix separately.
Number of possible submatrices: (n-k+1) × (m-k+1)
Sum of each submatrix: O(k²)
So, brute force takes O(n × m × k²) time.

To optimize this, use a 2D prefix sum matrix.
prefix[i][j] stores the sum of all elements in the rectangle from (0, 0) to (i-1, j-1).
We create prefix of size (n+1) × (m+1) so that the first row and column are zero. This avoids boundary checks.

// Prefix Sum Formula :
prefix[i][j] = mat[i-1][j-1]
             + prefix[i-1][j]
             + prefix[i][j-1]
             - prefix[i-1][j-1];

// Explanation:

Add the current matrix element.
Add the sum of the area above it.
Add the sum of the area to its left.
Subtract the top-left overlapping area because it was added twice.

// Finding Sum of a k × k Submatrix
For a square whose bottom-right corner is (i, j), its sum is:
sum = prefix[i][j]
    - prefix[i-k][j]
    - prefix[i][j-k]
    + prefix[i-k][j-k];

// This uses the inclusion-exclusion principle:
Start with the total rectangle up to (i, j).
Remove the area above the square.
Remove the area left of the square.
Add back their overlapping area.
Check every valid k × k submatrix and keep track of the maximum sum. */

// C++ Code
class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        // prefix[i][j] = sum of rectangle from (0, 0) to (i-1, j-1)
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

        // Build 2D prefix sum matrix
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        int maxSum = INT_MIN;

        
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= m; j++) {
                int sum = prefix[i][j]
                        - prefix[i - k][j]
                        - prefix[i][j - k]
                        + prefix[i - k][j - k];

                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

///Complexity Analysis
/* Building the prefix sum matrix: O(n × m)
Checking all possible k × k submatrices: O(n × m)
Total Time Complexity: O(n × m)
Space Complexity: O(n × m) */


// Interview Explanation
// “I use a 2D prefix sum to efficiently calculate the sum of every k × k submatrix. First, I preprocess the matrix so that each prefix[i][j] stores the sum of all elements from the top-left corner up to that position. Then, using inclusion-exclusion, I can find the sum of any k × k submatrix in constant time. I iterate through all possible k × k squares and return the maximum sum. This reduces the time complexity from O(n × m × k²) to O(n × m).”
