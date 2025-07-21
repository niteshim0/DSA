// Recursive Solution
class Solution {
public:
    int maxProfitSolver(int idx,int trans,vector<int>& prices,int k){
        if(idx == prices.size() || trans == 2*k) return 0;
        
        int profit = 0;
        if(trans%2==0){
            int buy = -prices[idx] + maxProfitSolver(idx+1,trans+1,prices,k);
            int notBuy = maxProfitSolver(idx+1,trans,prices,k);
            profit = max(buy,notBuy);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+1,trans+1,prices,k);
            int notSell = maxProfitSolver(idx+1,trans,prices,k);
            profit = max(sell,notSell);
        }
        return profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        return maxProfitSolver(0,0,prices,k);
    }
};
// Time Complexity : O(2^N)
// Space Complexity : O(N)

// Memoization Solution
class Solution {
public:
    int maxProfitSolver(int idx,int trans,vector<int>& prices,int k,vector<vector<int>>& dp){
        if(idx == prices.size() || trans == 2*k) return 0;

        if(dp[idx][trans]!=-1) return dp[idx][trans];
        
        int profit = 0;
        if(trans%2==0){
            int buy = -prices[idx] + maxProfitSolver(idx+1,trans+1,prices,k,dp);
            int notBuy = maxProfitSolver(idx+1,trans,prices,k,dp);
            profit = max(buy,notBuy);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+1,trans+1,prices,k,dp);
            int notSell = maxProfitSolver(idx+1,trans,prices,k,dp);
            profit = max(sell,notSell);
        }
        return dp[idx][trans] = profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return maxProfitSolver(0,0,prices,k,dp);
    }
};

// Time Complexity : O(N*2k)
// Space Complexity : O(N) + O(N*2k)

// Tabulation Solution
class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        // base case gets included;
        for(int idx = n-1;idx>=0;idx--){
            for(int trans = 2*k-1;trans>=0;trans--){
                int profit = 0;
                if(trans%2==0){
                    int buy = -prices[idx] + dp[idx+1][trans+1];
                    int notBuy = dp[idx+1][trans];
                    profit = max(buy,notBuy);
                }else{
                    int sell = prices[idx] + dp[idx+1][trans+1];
                    int notSell = dp[idx+1][trans];
                    profit = max(sell,notSell);
                }
                dp[idx][trans] =  profit;
            }
        }
        return dp[0][0];
    }
};

// Time Complexity : O(N*2k)
// Space Complexity : O(N*2k)

// Space Optimized Tabulation Solution
class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2*k+1,0) , curr(2*k+1,0);
        // base case already gets included

        for(int idx = n-1;idx>=0;idx--){
            for(int trans = 2*k-1;trans>=0;trans--){
                int profit = 0;
                if(trans%2==0){
                    int buy = -prices[idx] + ahead[trans+1];
                    int notBuy = ahead[trans];
                    profit = max(buy,notBuy);
                }else{
                    int sell = prices[idx] + ahead[trans+1];
                    int notSell = ahead[trans];
                    profit = max(sell,notSell);
                }
                curr[trans] =  profit;
            }
            ahead = curr;
        }
        return ahead[0];
    }
};

// Time Complexity : O(N*2k)
// Space Complexity : O(2k)
