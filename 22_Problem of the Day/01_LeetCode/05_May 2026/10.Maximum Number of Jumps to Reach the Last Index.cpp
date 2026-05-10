// LC 2770 . Maximum Number of Jumps to Reach the Last Index
// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description

// Concepts :: Dynamic Programming + Recursion + Memoization + Tabulation

// Approach 1 :: Recursive Approach

class Solution {
public:
    int maxJump(int idx,vector<int>& nums,int target){

        if(idx == nums.size() - 1) return 0;

        int ans = INT_MIN;

        for(int i = idx + 1 ; i < nums.size() ; i++){

            if(abs(nums[i] - nums[idx]) <=target){
                ans = max(ans, 1 + maxJump(i,nums,target));
            }
        }

        return ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        
        int ans = maxJump(0,nums,target);
        return ans < 0 ? -1 : ans;
    }
};

//  Approach 2 :: Memoization Approach

class Solution {
public:
    int maxJump(int idx,vector<int>& nums,int target,vector<int>& dp){

        if(idx == nums.size() - 1) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int ans = INT_MIN;

        for(int i = idx + 1 ; i < nums.size() ; i++){

            if(abs(nums[i] - nums[idx]) <=target){
                ans = max(ans, 1 + maxJump(i,nums,target,dp));
            }
        }

        return dp[idx] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> dp(n+1,-1);
        int ans = maxJump(0,nums,target,dp);
        return ans < 0 ? -1 : ans;
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(N) + Recursion Stack Space

// Approach 3 :: Tabulation Appraoch
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n - 1] = 0;

        for (int idx = n - 2; idx >= 0; idx--) {
            int best = -1;

            for (int i = idx + 1; i < n; i++) {
                if (abs(nums[i] - nums[idx]) <= target && dp[i] != -1) {
                    best = max(best, 1 + dp[i]);
                }
            }

            dp[idx] = best;
        }

        return dp[0];
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(N)

