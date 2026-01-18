// LC 3805. Count Caesar Cipher Pairs
// https://leetcode.com/problems/count-caesar-cipher-pairs/
// Concept :: Cyclic Shift  
// Approach :: For every string , we normalize to at a level , and then see , how much away from it a version

class Solution {
public:
    string cyclicShift(string s) {
        
        int shift = s[0] - 'a';
        for (char &c : s) {
            c = (c - shift - 'a' + 26) % 26 + 'a';
        }
        return s;
    }

    long long countPairs(vector<string>& words) {
        
        unordered_map<string, long long> mp;
        long long ans = 0;

        for (string &word : words) {
            string key = cyclicShift(word);
            //cout<<key<<endl;
            ans += mp[key];   
            mp[key]++;
        }
        
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)
