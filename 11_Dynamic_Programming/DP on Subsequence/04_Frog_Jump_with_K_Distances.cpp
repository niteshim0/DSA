// 1. Recursion Solution

class Solution {
  public:
    int minJumps(int idx, vector<int>& height, int k) {
        if (idx == 0) return 0;
        int minSteps = INT_MAX;
        for (int i = 1; i <= k; i++) {
            if (idx - i >= 0) {
                int jump = minJumps(idx - i, height, k) + abs(height[idx] - height[idx - i]);
                minSteps = min(minSteps, jump);
            }
        }
        return minSteps; 
    }

    int minCostK(vector<int>& height, int k) {
        int n = height.size();
        return minJumps(n - 1, height, k);
    }
};


/*
Recurrence Relation :: 
Let f(i) be the minimum cost to reach the i-th stone:
f(0) = 0
f(i) = min( f(i-j) + |height[i] - height[i-j]| )  for all j in [1, k] and i-j >= 0


Time Complexity : O(k^N)
Space Complexity : O(N) // recurisive stack space
*/

// 2. Memoization Solution(Top Down Solution)

class Solution {
  public:
    int minJumps(int idx, vector<int>& height, int k, vector<int>& dp) {
        if (idx == 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        int minSteps = INT_MAX;
        for (int i = 1; i <= k; i++) {
            if (idx - i >= 0) {
                int jump = minJumps(idx - i, height, k, dp) + abs(height[idx] - height[idx - i]);
                minSteps = min(minSteps, jump);
            }
        }

        return dp[idx] = minSteps;
    }

    int minCostK(vector<int>& height, int k) {
        int n = height.size();
        vector<int> dp(n, -1); // Memoization table
        return minJumps(n - 1, height, k, dp);
    }
};

// Time Complexity : O(N*k)
// Space Complexity : O(N)(for dp array) + O(N)(for recursive stack space)

//3.Tabulation Solution(Bottom Up Approach)

class Solution {
  public:
    int minCostK(vector<int>& height,int k) {
        int n = height.size();
        vector<int> dp(n+1,0);
        dp[0] = 0;
        for(int idx = 1;idx<=n;idx++){
            int minSteps = INT_MAX;
          for (int i = 1; i <= k; i++) {
            if (idx - i >= 0) {
                int jump = minJumps(idx - i, height, k, dp) + abs(height[idx] - height[idx - i]);
                minSteps = min(minSteps, jump);
            }
            dp[idx] = minSteps;
        }
        }
        return dp[n-1];
    }
};
// Time Complexity : O(N*k)
// Space Complexity : O(N)

//4. Space Optimized Solution
// No need for space optimized in worst case k = N it will be of no use