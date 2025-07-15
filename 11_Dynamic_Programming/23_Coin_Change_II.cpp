// 1. Recursive Solution
class Solution {
public:
    // Recursive Solution
    int solve(int idx,vector<int>& coins,int amount){
        if(idx == 0){
            return (amount%coins[0] == 0);
        }

        int notPick = solve(idx-1,coins,amount);
        int pick = (amount>=coins[idx] ? solve(idx,coins,amount-coins[idx]) : 0);

        return pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(n-1,coins,amount);
        // Time Complexity : (>>2^N) // exponential
        // Space Complexity : O(amount)
    }
};
// 2. Memoization Solution
class Solution {
public:
    // Memoization Solution
    int solve(int idx,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(idx == 0){
            return (amount%coins[0] == 0);
        }
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int notPick = solve(idx-1,coins,amount,dp);
        int pick = (amount>=coins[idx] ? solve(idx,coins,amount-coins[idx],dp) : 0);

        return dp[idx][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
        // Time Complexity : (N) 
        // Space Complexity : O(amount) + O(N*amount)
    }
};
// 3. Tabulation Solution
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: fill the first row (using only coins[0])
        for (int den = 0; den <= amount; ++den) {
            if (den % coins[0] == 0) {
                dp[0][den] = 1;
            }
        }

        for (int idx = 1; idx < n; ++idx) {
            for (int den = 0; den <= amount; ++den) {
                int notPick = dp[idx - 1][den];
                int pick = (den >= coins[idx]) ? dp[idx][den - coins[idx]] : 0;
                dp[idx][den] = pick + notPick;
            }
        }

        return dp[n - 1][amount];
        // Time Complexity: O(n * amount)
        // Space Complexity: O(n * amount)
    }
};

// 4. Space Optimised Tabulation Solution
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> dp(amount + 1, 0);

        dp[0] = 1; // Base case: 1 way to make amount 0 (no coins)

        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
        // Time Complexity: O(n * amount)
        // Space Complexity: O(amount)
    }
};
