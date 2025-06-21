// 1. Recursion Solution
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& obstacleGrid){
        if(row>=0 && col>=0 && obstacleGrid[row][col] == 1) return 0;
        if(row<0 || col<0) return 0;
        if(row == 0 && col == 0) return 1;

        int up = solve(row-1,col,obstacleGrid);
        int left = solve(row,col-1,obstacleGrid);

        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solve(m-1,n-1,obstacleGrid);
    }
};
// Time Complexity : O(2^(M*N))
// Space Complexity : O(M+N-1) // recursion stack space


// 2. Memoization Solution
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(row>=0 && col>=0 && obstacleGrid[row][col] == 1) return 0;
        if(row<0 || col<0) return 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = solve(row-1,col,obstacleGrid,dp);
        int left = solve(row,col-1,obstacleGrid,dp);

        return dp[row][col]  = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obstacleGrid,dp);
    }
};
// Time Complexity : O(M*N)
// Space Complexity : O(M*N) +O(M+N-1);

// 3. Tabulation Solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int row = 0;row<m;row++){
            for(int col = 0;col<n;col++){
                if(obstacleGrid[row][col] == 1) dp[row][col] = 0;
                else if(row == 0 && col == 0) dp[row][col] = 1;
                else{
                    int up  = 0 , left = 0;
                    if(row-1>=0) up = dp[row-1][col];
                    if(col-1>=0) left = dp[row][col-1];
                    dp[row][col] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// Time Complexity : O(M*N)
// Space Complexity : O(M*N)

// 4. Space Optimized Solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n,0);
        for(int row = 0;row<m;row++){
            vector<int> curr(n,0);
            for(int col = 0;col<n;col++){
                if(obstacleGrid[row][col] == 1) curr[col] = 0;
                else if(row == 0 && col == 0) curr[col] = 1;
                else{
                    int up  = 0 , left = 0;
                    if(row-1>=0) up = prev[col];
                    if(col-1>=0) left = curr[col-1];
                    curr[col] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

// Time Complexity : O(M*N)
// Space Complexity : O(N)