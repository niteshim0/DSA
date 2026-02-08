// https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
// Maximum Product Subarray
// Concepts :: Multiplication + Recursion + Dynamic Programming + Recurrrence Relation


// Approach :: For every index ending , we must find , how much we can get maxProduct and minProduct get till there

// Technique 1 : Memoization(top down approach)
class Solution {
public:
    vector<long long> dpMax, dpMin;
    vector<bool> vis;

    void solve(int idx, vector<int>& nums) {
        if (vis[idx]) return;
        vis[idx] = true;

        if (idx == 0) {
            dpMax[0] = dpMin[0] = nums[0];
            return;
        }

        solve(idx - 1, nums);

        long long a = nums[idx];
        long long b = nums[idx] * dpMax[idx - 1];
        long long c = nums[idx] * dpMin[idx - 1];

        dpMax[idx] = max({a, b, c});
        dpMin[idx] = min({a, b, c});
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        dpMax.assign(n, 0);
        dpMin.assign(n, 0);
        vis.assign(n, false);

        long long ans = nums[0];
        for (int i = 0; i < n; i++) {
            solve(i, nums);
            ans = max(ans, dpMax[i]);
        }
        return ans;
    }
};

// Complexity
// Time: O(n)
// Space: O(n) (memo tables + recursion stack)

// Technique 2 :: Tabulation (Bottom Up Version)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<long long> dpMax(n), dpMin(n);

        dpMax[0] = dpMin[0] = nums[0];
        long long ans = nums[0];

        for (int i = 1; i < n; i++) {
            long long a = nums[i];
            long long b = nums[i] * dpMax[i - 1];
            long long c = nums[i] * dpMin[i - 1];

            dpMax[i] = max({a, b, c});
            dpMin[i] = min({a, b, c});

            ans = max(ans, dpMax[i]);
        }
        return ans;
    }
};

// Complexity
// Time: O(n)
// Space: O(n) (memo tables)

// See :: we don't need whole array , we just need previous value , need to be space optmized

class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int maxProd = nums[0], minProd = nums[0], ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            ans = max(ans, maxProd);
        }
        return ans;
    }
};

// Complexity
// Time: O(n)
// Space: O(1) // constant space throughout , but we need atleast something to store our variables
