// Tabulation Solution

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n1 = s1.size() , n2 = s2.size();
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        // base case already gets covered with intitialization
        
        int ans = 0;
        for(int idx1  = 1;idx1<=n1;idx1++){
            for(int idx2 = 1;idx2<=n2;idx2++){
                if(s1[idx1-1] == s2[idx2-1]){
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                    ans = max(ans,dp[idx1][idx2]);
                }else{
                    dp[idx1][idx2] = 0; // if not continuous characters get intitilized to zero.
                }
            }
        }
        
        return ans;
    }
};
// Time Complexity : O(n1 * n2)
// Space Complexity : O(n1 * n2)

// Space Optimized Tabulation Solution

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n1 = s1.size() , n2 = s2.size();
        
        vector<int> prev(n2+1,0) , curr(n2+1,0);
        
        // base case already gets covered with intitialization
        
        int ans = 0;
        for(int idx1  = 1;idx1<=n1;idx1++){
            for(int idx2 = 1;idx2<=n2;idx2++){
                if(s1[idx1-1] == s2[idx2-1]){
                    curr[idx2] = 1 + prev[idx2-1];
                    ans = max(ans,curr[idx2]);
                }else{
                    curr[idx2] = 0;
                }
            }
            prev = curr;
        }
        
        return ans;
    }
};

// Time Complexity : O(n1*n2)
// Space Complexity : O(n2)
