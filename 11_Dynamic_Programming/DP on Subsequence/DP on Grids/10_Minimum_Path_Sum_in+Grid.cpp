// 1. Recursion Solution
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& grid){
        if(row == 0 && col == 0) return grid[row][col];
        if(row<0 || col<0) return 1e9;

        int up = grid[row][col] + solve(row-1,col,grid);
        int  left = grid[row][col]  + solve(row,col-1,grid);

        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(m-1,n-1,grid);
    }
};
// Time Complexity : O(2^(M*N))
// Space Complexity : O(M+N-1)//path length

// 2. Memoization Solution
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(row == 0 && col == 0) return grid[row][col];
        if(row<0 || col<0) return 1e9;
        if(dp[row][col]!=-1) return dp[row][col];

        int up = grid[row][col] + solve(row-1,col,grid,dp);
        int  left = grid[row][col]  + solve(row,col-1,grid,dp);

        return dp[row][col] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};
// Time Complexity : O((M*N))
// Space Complexity : O(M*N) + O(M + N-1)

// 3. Tabulation Solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        for(int row = 0;row<m;row++){
          for(int col = 0;col<n;col++){
            if(row == 0 && col == 0) dp[0][0] = grid[row][col];
            else{
                int up = 1e9,left = 1e9;
                if(row-1>=0) up = grid[row][col] + dp[row-1][col];
                if(col-1>=0) left = grid[row][col] + dp[row][col-1];
                dp[row][col] = min(up,left);
            }
          }
        }
        return dp[m-1][n-1];
    }
};
// Time Complexity : O(M*N)
// Space Complexity : O(M*N)

// 4.Space Optimized Solution

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,1e9);
        for(int row = 0;row<m;row++){
            vector<int> curr(n,0);
          for(int col = 0;col<n;col++){
            if(row == 0 && col == 0) curr[0] = grid[row][col];
            else{
                int up = 1e9,left = 1e9;
                if(row-1>=0) up = grid[row][col] + prev[col];
                if(col-1>=0) left = grid[row][col] + curr[col-1];
                curr[col] = min(up,left);
            }
          }
          prev = curr;
        }
        return prev[n-1];
    }
};

// Time Complexity : O(M*N)
// Space Complexity : O(N)
