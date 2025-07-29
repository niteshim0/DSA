// 1. Recursive Solution

// 2. Memoization Solution
// 3. Tabulation Solution
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        // Base Case: only first item is available
        for (int i = 0;i<=n; i++) {
            dp[0][i] = i * price[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int cap = 0; cap <= n; cap++) {
                int notPick = dp[idx-1][cap];
                int rodLen = idx+1;
                int pick = (rodLen<= cap) ? price[idx] + dp[idx][cap - rodLen] : INT_MIN;
                dp[idx][cap] = max(pick, notPick);
            }
        }

        return dp[n-1][n];
    }
};
/*
Time Complexity : O(n*n)
Space Complexity : O(n*n)
*/
// 4. Space Optimised Tabulation Solution
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1, 0);

        // Base Case: only first item is available
        for (int i = 0;i<=n; i++) {
            dp[i] = i * price[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int cap = 0; cap <= n; cap++) {
                int notPick = dp[cap];
                int rodLen = idx+1;
                int pick = (rodLen<= cap) ? price[idx] + dp[cap - rodLen] : INT_MIN;
                dp[cap] = max(pick, notPick);
            }
        }

        return dp[n];
    }
};
/*
Time Complexlity : O(n*n)
Space Complexity : O(n)
*/

// It is same as unbounded knapsack nothing difference.