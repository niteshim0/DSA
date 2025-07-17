// Recursive Solution
class Solution {
public:
    int lcs(int idx1,int idx2,string text1,strinAg text2){
        if(idx1<0 || idx2<0) return 0;
        
        if(text1[idx1] == text2[idx2]){
            return 1 + lcs(idx1-1,idx2-1,text1,text2);
        }

        return max(lcs(idx1-1,idx2,text1,text2),lcs(idx1,idx2-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size() , n2 = text2.size();
        return lcs(n1-1,n2-1,text1,text2);
    }
};
// Time Complexity : O(2^n1 * 2*n2)
// Space Complexity : O(max(n1,n2)) // Auxiliary Stack Space

// Memoized Solution
class Solution {
public:
    int lcs(int idx1,int idx2,string text1,string text2,vector<vector<int>>& dp){
        if(idx1<0 || idx2<0) return 0;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        
        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + lcs(idx1-1,idx2-1,text1,text2,dp);
        }

        return dp[idx1][idx2] = max(lcs(idx1-1,idx2,text1,text2,dp),lcs(idx1,idx2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size() , n2 = text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return lcs(n1-1,n2-1,text1,text2,dp);
    }
};

// Time Complexity : O(n1 *n2)
// Space Complexity : O(n1*n2) + O(n1 + n2) // Auxiliary Stack Space

// Tabulation Solution
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
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

        return dp[n1][n2];
    }
};
// Time Complexity : O(n1*  n2)
// Space Complexity : O(n1+1*(n2+1));

// Space Optimized Tabulation Solution

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size() , n2 = text2.size();
        vector<int> prev(n2+1,0),curr(n2+1,0);

        for(int idx2 = 0;idx2<=n2;idx2++){
            prev[idx2] = 0;
        }

        for(int idx1 = 1;idx1<=n1;idx1++){
            for(int idx2 = 1;idx2<=n2;idx2++){
                if(text1[idx1-1] == text2[idx2-1]){
                    curr[idx2] = 1 + prev[idx2-1];
                }else{
                    curr[idx2] = max(prev[idx2],curr[idx2-1]);
                }
            }
            prev = curr;
        }

        return prev[n2];
    }
};

// Time Complexity : O(n1*  n2)
// Space Complexity : O(n2+1);