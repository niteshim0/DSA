// 3856. Trim Trailing Vowels
// https://leetcode.com/problems/trim-trailing-vowels/description/

// Concepts :: Hashing + Vowels + Consonants Knowledge

// Approach :: Do as said

class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string trimTrailingVowels(string s) {
        int n = s.size();
        vector<int> hash(n,true);
        for(int i = n-1;i>=0;i--){
            if(isVowel(s[i])){
                hash[i] = false;
            }else{
                break;
            }
        }

        string ans = "";
        for(int i = 0;i<n;i++){
            if(hash[i]) ans+=s[i];
        }
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)