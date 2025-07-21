// Recursive Solution
class Solution {
public:
    int maxProfitSolver(int idx,int buy , vector<int>& prices){
        if(idx == prices.size()) return 0;

        int profit = 0;

        if(buy){
            int buying = -prices[idx] + maxProfitSolver(idx+1,0,prices);
            int notBuying = maxProfitSolver(idx+1,1,prices);
            profit = max(buying,notBuying);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+1,1,prices);
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

// Memoization Solution 
class Solution {
public:
    int maxProfitSolver(int idx,int buy , vector<int>& prices,vector<vector<int>>& dp){
        if(idx == prices.size()) return 0;

        int profit = 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        if(buy){
            int buying = -prices[idx] + maxProfitSolver(idx+1,0,prices,dp);
            int notBuying = maxProfitSolver(idx+1,1,prices,dp);
            profit = max(buying,notBuying);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+1,1,prices,dp);
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
// Space Complexity : O(2*N) + O(N)

// Tabulation Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0] = 0 , dp[n][1] = 0;
        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){
               int profit = 0;
               if(buy){
                int buying = -prices[idx] + dp[idx+1][0];
                int notBuying = dp[idx+1][1];
                profit = max(buying,notBuying);
               }else{
                int sell = prices[idx] + dp[idx+1][1];
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
// Space Complexity : O(2*N)

// Space Optimized Tabulation Solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
                int sell = prices[idx] + prev[1];
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
// Space Complexity : O(2)


// Greedy Solution of this question (good to have one more solution but most of the times interviewer will expect DP Approach)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int yesterday = INT_MAX;
        int profit = 0;
        for(auto today : prices){
            if(today - yesterday > 0){
                profit+=(today-yesterday);
            }
            yesterday = today;
        }
        return profit;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)