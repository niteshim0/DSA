// 3013. Divide an Array Into Subarrays With Minimum Cost II
// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/
// Concept :: Multiset + Priority Queue + Lazy Deletion


// Approach :: Use Sliding Window


class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX;
        long long base = nums[0];

        multiset<int> low, high;
        long long sumLow = 0;

        int secIdx = 1;
        int kthIdx = min(n - 1, 1 + dist);

        auto add = [&](int x) {
            if (low.empty() || x <= *prev(low.end())) {
                low.insert(x);
                sumLow += x;
            } else {
                high.insert(x);
            }
        };

        auto remove = [&](int x) {
            if (low.find(x) != low.end()) {
                low.erase(low.find(x));
                sumLow -= x;
            } else {
                high.erase(high.find(x));
            }
        };

        auto rebalance = [&]() {
            while (low.size() > k - 1) {
                auto it = prev(low.end());
                sumLow -= *it;
                high.insert(*it);
                low.erase(it);
            }
            while (low.size() < k - 1 && !high.empty()) {
                auto it = high.begin();
                sumLow += *it;
                low.insert(*it);
                high.erase(it);
            }
        };

        for (int i = secIdx; i <= kthIdx; i++) {
            add(nums[i]);
            rebalance();
        }

        while (kthIdx < n) {
            if (low.size() == k - 1) {
                ans = min(ans, base + sumLow);
            }

            remove(nums[secIdx]);
            secIdx++;
            kthIdx++;

            if (kthIdx < n) {
                add(nums[kthIdx]);
            }
            rebalance();
        }

        return ans;
    }
};


// Time Complexity : O(NlogN)
// Space Complexity : O(N)