// Recursive Solution
class Solution {
public:
    bool matchFound(int idx1, int idx2, string& s, string& p) {
        if (idx1 < 0 && idx2 < 0) return true;
        if (idx2 < 0 && idx1 >= 0) return false;
        if (idx1 < 0 && idx2 >= 0) {
            for (int i = 0; i <= idx2; i++) {
                if (p[i] != '*') return false;
            }
            return true;
        }

        if (s[idx1] == p[idx2] || p[idx2] == '?') {
            return matchFound(idx1 - 1, idx2 - 1, s, p);
        }
        else if (p[idx2] == '*') {
            return matchFound(idx1 - 1, idx2, s, p) || matchFound(idx1, idx2 - 1, s, p);
        }
        return false;
    }

    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        return matchFound(n1 - 1, n2 - 1, s, p);
    }
};

// 1 - based indexing Top Down Approach
class Solution {
public:
    bool matchFound(int idx1, int idx2, string& s, string& p, vector<vector<int>>& dp) {
        if (idx1 == 0 && idx2 == 0) return true;
        if (idx2 == 0 && idx1 > 0) return false;
        if (idx1 == 0 && idx2 > 0) {
            for (int i = 1; i <= idx2; i++) {
                if (p[i - 1] != '*') return false;
            }
            return true;
        }

        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '?') {
            return dp[idx1][idx2] = matchFound(idx1 - 1, idx2 - 1, s, p, dp);
        } else if (p[idx2 - 1] == '*') {
            return dp[idx1][idx2] = matchFound(idx1 - 1, idx2, s, p, dp) || matchFound(idx1, idx2 - 1, s, p, dp);
        }

        return dp[idx1][idx2] = false;
    }

    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return matchFound(n1, n2, s, p, dp);
    }
};


// Time Complexity : O((N*M))
// Space Complexity : O(N+M) + O(N*M)

// Tabulation Solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        dp[0][0] = 1;

        for (int idx1 = 1; idx1 <= n1; idx1++) {
            dp[idx1][0] = 0;
        }

        for (int idx2 = 1; idx2 <= n2; idx2++) {
            bool flag = true;
            for (int i = 1; i <= idx2; i++) {
                if (p[i - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][idx2] = flag;
        }

        for (int idx1 = 1; idx1 <= n1; idx1++) {
            for (int idx2 = 1; idx2 <= n2; idx2++) {
                if (s[idx1 - 1] == p[idx2 - 1] || p[idx2 - 1] == '?') {
                    dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
                } else if (p[idx2 - 1] == '*') {
                    dp[idx1][idx2] = dp[idx1 - 1][idx2] || dp[idx1][idx2 - 1];
                } else {
                    dp[idx1][idx2] = 0;
                }
            }
        }

        return dp[n1][n2];
    }
};
// Time Complexity : O((N*M))
// Space Complexity : O(N*M)