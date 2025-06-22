// 1. Recursive Solution
class Solution {
  public:
    // Recursive Solution
    int solve(int idx,vector<int>& val,vector<int>& wt,int W){
        if(idx == 0){
            return (wt[idx]<=W ? val[idx] : 0);
        }
        
        int notPick = solve(idx-1,val,wt,W);
        int pick = (wt[idx]<=W ? val[idx] +  solve(idx-1,val,wt,W-wt[idx]) : INT_MIN);
        
        return max(pick,notPick);

    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        return solve(n-1,val,wt,W);
        // Time Complexity : O(2^N)
        // Space Complexity : O(N)
    }
};
// 2. Memoization Solution
class Solution {
  public:
    // Memoization Solution
    int solve(int idx,vector<int>& val,vector<int>& wt,int W,vector<vector<int>>& dp){
        if(idx == 0){
            return (wt[idx]<=W ? val[idx] : 0);
        }
        
        if(dp[idx][W]!=-1) return dp[idx][W];
        
        int notPick = solve(idx-1,val,wt,W,dp);
        int pick = (wt[idx]<=W ? val[idx] +  solve(idx-1,val,wt,W-wt[idx],dp) : INT_MIN);
        
        return dp[idx][W] = max(pick,notPick);

    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return solve(n-1,val,wt,W,dp);
        // Time Complexity : O(N*W)
        // Space Complexity : O(N) + O(N*W)
    }
};
// 3. Tabulation Solution
class Solution {
  public:
    // Tabulation Solution
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        
        for(int weight = wt[0];weight<=W;weight++){
            dp[0][weight] = val[0];
        }
        
        for(int idx = 1;idx<n;idx++){
            for(int weight = 0;weight<=W;weight++){
                
                int notPick = dp[idx-1][weight];
                int pick = (wt[idx]<=weight ? val[idx] +  dp[idx-1][weight-wt[idx]] : INT_MIN);
        
                dp[idx][weight] = max(pick,notPick);
            }
        }
        return dp[n-1][W];
        // Time Complexity : O(N*W)
        // Space Complexity : O(N*W)
    }
};
// 4. Space Optimised Tabulation Solution
class Solution {
  public:
    //Space Optimised Tabulation Solution
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> prev(W+1,0);
        
        for(int weight = wt[0];weight<=W;weight++){
            prev[weight] = val[0];
        }
        
        for(int idx = 1;idx<n;idx++){
            vector<int> curr(W+1,0);
            for(int weight = 0;weight<=W;weight++){
                
                int notPick = prev[weight];
                int pick = (wt[idx]<=weight ? val[idx] +  prev[weight-wt[idx]] : INT_MIN);
        
                curr[weight] = max(pick,notPick);
            }
            prev = curr;
        }
        return prev[W];
        // Time Complexity : O(N*W)
        // Space Complexity : O(W)
    }
};