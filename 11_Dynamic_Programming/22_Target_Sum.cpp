// 1. Recursive Solution
class Solution {
public:
    // Recursive Solution
    int solve(int idx,vector<int>& nums,int target,int sum){
        if(idx == 0){
            if(sum+nums[0]== target && sum-nums[0] == target) return 2; // in case of zero
            if(sum+nums[0]== target || sum-nums[0] == target) return 1;
            return 0;
        }

        int plus = solve(idx-1,nums,target,sum + nums[idx]);
        int neg = solve(idx-1,nums,target,sum-nums[idx]);

        return plus + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n-1,nums,target,0);
        // Time Complexity : O(2^N)
        // Space Complexity : O(N)
    }
};
// 2. Memoization Solution
class Solution {
public:
    int solve(int idx, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        if (idx < 0) {
            return sum == target ? 1 : 0;
        }
        if (dp[idx][sum + offset] != -1) return dp[idx][sum + offset];

        int plus = solve(idx - 1, sum + nums[idx], nums, target, dp, offset);
        int minus = solve(idx - 1, sum - nums[idx], nums, target, dp, offset);

        return dp[idx][sum + offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int offset = total;  // because sum can go from -total to +total

        if (target > total || target < -total) return 0; // no solution possible

        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

        return solve(n - 1, 0, nums, target, dp, offset);
      //Time: O(N * 2 * totalSum) = O(N * totalSum)
      // Space: O(N * totalSum) for memoization
    }
};

// 3. Tabulation Solution
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If target is out of possible range, return 0
        if (target > totalSum || target < -totalSum) return 0;

        int offset = totalSum;
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, 0));

        // Base case initialization for the first element
        dp[0][nums[0] + offset] += 1;
        dp[0][-nums[0] + offset] += 1;

        for (int idx = 1; idx < n; ++idx) {
            for (int sum = -totalSum; sum <= totalSum; ++sum) {
                int shiftedSum = sum + offset;
                if (dp[idx - 1][shiftedSum] > 0) {
                    dp[idx][shiftedSum + nums[idx]] += dp[idx - 1][shiftedSum];
                    dp[idx][shiftedSum - nums[idx]] += dp[idx - 1][shiftedSum];
                }
            }
        }

        return dp[n - 1][target + offset];
        // Time Complexity : O(N * 2 * totalSum)
        // Space Complexity : O(N * 2 * totalSum)
    }
};

// 4. Space Optimised Tabulation Solution
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        if (target > totalSum || target < -totalSum) return 0;

        int offset = totalSum;
        int size = 2 * totalSum + 1;

        vector<int> prev(size, 0), curr(size, 0);

        // Base case for the first element
        prev[nums[0] + offset]++;
        prev[-nums[0] + offset]++;

        for (int idx = 1; idx < n; ++idx) {
            fill(curr.begin(), curr.end(), 0); // reset current row
            for (int sum = -totalSum; sum <= totalSum; ++sum) {
                int shiftedSum = sum + offset;
                if (prev[shiftedSum] > 0) {
                    curr[shiftedSum + nums[idx]] += prev[shiftedSum];
                    curr[shiftedSum - nums[idx]] += prev[shiftedSum];
                }
            }
            swap(prev, curr);
        }

        return prev[target + offset];
        // Time Complexity : O(N * 2 * totalSum)
        // Space Complexity : O(2 * totalSum)
    }
};

// It will be much better approach to use the knowledge of partition with given difference (s1 = all + signs) - (s2(all-ve signs)) == target eventually converted the problem in that
