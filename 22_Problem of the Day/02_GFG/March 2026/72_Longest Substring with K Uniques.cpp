// Longest Substring with K Uniques
// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

// Concepts :: Sliding Window(Variable Window Size) + Hashing

// Approach :: Track the distinct elements in substring , if its greater than k , remove from start till its == k , then calculate the length of window ,
// if max window gets found , return it , if there is no any such window which contains exactly k uniques , return -1


class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        
        int distinct = 0;
        vector<int> hash(26,0);
        
        int i = 0 , j = 0 , n = s.size();
        
        int maxi = INT_MIN ;
        
        while(j<n){
            hash[s[j]-'a']++;
            if(hash[s[j]-'a'] == 1) distinct++;
            
            while(i<=j && distinct>k){
                hash[s[i]-'a']--;
                if(hash[s[i]-'a'] == 0) {
                    distinct--;
                }
                i++;
            }
            if(distinct == k){
                maxi = max(maxi,j-i+1);
            }
            j++;
        }
        
        return maxi == INT_MIN ? -1 : maxi;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(26) ~ O(1) // doesn't depend upon input size