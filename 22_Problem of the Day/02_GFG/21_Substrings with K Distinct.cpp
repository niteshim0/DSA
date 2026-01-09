// Substrings with K Distinct
// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1
// Concept :: Sliding Window(Variable Window Size) + Frequency Array


class Solution {
  public:
    int substringWithAtMostKDistinct(string&s,int k){
        int n = s.size();
        
        int i = 0 , j = 0 , res = 0;
        
        vector<char> hash(26,0);
        int distinctCnt = 0;
        
        while(j<n){
            
            hash[s[j]-'a']++;
            if(hash[s[j]-'a'] == 1) distinctCnt++;
            
            while(distinctCnt>k){
                hash[s[i]-'a']--;
                if(hash[s[i]-'a'] == 0) distinctCnt--;
                i++;
            }
            
            res+=(j-i+1);
            j++;
        }
        
        return res;
    }
    int countSubstr(string& s, int k) {
        
        return substringWithAtMostKDistinct(s,k) - substringWithAtMostKDistinct(s,k-1);
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(26) ~ O(1)