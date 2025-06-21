// 1. Recursive Solution

class Solution {
public:
    // Recursive Solution
    int solve(int row,int col,vector<vector<int>>& triangle){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }

        int down = triangle[row][col] + solve(row+1,col,triangle);
        int diagonal = triangle[row][col] + solve(row+1,col+1,triangle);

        return min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0,0,triangle);
    }
    // Time Complexity : O(2^(N*(N+1)/2))
    // Space Complexity : O(N)
};


// 2. Memoization Solution

class Solution {
public:
    // Memoization Solution
    int solve(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }
        
        if(dp[row][col]!=-1) return dp[row][col];

        int down = triangle[row][col] + solve(row+1,col,triangle,dp);
        int diagonal = triangle[row][col] + solve(row+1,col+1,triangle,dp);

        return dp[row][col] = min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,dp);
    }
    // Time Complexity : O((N*(N+1)/2))
    // Space Complexity : O(N) // for auxiliary stack space + O(N*N) // for dp array
};


// 3. Tabulation Solution

class Solution {
public:
    // Tabulation Solution
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i = 0;i<n;i++){
           dp[n-1][i] = triangle[n-1][i];
        }

        for(int row = n-2;row>=0;row--){
            for(int col = row;col>=0;col--){

                int down = triangle[row][col] + dp[row+1][col];
                int diagonal = triangle[row][col] + dp[row+1][col+1];

                dp[row][col] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
    // Time Complexity : O((N*(N+1)/2))
    // Space Complexity : O(N*N) // for dp array
};

// 4. Space Optimised Tabulation Solution

class Solution {
public:
    // Space Optimised Tabulation Solution
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,0);

        for(int i = 0;i<n;i++){
           prev[i] = triangle[n-1][i];
        }

        for(int row = n-2;row>=0;row--){
            vector<int> curr(n,0);
            for(int col = row;col>=0;col--){

                int down = triangle[row][col] + prev[col];
                int diagonal = triangle[row][col] + prev[col+1];

                curr[col] = min(down,diagonal);
            }
            prev = curr;
        }
        return prev[0];
    }
    // Time Complexity : O((N*(N+1)/2))
    // Space Complexity : O(N) // for dp array
};