// Recursive Solution
class Solution {
public:
    int minDis(int idx1,int idx2,string word1,string word2){
        if(idx1<0) return idx2 + 1;
        if(idx2<0) return idx1 + 1;

        if(word1[idx1] == word2[idx2]){
            return minDis(idx1-1,idx2-1,word1,word2);
        }else{
            int insert = 1 + minDis(idx1,idx2-1,word1,word2);
            int remove = 1 + minDis(idx1-1,idx2,word1,word2);
            int replace = 1 + minDis(idx1-1,idx2-1,word1,word2);
            return min(insert,min(remove,replace));
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size() , n2 = word2.size();
        return minDis(n1-1,n2-1,word1,word2);
    }
};

// Time Complexity : O(3^N)
// Space Complexity : O(n1 + n2)

// Memoization Solution(Top Down Approach)
class Solution {
public:
    int minDis(int idx1,int idx2,string word1,string word2,vector<vector<int>>& dp){
        if(idx1<0) return idx2 + 1;
        if(idx2<0) return idx1 + 1;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(word1[idx1] == word2[idx2]){
            return dp[idx1][idx2] =  minDis(idx1-1,idx2-1,word1,word2,dp);
        }else{
            int insert = minDis(idx1,idx2-1,word1,word2,dp);
            int remove = minDis(idx1-1,idx2,word1,word2,dp);
            int replace = minDis(idx1-1,idx2-1,word1,word2,dp);
            return dp[idx1][idx2] = 1 + min(insert,min(remove,replace));
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size() , n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return minDis(n1-1,n2-1,word1,word2,dp);
    }
};

// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2) + O(n1 + n2)

// Tabulation Solution
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size() , n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        for(int idx1 = 0;idx1<=n1;idx1++){
            dp[idx1][0] = idx1;
        }
        for(int idx2 = 0;idx2<=n2;idx2++){
            dp[0][idx2] = idx2;
        }

        for(int idx1 = 1;idx1<=n1;idx1++){
            for(int idx2 = 1;idx2<=n2;idx2++){
                if(word1[idx1-1] == word2[idx2-1]){
                    dp[idx1][idx2] = dp[idx1-1][idx2-1];
                }else{
                    int insert = dp[idx1][idx2-1];
                    int remove = dp[idx1-1][idx2];
                    int replace = dp[idx1-1][idx2-1];
                    dp[idx1][idx2] = 1 + min(insert,min(remove,replace));
                }
            }
        }
        return dp[n1][n2];
    }
};

// Time Complexity : O(n1*n2)
// Space Complexity : O(n1*n2)

// Space Optimized Tabulation Solution
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size() , n2 = word2.size();
        vector<int> prev(n2+1,0) , curr(n2+1,0);
        for(int idx2 = 0;idx2<=n2;idx2++){
            prev[idx2] = idx2;
        }

        for(int idx1 = 1;idx1<=n1;idx1++){
            curr[0] = idx1;
            for(int idx2 = 1;idx2<=n2;idx2++){
                if(word1[idx1-1] == word2[idx2-1]){
                    curr[idx2] = prev[idx2-1];
                }else{
                    int insert = curr[idx2-1];
                    int remove = prev[idx2];
                    int replace = prev[idx2-1];
                    curr[idx2] = 1 + min(insert,min(remove,replace));
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
};
// Time Complexity  : O(N1*N2)
// Space Complexity : O(N2)
