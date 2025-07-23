// Recursive Solution
class Solution {
public:
    int LISSolver(int idx,int prevIdx,vector<int>& nums){
        if(idx == nums.size()){
            return 0;
        }
        int notPick = LISSolver(idx+1,prevIdx,nums);
        int pick = 0;
        if(prevIdx == -1 || nums[idx]>nums[prevIdx]){
            pick = 1 + LISSolver(idx+1,idx,nums);
        }
        return max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        return LISSolver(0,-1,nums);
    }
};
// Time Complexity : O(2^N)
// Space Complexity : O(N)

// Tabulation Solution
class Solution {
public:
    int LISSolver(int idx,int prevIdx,vector<int>& nums,vector<vector<int>>& dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prevIdx+1]!=-1) return dp[idx][prevIdx+1];
        int notPick = LISSolver(idx+1,prevIdx,nums,dp);
        int pick = 0;
        if(prevIdx == -1 || nums[idx]>nums[prevIdx]){
            pick = 1 + LISSolver(idx+1,idx,nums,dp);
        }
        return dp[idx][prevIdx+1] = max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LISSolver(0,-1,nums,dp);
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N*N) + O(N)

// Tabulation Solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--) {
                int notPick = dp[idx + 1][prevIdx + 1];
                int pick = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    pick = 1 + dp[idx + 1][idx + 1];
                }
                dp[idx][prevIdx + 1] = max(pick, notPick);
            }
        }

        return dp[0][0];
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(N*N)


// Space Optimized Tabulation Solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--) {
                int notPick = dp[prevIdx + 1];
                int pick = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    pick = 1 + dp[idx + 1];
                }
                dp[prevIdx + 1] = max(pick, notPick);
            }
        }

        return dp[0];
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N)


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int lis = 1;

        for(int i = 0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i] = max(1+dp[prev],dp[i]);
                }
            }
            lis = max(lis,dp[i]);
        }
        return lis;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N)

