class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1) , hash(n,0);
        int lds = 0,lastIdx = 0;

        for(int i = 0;i<n;i++){
            hash[i] = i;
           for(int prev = 0;prev<i;prev++){
               if(nums[i]%nums[prev]==0 && 1+dp[prev] > dp[i]){
                 dp[i] = 1 + dp[prev];
                 hash[i] = prev;
               }
           }
           if(dp[i]>lds){
            lds = dp[i];
            lastIdx  = i;
           }
        }
        vector<int> LDS;
        LDS.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx){
            lastIdx = hash[lastIdx];
            LDS.push_back(nums[lastIdx]);
        }
        reverse(LDS.begin(),LDS.end());
        return LDS;
    }
};
// Time Complexity : O(N*N) + O(N)
// Space Complexity :O(3*N)