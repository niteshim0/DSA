// 1. Recursion Solution
class Solution {
public:
    int solve(int row,int col){
        if(row == 0 && col == 0) return 1;
        if(row<0 && col<0) return 0;
        int up = solve(row-1,col);
        int left = solve(row,col-1);
        return up + left;
    }
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};
// Time Complexity : O(2^(m*n))
// Space Complexity : O(m+n-1)

// 2. Memoization Solution

class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& dp){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        
        int up = solve(row - 1, col, dp);
        int left = solve(row, col - 1, dp);
        
        return dp[row][col] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};
// Time Complexity : O(M*N)
// Space Complexity : O(M-1 + N-1)  + O(N*M)


// 3. Tabulation Solution

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0) continue;

                int up = 0, left = 0;
                if (row - 1 >= 0) up = dp[row - 1][col];
                if (col - 1 >= 0) left = dp[row][col - 1];

                dp[row][col] = up + left;
            }
        }

        return dp[m - 1][n - 1];
    }
};
// Time Complexity : O(M*N)
// Space Complexity : O(M*N)


// 4. Space Optimization
// if there is a prev row and prev col ,we can space optimize it.

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);

        for (int row = 0; row < m; row++) {
            vector<int> curr(n, 0);
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0) {
                    curr[0] = 1;
                } else {
                    int up = 0, left = 0;
                    if (row - 1 >= 0) up = prev[col];
                    if (col - 1 >= 0) left = curr[col - 1];
                    curr[col] = up + left;
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};
// Time Complexity : O(M*N)
// Space Complexity : O(2N)