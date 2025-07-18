// Recursive Solution
class Solution {
public:
    int distinctSub(int idx1,int idx2,string s,string t){
        if(idx2<0) return 1;
        if(idx1<0) return 0;

        if(s[idx1] == t[idx2]){
            return distinctSub(idx1-1,idx2-1,s,t) + distinctSub(idx1-1,idx2,s,t);
        }else{
            return distinctSub(idx1-1,idx2,s,t);
        }
    }
    int numDistinct(string s, string t) {
        int n1 = s.size() , n2 = t.size();
        return distinctSub(n1,n2,s,t);
    }
};

// Time Complexity : O(2^N)
// Space Complexity : O(N + M)

// Memoization (Top Down Approach) Solution
class Solution {
public:
    int distinctSub(int idx1,int idx2,string s,string t,vector<vector<int>>& dp){
        if(idx2<0) return 1;
        if(idx1<0) return 0;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(s[idx1] == t[idx2]){
            return dp[idx1][idx2] = distinctSub(idx1-1,idx2-1,s,t,dp) + distinctSub(idx1-1,idx2,s,t,dp);
        }else{
            return dp[idx1][idx2] =  distinctSub(idx1-1,idx2,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n1 = s.size() , n2 = t.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return distinctSub(n1-1,n2-1,s,t,dp);
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M) + O(N+M)

// Tabulation Solution
class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<double>> dp(n1 + 1, vector<double>(n2 + 1, 0));

        for (int i = 0; i <= n1; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n1][n2];
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

// Space Optimized Tabulation Solution
class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<double> prev(n2 + 1, 0) , curr(n2+1,0);
        prev[0] = 1;

        for (int i = 1; i <= n1; i++) {
            curr[0] = 1;
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[n2];
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(2*N)

// 1D Array Optimization

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<double> prev(n2 + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n1; i++) {
            for (int j = n2; j >=1 ;j--) {
                if (s[i - 1] == t[j - 1]) {
                    prev[j] = prev[j - 1] + prev[j];
                } else {
                    prev[j] = prev[j];
                }
            }
        }

        return prev[n2];
    }
};
// Time Complexity : O(N*M)
// Space Complexity : O(N)
