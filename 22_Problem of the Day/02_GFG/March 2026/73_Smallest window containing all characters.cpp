// Smallest window containing all characters (Minimum Window Substring)
// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

// Concepts :: Variable Size Sliding Window + Hashing + Unique Frequency Logic


// Approach :: We will just track down the all subarrays , which contains all characters of p , and then if there any more char in hashS , we will reduce it , otherwise just cnt and take the ans.


class Solution {
public:
    string minWindow(string &s, string &p) {
        
        vector<int> hashS(26,0), hashP(26,0);
        
        int uniqueChars = 0, matchCount = 0;
        
        for(char &ch : p){
            hashP[ch-'a']++;
            if(hashP[ch-'a'] == 1) uniqueChars++;
        }
        
        int i = 0, j = 0, n = s.size();
        int start = -1, mini = INT_MAX;
        
        while(j < n){
            
            hashS[s[j]-'a']++;
            
            if(hashP[s[j]-'a'] > 0 && hashS[s[j]-'a'] == hashP[s[j]-'a'])
                matchCount++;
            
            if(matchCount == uniqueChars){
                
                while(i <= j && hashS[s[i]-'a'] > hashP[s[i]-'a']){
                    hashS[s[i]-'a']--;
                    i++;
                }
                
                int winSize = j - i + 1;
                
                if(winSize < mini){
                    start = i;
                    mini = winSize;
                }
            }
            
            j++;
        }
        
        if(start == -1) return "";
        return s.substr(start, mini);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(26) ~ O(1)