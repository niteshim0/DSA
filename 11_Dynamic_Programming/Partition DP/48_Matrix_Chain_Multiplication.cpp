// Recursive Solution
class Solution {
  public:
    int MMSolver(int start,int end,vector<int>& arr){
        if(start == end) return 0;
        
        int mini = INT_MAX;
        
        for(int k = start;k<end;k++){
            int steps = arr[start-1]*arr[k]*arr[end] + MMSolver(start,k,arr) + MMSolver(k+1,end,arr);
            if(steps<mini){
                mini = steps;
            }
        }
        
        return mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        return MMSolver(1,n-1,arr);
        
    }
};
// Time Complexity : O(N^N)
// Space Complexity : O(N)

// Bottom Up Approach Solution

class Solution {
  public:
    int MMSolver(int start,int end,vector<int>& arr,vector<vector<int>>& dp){
        if(start == end) return 0;
        
        if(dp[start][end]!=-1) return dp[start][end];
        
        int mini = INT_MAX;
        
        for(int k = start;k<end;k++){
            int steps = arr[start-1]*arr[k]*arr[end] + MMSolver(start,k,arr,dp) + MMSolver(k+1,end,arr,dp);
            if(steps<mini){
                mini = steps;
            }
        }
        
        return dp[start][end] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return MMSolver(1,n-1,arr,dp);
        
    }
};

// Time Complexity : O(N*N*N)
// Space Complexity : O(N) + O(N*N)

// Tabulation Method
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));


        for(int start = n - 1; start >= 1; start--) {
            for(int end = start + 1; end < n; end++) {
                int mini = INT_MAX;
                for(int k = start; k < end; k++) {
                    int steps = arr[start - 1] * arr[k] * arr[end] + 
                                dp[start][k] + dp[k + 1][end];
                    mini = min(mini, steps);
                }
                dp[start][end] = mini;
            }
        }
        return dp[1][n - 1];
    }
};
// Time Complexity : O(N*N*N)
// Space Complexity : O(N*N)