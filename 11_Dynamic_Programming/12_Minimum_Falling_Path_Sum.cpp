// 1. Recursive Solution

class Solution {
public:
    // Recursive Solution
    int solve(int row,int col,vector<vector<int>>& matrix){
        if(col<0 || col>=matrix.size()) return 1e9;
        if(row == 0){
            return matrix[row][col];
        }

        int up = matrix[row][col] + solve(row-1,col,matrix);
        int leftDiagonal = matrix[row][col] + solve(row-1,col-1,matrix);
        int rightDiagonal = matrix[row][col] + solve(row-1,col+1,matrix);

        return min(up,min(leftDiagonal,rightDiagonal));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            mini = min(mini,solve(n-1,i,matrix));
        }
        return mini;

        // Time Complexity : O(3^(N*N))
        // Space Complexity : O(N) // for auxiliary stack space
    }
};


// 2. Memoization Solution
class Solution {
public:
    // Memoization Solution
    int solve(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (col < 0 || col >= matrix.size()) return 1e9;
        if (row == 0) return matrix[0][col];
        
        if (dp[row][col] != -1) return dp[row][col];

        int up = matrix[row][col] + solve(row - 1, col, matrix, dp);
        int leftDiagonal = matrix[row][col] + solve(row - 1, col - 1, matrix, dp);
        int rightDiagonal = matrix[row][col] + solve(row - 1, col + 1, matrix, dp);

        return dp[row][col] = min({up, leftDiagonal, rightDiagonal});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Declare dp once
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            mini = min(mini, solve(n - 1, i, matrix, dp));
        }

        return mini;
    }

    // Time Complexity : O(N*N)
    // Space Complexity : O(N) // for auxiliary stack space + O(N*N) // for dp array
};

// 3. Tabulation Solution
class Solution {
public:
    // Tabulation Solution
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        int mini = INT_MAX;

        for (int col = 0; col < n; col++) {
            dp[0][col] = matrix[0][col];
        }

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int up = matrix[row][col] + dp[row - 1][col];

                int leftDiagonal = matrix[row][col];
                if (col - 1 >= 0)
                    leftDiagonal += dp[row - 1][col - 1];
                else
                    leftDiagonal = 1e9;

                int rightDiagonal = matrix[row][col];
                if (col + 1 < n)
                    rightDiagonal += dp[row - 1][col + 1];
                else
                    rightDiagonal = 1e9;

                dp[row][col] = min({up, leftDiagonal, rightDiagonal});
            }
        }

        for (int i = 0; i < n; i++) {
            mini = min(mini, dp[n - 1][i]);
        }

        return mini;
    }
    // Time Complexity : O(N*N)  + O(N)
    // Space Complexity : O(N*N)
};

// 4. Space Optimised Tabulation Solution
class Solution {
public:
    // Space Optimised Tabulation Solution
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, -1); 
        int mini = INT_MAX;

        for (int col = 0; col < n; col++) {
            prev[col] = matrix[0][col];
        }

        for (int row = 1; row < n; row++) {
            vector<int> curr(n,0);
            for (int col = 0; col < n; col++) {
                int up = matrix[row][col] + prev[col];

                int leftDiagonal = matrix[row][col];
                if (col - 1 >= 0)
                    leftDiagonal += prev[col - 1];
                else
                    leftDiagonal = 1e9;

                int rightDiagonal = matrix[row][col];
                if (col + 1 < n)
                    rightDiagonal += prev[col + 1];
                else
                    rightDiagonal = 1e9;

                curr[col] = min({up, leftDiagonal, rightDiagonal});
            }
            prev = curr;
        }

        for (int i = 0; i < n; i++) {
            mini = min(mini, prev[i]);
        }

        return mini;
    }
    // Time Complexity : O(N*N)  + O(N)
    // Space Complexity : O(N)
};
