class Solution {
public:
    static bool cmp(string& s1,string& s2){
        return s1.size() < s2.size();
    }
    bool isPossible(string &current , string& prev){
        int n = current.size() , m = prev.size();
        if(n-m!=1) return false;
        int i = 0,j = 0;
        while(i<n){
            if(current[i] == prev[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return (i==n && j==m);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int> dp(n,1);
        int lsc = 1;
        for(int i = 0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(isPossible(words[i],words[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            lsc = max(lsc,dp[i]);
        }
        return lsc;
    }
};
// Time Complexity : O(N*N*max(strLen))
// Space Complexity : O(N)