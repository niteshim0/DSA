//Memoization
class Solution
{
    public:
    const int MOD = 1e9 + 7;
    int solve(int idx1,int idx2,string &s,string& t,vector<vector<int>>&dp){
        if(idx2 == 0) return 1;
        if(idx1 == 0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int count = 0;
        if(s[idx1-1] == t[idx2-1]){
            count = (count%MOD + solve(idx1-1,idx2-1,s,t,dp)%MOD + solve(idx1-1,idx2,s,t,dp)%MOD)%MOD;
        }else{
            count = (count%MOD + solve(idx1-1,idx2,s,t,dp)%MOD)%MOD;
        }
        
        return dp[idx1][idx2] = count;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int n = s.size();
      int m = t.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
      return solve(n,m,s,t,dp);
    }
};
//Tabulation
  int subsequenceCount(string s, string t)
    {
      //Your code here
       int n = s.size();
       int m = t.size();
       vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

       for (int idx1 = 0; idx1 <= n; idx1++) {
           dp[idx1][0] = 1; 
        }

        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= m; idx2++) {
                if (s[idx1 - 1] == t[idx2 - 1]) {
                     dp[idx1][idx2] = (dp[idx1 - 1][idx2 - 1] % MOD + dp[idx1 - 1][idx2] % MOD) % MOD;
                } else {
                    dp[idx1][idx2] = dp[idx1 - 1][idx2] % MOD;
                }
            }
        }
    return dp[n][m];
    }