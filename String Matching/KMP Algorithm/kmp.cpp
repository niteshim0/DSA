vector<int> KMPAlgo(string s){
        int n = s.size();
        vector<int> lps(n,0);
        for(int i = 1;i<n;i++){
            int prev_idx = lps[i-1];
            while(prev_idx>0 && s[i]!=s[prev_idx]){
                prev_idx = lps[prev_idx-1];
            }
            lps[i] = prev_idx + (s[i]==s[prev_idx] ? 1 : 0);
        }
        return lps;
}