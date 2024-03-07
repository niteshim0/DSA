class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        string ans = "-1";
        for(int i = 0,j = 0;j<n;++j){
            string potential = s.substr(i,j-i+1);
            if(s.find(potential,j+1)!=-1) ans = potential;
            else i++;
        }
        return ans;
    }
};