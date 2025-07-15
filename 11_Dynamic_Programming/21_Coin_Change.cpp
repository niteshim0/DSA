// 1. Recursive Solution
class Solution {
public:
    // Recursion Solution
    int solve(int idx, vector<int>& coins, int amount) {
        if (idx == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }

        int notPick = solve(idx - 1, coins, amount);
        int pick = (amount >= coins[idx] ? 1 + solve(idx, coins, amount - coins[idx]) : 1e9);

        return  min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solve(n - 1, coins, amount);
        return ans >= 1e9 ? -1 : ans;
    }
    // Time Complexity : O(>> 2^N) // we can say exponential
    // Space Complexity : O(amount)
};

// 2. Memoization Solution
class Solution {
public:
    // Memoization Solution
    int solve(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int notPick = solve(idx - 1, coins, amount, dp);
        int pick = (amount >= coins[idx] ? 1 + solve(idx, coins, amount - coins[idx], dp) : 1e9);

        return dp[idx][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
    // Time Complexity : O(N*amount)
    // Space Complexity : O(amount) + O(N*amount)
};

// 3. Tabulation Solution
class Solution {
public:
    // Tabulation Solution
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1,0));
        for(int need = 0;need<=amount;need++){
            if(need % coins[0] == 0) {
              dp[0][need] =  need / coins[0];
            }else{
                dp[0][need] = 1e9;
            }
        }
        for(int idx = 1;idx<n;idx++){
            for(int den = 0;den<=amount;den++){

                int notPick = dp[idx-1][den];
                int pick = (den >= coins[idx] ? 1 + dp[idx][den-coins[idx]] : 1e9);

                dp[idx][den] = min(pick, notPick);
            }
        }
        int ans = dp[n-1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
    // Time Complexity : O(N*amount)
    // Space Complexity : O(N*amount)
};
// 4. Space Optimised Tabulation Solution
class Solution {
public:
    // Space Optimised Tabulation Solution
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;
        
        vector<int> prev(amount + 1, 0);

        // Base case: fill for using only the first coin
        for (int need = 0; need <= amount; ++need) {
            if (need % coins[0] == 0)
                prev[need] = need / coins[0];
            else
                prev[need] = INF;
        }

        for (int idx = 1; idx < n; ++idx) {
            vector<int> curr(amount + 1, 0);
            for (int den = 0; den <= amount; ++den) {
                int notPick = prev[den];
                int pick = (den >= coins[idx]) ? 1 + curr[den - coins[idx]] : INF;
                curr[den] = min(pick, notPick);
            }
            prev = curr;
        }

        return (prev[amount] >= INF) ? -1 : prev[amount];
        // Time Complexity : O(N*amount)
        // Space Complexity : O(amount)
    }
};
