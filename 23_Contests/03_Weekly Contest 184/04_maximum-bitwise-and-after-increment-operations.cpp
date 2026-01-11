// https://leetcode.com/problems/maximum-bitwise-and-after-increment-operations

// Concept :: BitMasking + Sorting + BrainPower


class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        long long ans = 0;

        for (int bit = 30; bit >= 0; bit--) {
            long long want = ans | (1LL << bit);
            vector<long long> cost;

            for (long long x : nums) {
                if ((x & want) == want) {
                    cost.push_back(0);
                } else {
                    long long y = x;
                    for (int b = 30; b >= 0; b--) {
                        if ((want & (1LL << b)) && !(y & (1LL << b))) {
                            long long add = (1LL << b) - (y & ((1LL << b) - 1));
                            y += add;
                        }
                    }
                    cost.push_back(y - x);
                }
            }

            sort(cost.begin(), cost.end());

            long long used = 0;
            for (int i = 0; i < m; i++) used += cost[i];

            if (used <= k) ans = want;
        }

        return (int)ans;
    }
};

// Time Compexity : O(31*n)
// Space Complexity : O(N)