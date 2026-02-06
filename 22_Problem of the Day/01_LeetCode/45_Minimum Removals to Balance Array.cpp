// 3634. Minimum Removals to Balance Array
// https://leetcode.com/problems/minimum-removals-to-balance-array/description/
// Concept :: Sliding Window + Two Pointers + Sorting

// Approach :: Remove the longest winSize which violates the condition.


class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0, maxWinSize = 0;

        for (int j = 0; j < n; j++) {
            while (nums[j] > 1LL * nums[i] * k) {
                i++;
            }
            maxWinSize = max(maxWinSize, j - i + 1);
        }

        return n - maxWinSize;
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N) (sorting algo takes space)