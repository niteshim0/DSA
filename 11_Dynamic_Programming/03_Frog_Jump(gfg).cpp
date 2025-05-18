// 1. Recursion Solution

class Solution {
  public:
    int minJumps(int idx,vector<int>& height){
        if(idx == 0) return 0;
        int left = minJumps(idx-1,height) + abs(height[idx]-height[idx-1]);
        int right = INT_MAX;
        if(idx>1) right = minJumps(idx-2,height) + abs(height[idx]-height[idx-2]);
        return min(left,right);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        return minJumps(n-1,height);
    }
};

/*
Recurrence Relation :: 
Let f(i) be the minimum cost to reach the i-th stone:
f(0) = 0
f(i) = min( f(i-1) + |height[i] - height[i-1]|,
            f(i-2) + |height[i] - height[i-2]| )   for i >= 1

Time Complexity : O(2^N)
Space Complexity : O(N) // recurisive stack space
*/

// 2. Memoization Solution(Top Down Solution)

class Solution {
  public:
    int minJumps(int idx,vector<int>& height,vector<int>& dp){
        if(idx == 0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int left = minJumps(idx-1,height,dp) + abs(height[idx]-height[idx-1]);
        int right = INT_MAX;
        if(idx>1) right = minJumps(idx-2,height,dp) + abs(height[idx]-height[idx-2]);
        return dp[idx] =  min(left,right);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1,-1);
        return minJumps(n-1,height,dp);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)(for dp array) + O(N)(for recursive stack space)

//3.Tabulation Solution(Bottom Up Approach)

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1,0);
        dp[0] = 0;
        for(int idx = 1;idx<=n;idx++){
            int left = dp[idx-1] + abs(height[idx]-height[idx-1]);
            int right = INT_MAX;
            if(idx>1) right = dp[idx-2] + abs(height[idx]-height[idx-2]);
            dp[idx] =  min(left,right);
        }
        return dp[n-1];
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

//4. Space Optimized Solution

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev1 = 0;  // cost to reach stone i-1
        int prev2 = 0;  // cost to reach stone i-2

        for(int idx = 1; idx < n; idx++) {
            int left = prev1 + abs(height[idx] - height[idx - 1]);
            int right = INT_MAX;
            if(idx > 1)
                right = prev2 + abs(height[idx] - height[idx - 2]);
            int curr = min(left, right);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)