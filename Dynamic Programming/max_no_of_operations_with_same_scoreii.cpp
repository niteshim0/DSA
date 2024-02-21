class Solution {
public:
    int solve(int left,int right,vector<int>&nums,int prevSum,vector<vector<int>>& dp){
        if(left>=right){
            return 0;
        }
        if(dp[left][right]!=-1) return dp[left][right];
        int ans = 0;
        if(nums[left+1] + nums[left] == prevSum){
            ans = max(ans, 1 + solve(left+2,right,nums,prevSum,dp));
        }
        if(nums[right-1] + nums[right] == prevSum){
            ans = max(ans, 1 + solve(left,right-2,nums,prevSum,dp));
        }
        if(nums[left] + nums[right] == prevSum){
            ans = max(ans, 1 + solve(left+1,right-1,nums,prevSum,dp));
        }
        return  dp[left][right] = ans;
    }
    int maxOperations(vector<int>& nums) {
          int n = nums.size();
        
         int prevSum1 = nums[0] + nums[1];
         vector<vector<int>> dp1(n,vector<int>(n,-1));
         int ans1 = solve(0,n-1,nums,prevSum1,dp1);
        
         int prevSum2 = nums[n-1] + nums[n-2];
         vector<vector<int>> dp2(n,vector<int>(n,-1));
         int ans2 = solve(0,n-1,nums,prevSum2,dp2);
        
         int prevSum3 = nums[0] + nums[n-1];
         vector<vector<int>> dp3(n,vector<int>(n,-1));
         int ans3 = solve(0,n-1,nums,prevSum3,dp3);
        
        return max({ans1,ans2,ans3});
        
        
    }
};