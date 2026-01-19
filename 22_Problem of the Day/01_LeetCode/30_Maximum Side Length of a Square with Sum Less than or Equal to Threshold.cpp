// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description
// Concepts :: BinarySearch + 2D PrefixSum

// Appraoch I : 2D PrefixSum + BinarySearch
/*
1. Create a 2d prefixSum array.
2. Now try all the square possible in that matrix , for better search try binarySearch.(in range of [1,min(m,n)])
3. For every binarySearch logic , check for every square of sideLen == mid , and as according to that , increse or decrease the sideLength.
*/

class Solution {
public:
    bool feasibleSquarePossible(vector<vector<int>>& prefSum,
                                int row1, int col1,
                                int row2, int col2,
                                int threshold) {

        int sum = prefSum[row2][col2]
                - prefSum[row1 - 1][col2]
                + prefSum[row1 - 1][col1 - 1]
                - prefSum[row2][col1 - 1];

        return sum <= threshold;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> prefSum(n + 1, vector<int>(m + 1, 0));

        // Build prefix sum
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefSum[i][j] = mat[i - 1][j - 1]
                              + prefSum[i - 1][j]
                              + prefSum[i][j - 1]
                              - prefSum[i - 1][j - 1];
            }
        }

        int start = 1, end = min(n, m), ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            bool findSquare = false;

            for (int i = 1; i + mid - 1 <= n; i++) {
                for (int j = 1; j + mid - 1 <= m; j++) {
                    if (feasibleSquarePossible(prefSum, i, j,
                        i + mid - 1, j + mid - 1, threshold)) {
                        findSquare = true;
                        break;
                    }
                }
                if (findSquare) break;
            }

            if (findSquare) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};

// Time Complexity : O(log(MN*N)*(N*M))
// Space Complexity : O(M*N)

// Approach II : Enumeration & Optimization
// Same as binary search but there are little bit optimization which results in Amortized M*N

class Solution {
public:
    bool feasibleSquarePossible(vector<vector<int>>& prefSum,
                                int row1, int col1,
                                int row2, int col2,
                                int threshold) {

        int sum = prefSum[row2][col2]
                - prefSum[row1 - 1][col2]
                - prefSum[row2][col1 - 1]
                + prefSum[row1 - 1][col1 - 1];

        return sum <= threshold;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> prefSum(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefSum[i][j] = mat[i - 1][j - 1]
                              + prefSum[i - 1][j]
                              + prefSum[i][j - 1]
                              - prefSum[i - 1][j - 1];
            }
        }

        int ans = 0;
        int end = min(n, m);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int c = ans + 1; c <= end; c++) {

                    if (i + c - 1 <= n && j + c - 1 <= m &&
                        feasibleSquarePossible(prefSum, i, j,
                            i + c - 1, j + c - 1, threshold)) {

                        ans = c;   
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M) amortized
// Space Complexity : O(M*N)