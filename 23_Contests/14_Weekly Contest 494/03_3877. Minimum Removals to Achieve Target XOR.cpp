// LC 3877. Minimum Removals to Achieve Target XOR
// https://leetcode.com/problems/minimum-removals-to-achieve-target-xor/description/

// Concepts :: Dynamic Programming + XOR Concept + Pick/Non-Pick Template of DP

// Approach :: Since we have to find the minimum removal to reach to the target, I will find the maximum element xored which results in target.
// and then subtract it from total no of elements.
// typical pick/non-pick template of dp gets followed

class Solution {
public:
    vector<vector<int>> dp;
    int maxAddition(vector<int>&nums, int target, int idx, int xr,int cnt){

       if(idx == nums.size()) {

           return (xr == target) ? 0 : -1e5;
       }

        if(dp[idx][xr]!=-1) return dp[idx][xr];

        int pick = 1 + maxAddition(nums,target,idx+1,xr^nums[idx],cnt+1);
        int notPick = maxAddition(nums,target,idx+1,xr,cnt);

        return dp[idx][xr] = max(pick,notPick);

    }
    int minRemovals(vector<int>& nums, int target) {

        int n = nums.size();

        int maxi = *max_element(nums.begin(),nums.end());

        dp.resize(n+1,vector<int>(1e5,-1));
        
        int maxLen = maxAddition(nums,target,0,0,0);
        
        return maxLen < 0 ? -1 : nums.size() - maxLen;

        
    }
};

// Time Complexity : O(N*1e5) // smaller n otherwise it should have failed if n>=1e5
// Space Complexity : O(N*1e5) + O(N) // recursion stack space