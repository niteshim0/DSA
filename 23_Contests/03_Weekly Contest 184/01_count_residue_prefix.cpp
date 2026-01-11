// https://leetcode.com/problems/count-residue-prefixes/
// LC 3803. Count Residue Prefixes
// Concept :: Just loop
// One Strike :: I didn't interpret question right (Module Concept did get wrong n%n == 0)
class Solution {
public:
    int residuePrefixes(string s) {
        int j = 0;
        int n = s.size();
        vector<int> freq(26,0);
        int distinctCnt = 0;
        int ans = 0;

        while(j<n){
            freq[s[j]-'a']++;
            if(freq[s[j]-'a'] == 1) distinctCnt++;
            int req = (j+1)%3;
            if(req == distinctCnt) ans++;
            j++;
        }
        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)