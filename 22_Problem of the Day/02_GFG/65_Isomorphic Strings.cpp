// Isomorphic Strings
// https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

// Concepts :: Isomorphic String + Hashing of Characters + Conditional Logic

// Approach :: Map every element of string first to second , and every element of string second to first , if discrepancy arise return false;

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        
        vector<int> hash1(26,-1);
        vector<int> hash2(26,-1);
        int n = s1.size();
        
        for(int i = 0;i<n;i++){
            char ch1 = s1[i];
            char ch2 = s2[i];
            
            int need1 = ch1 - 'a';
            int need2 = ch2 - 'a';
            
            if(hash1[need1]!=-1){
                if(hash1[need1]!=need2) return false;
            }else if(hash2[need2]!=-1){
                if(hash2[need2]!=need1) return false;
            }else{
                hash1[need1] = need2;
                hash2[need2] = need1;
            }
        }
        
        return true;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)