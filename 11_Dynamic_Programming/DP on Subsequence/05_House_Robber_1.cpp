// 1. Recursion Solution 

class Solution {
public:
    int maxAdj(int idx,vector<int>& nums){
        if(idx == 0) return nums[idx];
        if(idx<0) return 0;
        int pick = nums[idx]  + maxAdj(idx-2,nums);
        int notPick = maxAdj(idx-1,nums);
        return max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return maxAdj(n-1,nums);
    }
};

/* Recurrence Relaton::
Let T(i) represent the maximum money that can be robbed from house 0 to house i.

The recurrence relation is:
T(i) = max(nums[i] + T(i-2), T(i-1))

Base Cases::
T(0) = nums[0]
T(i) = 0, if i < 0

// Time Complexity :: O(2^n)
// Space Complexity:: O(n) ( for recursive stack space)
*/

// 2. Memoization Solution (Top Down Approach)

class Solution {
public:
    int maxAdj(int idx,vector<int>& nums,vector<int>& dp){
        if(idx == 0) return nums[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = nums[idx]  + maxAdj(idx-2,nums,dp);
        int notPick = maxAdj(idx-1,nums,dp);
        return dp[idx] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return maxAdj(n-1,nums,dp);
    }
};
// Time Complexity :: O(N)
// Space Complexity :: O(N)(for dp array) + O(N)(for recursive stack space)

// 3. Tabulation Solution(Bottom Up Approach)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        for(int idx = 1;idx<n;idx++){
            int pick = nums[idx];
            if(idx>1) pick+=dp[idx-2];
            int notPick = dp[idx-1];
            dp[idx] = max(pick,notPick);
        }
        return dp[n-1];
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// 4. Space Optimized Solution

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        for(int idx = 1;idx<n;idx++){
            int pick = nums[idx];
            if(idx>1) pick+=prev2;
            int notPick = prev1;
            int curr = max(pick,notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)