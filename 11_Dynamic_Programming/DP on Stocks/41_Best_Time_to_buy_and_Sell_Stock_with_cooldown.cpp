// Recursive Solution

class Solution {
public:
    int maxProfitSolver(int idx,int buy , vector<int>& prices){
        if(idx >= prices.size()) return 0;

        int profit = 0;

        if(buy){
            int buying = -prices[idx] + maxProfitSolver(idx+1,0,prices);
            int notBuying = maxProfitSolver(idx+1,1,prices);
            profit = max(buying,notBuying);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+2,1,prices);
            int notSell = maxProfitSolver(idx+1,0,prices);
            profit = max(sell,notSell);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return maxProfitSolver(0,1,prices);
    }
};

// Time Complexity : O(2^N)
// Space Complexity : O(N)

class Solution {
public:
    int maxProfitSolver(int idx,int buy , vector<int>& prices,vector<vector<int>>& dp){
        if(idx >= prices.size()) return 0;

        int profit = 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        if(buy){
            int buying = -prices[idx] + maxProfitSolver(idx+1,0,prices,dp);
            int notBuying = maxProfitSolver(idx+1,1,prices,dp);
            profit = max(buying,notBuying);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+2,1,prices,dp);
            int notSell = maxProfitSolver(idx+1,0,prices,dp);
            profit = max(sell,notSell);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return maxProfitSolver(0,1,prices,dp);
    }
};

// Time Complexity : O(2*N)
// Space Complexity : O(N*2) + O(N)

// Tabulation Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){
               int profit = 0;
               if(buy){
                int buying = -prices[idx] + dp[idx+1][0];
                int notBuying = dp[idx+1][1];
                profit = max(buying,notBuying);
               }else{
                int sell = prices[idx] + dp[idx+2][1];
                int notSell = dp[idx+1][0];
                profit = max(sell,notSell);
            }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// Time Complexity : O(2*N)
// Space Complexity : O(N*2)