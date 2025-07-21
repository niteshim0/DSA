//  Recursive Solution
class Solution {
public:
    int maxProfitSolver(int idx,int buy,int trans,vector<int>& prices){
        if(idx == prices.size() || trans == 0) return 0;

        int profit = 0;
        if(buy){
            int buying = -prices[idx] + maxProfitSolver(idx+1,0,trans,prices);
            int notBuying = maxProfitSolver(idx+1,1,trans,prices);
            profit = max(buying,notBuying);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+1,1,trans-1,prices);
            int notSell = maxProfitSolver(idx+1,0,trans,prices);
            profit = max(sell,notSell);
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return maxProfitSolver(0,1,2,prices);
    }
};
// Time Complexity : o(2^N)
// Space Complexity : O(N)

// Top Down Approach
class Solution {
public:
    int maxProfitSolver(int idx,int buy,int trans,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(idx == prices.size() || trans == 0) return 0;

        int profit = 0;
        if(dp[idx][buy][trans]!=-1) return dp[idx][buy][trans];

        if(buy){
            int buying = -prices[idx] + maxProfitSolver(idx+1,0,trans,prices,dp);
            int notBuying = maxProfitSolver(idx+1,1,trans,prices,dp);
            profit = max(buying,notBuying);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+1,1,trans-1,prices,dp);
            int notSell = maxProfitSolver(idx+1,0,trans,prices,dp);
            profit = max(sell,notSell);
        }

        return dp[idx][buy][trans] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(4, -1)));
        return maxProfitSolver(0,1,2,prices,dp);
    }
};

// Time Complexity : o(N*2*4)
// Space Complexity : O(N*2*4) + O(N)

// Bottom Up Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        for(int buy = 0;buy<=1;buy++){
            for(int trans = 0;trans<=2;trans++){
                dp[n][buy][trans] = 0;
            }
        }
        for(int idx = 0;idx<=n;idx++){
            for(int buy = 0;buy<=1;buy++){
                dp[idx][buy][0] = 0;
            }
        }

        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){
                for(int trans = 1;trans<=2;trans++){
                    int profit = 0;

                if(buy){
                    int buying = -prices[idx] + dp[idx+1][0][trans];
                    int notBuying = dp[idx+1][1][trans];
                    profit = max(buying,notBuying);
                }else{
                    int sell = prices[idx] + dp[idx+1][1][trans-1];
                    int notSell = dp[idx+1][0][trans];
                    profit = max(sell,notSell);
                }
                dp[idx][buy][trans] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};
// Time Complexity : o(N*2*4)
// Space Complexity : O(N*2*4)

// Space Optimized Bottom Up Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3,0));
        vector<vector<int>> curr(2, vector<int>(3,0));

        // base case gets initialized with the declaration

        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){
                for(int trans = 1;trans<=2;trans++){
                    int profit = 0;

                if(buy){
                    int buying = -prices[idx] + ahead[0][trans];
                    int notBuying = ahead[1][trans];
                    profit = max(buying,notBuying);
                }else{
                    int sell = prices[idx] + ahead[1][trans-1];
                    int notSell = ahead[0][trans];
                    profit = max(sell,notSell);
                }
                curr[buy][trans] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};

// Time Complexity : o(N*2*3)
// Space Complexity : O(2*3) // O(1)



// N*4 variation
// Recursion Solution
class Solution {
public:
    int maxProfitSolver(int idx,int trans,vector<int>& prices){
        if(idx == prices.size() || trans == 4) return 0;
        
        int profit = 0;
        if(trans%2==0){
            int buy = -prices[idx] + maxProfitSolver(idx+1,trans+1,prices);
            int notBuy = maxProfitSolver(idx+1,trans,prices);
            profit = max(buy,notBuy);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+1,trans+1,prices);
            int notSell = maxProfitSolver(idx+1,trans,prices);
            profit = max(sell,notSell);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return maxProfitSolver(0,0,prices);
    }
};

// Time Complexity : O(2^N)
// Space Complexity : O(N)

// Memoization Solution
class Solution {
public:
    int maxProfitSolver(int idx,int trans,vector<int>& prices,vector<vector<int>>& dp){
        if(idx == prices.size() || trans == 4) return 0;

        if(dp[idx][trans]!=-1) return dp[idx][trans];
        
        int profit = 0;
        if(trans%2==0){
            int buy = -prices[idx] + maxProfitSolver(idx+1,trans+1,prices,dp);
            int notBuy = maxProfitSolver(idx+1,trans,prices,dp);
            profit = max(buy,notBuy);
        }else{
            int sell = prices[idx] + maxProfitSolver(idx+1,trans+1,prices,dp);
            int notSell = maxProfitSolver(idx+1,trans,prices,dp);
            profit = max(sell,notSell);
        }
        return dp[idx][trans] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return maxProfitSolver(0,0,prices,dp);
    }
};

// Time Complexity : O(N*4)
// Space Complexity : O(N) + O(N*4)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        
        for(int idx = 0;idx<=n;idx++){
            dp[idx][4] = 0;
        }

        for(int idx = n-1;idx>=0;idx--){
            for(int trans = 0;trans<=3;trans++){
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

// Time Complexity : O(N*4)
// Space Complexity : O(N*4)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(5,0) , curr(5,0);
        // base case already gets included

        for(int idx = n-1;idx>=0;idx--){
            for(int trans = 0;trans<=3;trans++){
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
// Time Complexity : O(N*4)
// Space Complexity : O(5)

