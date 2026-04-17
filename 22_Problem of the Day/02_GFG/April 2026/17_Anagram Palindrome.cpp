// Anagram Palindrome
// https://www.geeksforgeeks.org/problems/anagram-palindrome4720/1

// Concepts :: Palindrome Check

// Approach :: If all the character count is even , then no problem and if odd count then it should be <=1


class Solution {
public:
    bool canFormPalindrome(string &s) {
        
        vector<int> hash(26, 0); 
                         
        for(char &ch : s){
            hash[ch - 'a']++;
        }    
        
        int cnt = 0; 
                                                                                                               
        for(int i = 0; i < 26; i++){ 
            if(hash[i] & 1) cnt++;
        }
        
        return cnt <= 1;      
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)