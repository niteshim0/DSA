// Recursive Solution
class Solution {
public:
    int maxProfitSolver(int idx,int buy , vector<int>& prices,int fee){
        if(idx == prices.size()) return 0;

        int profit = 0;

        if(buy){
            int buying = -prices[idx] + maxProfitSolver(idx+1,0,prices,fee);
            int notBuying = maxProfitSolver(idx+1,1,prices,fee);
            profit = max(buying,notBuying);
        }else{
            int sell = prices[idx] - fee + maxProfitSolver(idx+1,1,prices,fee);
            int notSell = maxProfitSolver(idx+1,0,prices,fee);
            profit = max(sell,notSell);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        return maxProfitSolver(0,1,prices,fee);
    }
};
// Time Complexity : O(2^N)
// Space Complexity : O(N)

// Memoization Solution
class Solution {
public:
    int maxProfitSolver(int idx,int buy , vector<int>& prices,vector<vector<int>>& dp,int fee){
        if(idx == prices.size()) return 0;

        int profit = 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        if(buy){
            int buying = -prices[idx] + maxProfitSolver(idx+1,0,prices,dp,fee);
            int notBuying = maxProfitSolver(idx+1,1,prices,dp,fee);
            profit = max(buying,notBuying);
        }else{
            int sell = prices[idx] - fee + maxProfitSolver(idx+1,1,prices,dp,fee);
            int notSell = maxProfitSolver(idx+1,0,prices,dp,fee);
            profit = max(sell,notSell);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return maxProfitSolver(0,1,prices,dp,fee);
    }
};
// Time Complexity : O(N*2)
// Space Complexity : O(N) + O(N*2)

// Tabulation Solution
class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){
               int profit = 0;
               if(buy){
                int buying = -prices[idx] + dp[idx+1][0];
                int notBuying = dp[idx+1][1];
                profit = max(buying,notBuying);
               }else{
                int sell = prices[idx] - fee + dp[idx+1][1];
                int notSell = dp[idx+1][0];
                profit = max(sell,notSell);
            }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
// Time Complexity : O(N*2)
// Space Complexity :O(N*2)

// Space Optimized Tabulation Solution
class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<int> prev(2,0) , curr(2,0);
        // base case gets included in intialization
        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){
               int profit = 0;
               if(buy){
                int buying = -prices[idx] + prev[0];
                int notBuying = prev[1];
                profit = max(buying,notBuying);
               }else{
                int sell = prices[idx] - fee + prev[1];
                int notSell = prev[0];
                profit = max(sell,notSell);
            }
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};
// Time Complexity : O(2*N)
// Space Complexity : o(2)
