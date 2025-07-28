class Solution {
public:
    vector<int> getLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int lis = 1, lastIdx = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i; 
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if (dp[i] > lis) {
                lis = dp[i];
                lastIdx = i;
            }
        }

        vector<int> LIS;
        while (hash[lastIdx] != lastIdx) {
            LIS.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        LIS.push_back(nums[lastIdx]);

        reverse(LIS.begin(), LIS.end());
        return LIS;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N)