// User function Template for C++

class Solution {
public:
    const int MOD = 1003;
    
     int fn(int i, int j, bool isTrue, string& s, vector<vector<vector<int>>>& dp) {
        if (i == j) {
            if (isTrue) {
                return s[i] == 'T';
            } else {
                return s[i] == 'F';
            }
        }
        
        if (dp[i][j][isTrue] != -1) {
            return dp[i][j][isTrue];
        }
            
        int res = 0;
            
        for (int k = i + 1; k < j; k += 2) {
            int leftTrue = fn(i, k - 1, true, s, dp);
            int leftFalse = fn(i, k - 1, false, s, dp);
            int rightTrue = fn(k + 1, j, true, s, dp);
            int rightFalse = fn(k + 1, j, false, s, dp);
            
            int ltrt = (leftTrue * rightTrue) % MOD;
            int ltrf = (leftTrue * rightFalse) % MOD;
            int lfrt = (leftFalse * rightTrue) % MOD;
            int lfrf = (leftFalse * rightFalse) % MOD;
            
            if (s[k] == '&') {
                res = isTrue ? (res + ltrt) % MOD : (res + ltrf + lfrt + lfrf) % MOD;
            } else if (s[k] == '|') {
                res = isTrue ? (res + ltrt + ltrf + lfrt) % MOD : (res + lfrf) % MOD;
            } else {
                res = isTrue ? (res + ltrf + lfrt) % MOD : (res + ltrt + lfrf) % MOD;
            }
        }
        
        return dp[i][j][isTrue] = res;
    }

    int countWays(int n, string s) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return fn(0, n - 1, 1 , s, dp);
    }
};