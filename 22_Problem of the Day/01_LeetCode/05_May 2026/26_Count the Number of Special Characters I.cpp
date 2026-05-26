// LC 3120 :: Count the Number of Special Characters I
// https://leetcode.com/problems/count-the-number-of-special-characters-i/description/

// Concepts :: Hashing

// Key Idea :: Hash the characters , and cnt them if they are present in both upper and lower hashset.


class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> up(26,0);
        vector<int> lr(26,0);

        for(char& ch : word){

            if(ch>='a' && ch<='z'){
                lr[ch-'a']++;
            }else{
                up[ch-'A']++;
            }
        }

        int cnt = 0;

        for(int i = 0 ; i < 26 ; i++){

            if(up[i] && lr[i]){
                cnt++;
            }
        }

        return cnt;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)