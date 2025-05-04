class Solution {
  public:
    int longestKSubstr(string &s, int k){
        unordered_map<char,int> mp;
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxLen = -1;
        int cnt =0;
        while(r<n){
            mp[s[r]]++;
            if(mp.size()>k){
                int x = s[l];
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
                l++;
            }
            if(mp.size()==k){
                 maxLen = max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};
// Time Complexity : O(N) + O(log256)
// Space Complexity : O(256)