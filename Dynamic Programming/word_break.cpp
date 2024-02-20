class Solution
{
public:
    int solve(int idx,string prefix,string &s,unordered_set<string>&dict){
        if(idx == s.size()) return 0;
        
        prefix+=s[idx];
        if(idx == s.size()-1){
            return (dict.find(prefix)!=dict.end());
        }
        int cut = 0;
        int notCut = 0;
        if(dict.find(prefix)!=dict.end()){
            cut = solve(idx+1,"",s,dict);
        }
        notCut = solve(idx + 1,prefix,s,dict);
        
        return cut || notCut; 
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_set<string> dict;
        for(auto &str : dictionary){
            dict.insert(str);
        }
        return solve(0,"",s,dict);
  }
}

//Tabulation Version
 int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_set<string> dict;
        for(auto &str : dictionary){
            dict.insert(str);
        }
        int N = s.length();
        vector<bool> dp(N + 1, false);
        dp[0] = true;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[N] ? 1 : 0;
    }