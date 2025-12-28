// Minimum time to fulfil all orders
// https://www.geeksforgeeks.org/problems/minimum-time-to-fulfil-all-orders/1

class Solution {
public:
    long long cooksCanMake(long long time, vector<int>& ranks) {
        long long total = 0;
        for (int r : ranks) {
            long long x = (long long)(sqrt(1 + 8LL * time / r) - 1) / 2;
            total += x;
        }
        return total;
    }

    int minTime(vector<int>& ranks, int n) {
        long long low = 0, high = 1e18;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (cooksCanMake(mid, ranks) >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// Time Complexity : m*log(high)
// Space Complexity : O(1)
