class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Build LCS table
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        int i = n1, j = n2;
        string scs;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs.push_back(str1[i - 1]);
                --i; --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs.push_back(str1[i - 1]);
                --i;
            } else {
                scs.push_back(str2[j - 1]);
                --j;
            }
        }

        while (i > 0) scs.push_back(str1[--i]);
        while (j > 0) scs.push_back(str2[--j]);

        reverse(scs.begin(), scs.end());
        return scs;
    }
};

// Time Complexity : O(n1*n2) // for building LCS Table + O(n1+n2) // for generateing SCS
// Space Complexity : O(n1 * n2) // for LCS Table