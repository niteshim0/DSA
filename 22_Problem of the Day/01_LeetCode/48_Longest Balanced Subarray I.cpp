// LC 3719. Longest Balanced Subarray I
// https://leetcode.com/problems/longest-balanced-subarray-i/description/
// approach :: apply brute force . Most of the distinct type of subarrays O(n^2) is optimal one , one can do some micro optimizations.
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> evenSet, oddSet;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    evenSet.insert(nums[j]);
                else
                    oddSet.insert(nums[j]);

                if (evenSet.size() == oddSet.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(N)