class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1) , cnt(n,1);
        int lis = 0;

        for(int i = 0 ;i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(arr[i] > arr[prev] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                } else if(arr[i] > arr[prev] && 1 + dp[prev] == dp[i]) {
                    cnt[i] += cnt[prev];
                }
            }
            lis = max(lis, dp[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == lis) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};
