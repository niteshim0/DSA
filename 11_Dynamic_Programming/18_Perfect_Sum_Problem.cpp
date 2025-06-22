// 1. Recursive Solution

class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int idx, vector<int>& arr, int target) {
        if (idx == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }

        int notPick = solve(idx - 1, arr, target) % mod;
        int pick = 0;
        if (arr[idx] <= target) {
            pick = solve(idx - 1, arr, target - arr[idx]) % mod;
        }

        return (pick + notPick) % mod;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        return solve(n - 1, arr, target);
    }
    // Time Complexity : O(2^N)
    // Space Complexity : O(N)
};

// 2. Memoization Solution
class Solution {
public:
    // Memoization Solution
    int mod = 1e9 + 7;

    int solve(int idx, vector<int>& arr, int target,vector<vector<int>>& dp) {
        if (idx == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notPick = solve(idx - 1, arr, target,dp) % mod;
        int pick = 0;
        if (arr[idx] <= target) {
            pick = solve(idx - 1, arr, target - arr[idx],dp) % mod;
        }

        return dp[idx][target] = (pick + notPick) % mod;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n - 1, arr, target,dp);
        // Time Complexity : O(N*target)
        // Space Complexity : O(N* target) + O(N)
    }
};

// 3. Tabulation Solution
class Solution {
public:
   // Tabulation Solution
    int mod = 1e9 + 7;

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        dp[0][0] = 1;
        if(num[0] = 0) dp[0][0] = 2;
        if (arr[0]!=0 && arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int sum = 0; sum <= target; sum++) {
                int notPick = dp[idx - 1][sum] % mod;
                int pick = (arr[idx] <= sum) ? dp[idx - 1][sum - arr[idx]] % mod : 0;
                dp[idx][sum] = (pick + notPick) % mod;
            }
        }

        return dp[n - 1][target];
        
        // Time Complexity : O(N*sum)
        // Space Complexity : O(N*sum) 
    }
};

// 4. Space Optimised Tabulation Solution
class Solution {
public:
    int mod = 1e9 + 7;

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        prev[0] = 1;
        if (arr[0] == 0)
            prev[0] = 2;
        else if (arr[0]!=0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for (int idx = 1; idx < n; idx++) {
            curr[0] = (arr[idx] == 0) ? (2 * prev[0]) % mod : prev[0];
            for (int sum = 1; sum <= target; sum++) {
                int notPick = prev[sum] % mod;
                int pick = (arr[idx] <= sum) ? prev[sum - arr[idx]] % mod : 0;
                curr[sum] = (pick + notPick) % mod;
            }
            prev = curr;
        }

        return prev[target];
        // Time Complexity : O(N*sum)
        // Space Complexity : O(sum)
    }
};


