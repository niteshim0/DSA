class Solution
{
    public:
    //Memoization Approach
    int solve(int idx, int isBuying, vector<int>& price, vector<vector<vector<int>>>& memo, int tsc) {
    if (idx == price.size()) {
        return 0;
    }

    if (memo[idx][isBuying][tsc] != -1) {
        return memo[idx][isBuying][tsc];
    }

    int profit = 0;
    if (isBuying && tsc < 2) {
        int pick = -price[idx] + solve(idx + 1, 0, price, memo, tsc); 
        int notPick = solve(idx + 1, 1, price, memo, tsc); 
        profit = max(pick, notPick);
    } else if (!isBuying && tsc < 2) {
        int pick = price[idx] + solve(idx + 1, 1, price, memo, tsc + 1); 
        int notPick = solve(idx + 1, 0, price, memo, tsc); 
        profit = max(pick, notPick);
    }

    memo[idx][isBuying][tsc] = profit;
    return profit;
}

int maxProfit(vector<int>& price) {
    //Tabulation Apporach
    int n = price.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
    for(int idx = n-1;idx>=0;idx--){
        for(int isBuying = 0;isBuying<=1;isBuying++){
            for(int tsc = 0;tsc<=2;tsc++){
                if (isBuying && tsc < 2) {
                    int pick = -price[idx] + dp[idx + 1][0][tsc];
                    int notPick = dp[idx + 1][1][tsc]; 
                    dp[idx][isBuying][tsc] = max(pick, notPick);
                }else  if (!isBuying && tsc < 2) {
                    int pick = price[idx] + dp[idx + 1][1][tsc+1];
                    int notPick = dp[idx + 1][0][tsc]; 
                    dp[idx][isBuying][tsc] = max(pick, notPick);
                }
            }
        }
    }
    return dp[0][1][0];
}