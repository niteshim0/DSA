// LC 3120 :: Count the Number of Special Characters I
// https://leetcode.com/problems/count-the-number-of-special-characters-i/description/

// Concepts :: Hashing

// Key Idea :: Hash the characters , and cnt them if they are present in both upper and lower hashset + firstUpperOccurence of upperCase characters , and lastOccurrence of every lowercase distinct characters.(we will check all the things on the basis of this only)


class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int n = word.size();

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

        vector<int> lowerLast(26,0);
        vector<int> upperFirst(26,0);

        for(int i =  0 ; i < n ; i++){
            char ch = word[i];
            if(ch>='a' && ch<='z'){
                lowerLast[ch-'a'] = i;
            }
        }

        for(int i =  n-1 ; i>=0 ; i--){
            char ch = word[i];
            if(ch>='A' && ch<='Z'){
                upperFirst[ch-'A'] = i;
            }
        }

        for(int i = 0 ; i < 26 ; i++){

            if(up[i] && lr[i] && upperFirst[i] > lowerLast[i] ){
                cnt++;
            }
        }

        return cnt;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)
