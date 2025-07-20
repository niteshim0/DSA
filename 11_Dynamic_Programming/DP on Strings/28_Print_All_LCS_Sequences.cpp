class Solution {
public:
    string printlongestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size() , n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        for(int idx1 = 0;idx1<=n1;idx1++){
            dp[idx1][0] = 0;
        }
        for(int idx2 = 0;idx2<=n2;idx2++){
            dp[0][idx2] = 0;
        }

        for(int idx1 = 1;idx1<=n1;idx1++){
            for(int idx2 = 1;idx2<=n2;idx2++){
                if(text1[idx1-1] == text2[idx2-1]){
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                }else{
                    dp[idx1][idx2] = max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
                }
            }
        }

        int len = dp[n1][n2];

        string ans(len,'#');
        int idx = len-1;
        int idx1 = n1 , idx2 = n2;
        while(idx1>0 && idx2>0){
            if(text1[idx1-1] == text2[idx2-1]){
                ans[idx] = text1[idx1-1];
                idx--;
                idx1--;
                idx2--;
            }else if(dp[idx1-1][idx2]>dp[idx1][idx2-1]){
                idx1--;
            }else{
                idx2--;
            }
        }

        return ans;
    }
};

// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + O(lcs)


// Printing all LCS Sequences

class Solution {
public:
    void allLCSUtil(string& s1, string& s2, vector<vector<int>>& dp, set<string>& ans,
                    int idx1, int idx2, string lcs) {
        if (idx1 == 0 || idx2 == 0) {
            reverse(lcs.begin(), lcs.end());
            ans.insert(lcs);
            return;
        }

        if (s1[idx1 - 1] == s2[idx2 - 1]) {
            allLCSUtil(s1, s2, dp, ans, idx1 - 1, idx2 - 1, lcs + s1[idx1 - 1]);
        } else {
            if (dp[idx1 - 1][idx2] == dp[idx1][idx2]) {
                allLCSUtil(s1, s2, dp, ans, idx1 - 1, idx2, lcs);
            }
            if (dp[idx1][idx2 - 1] == dp[idx1][idx2]) {
                allLCSUtil(s1, s2, dp, ans, idx1, idx2 - 1, lcs);
            }
        }
    }

    vector<string> allLCS(string &s1, string &s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        set<string> ans;
        allLCSUtil(s1, s2, dp, ans, n1, n2, "");
        return vector<string>(ans.begin(), ans.end());
    }
};

