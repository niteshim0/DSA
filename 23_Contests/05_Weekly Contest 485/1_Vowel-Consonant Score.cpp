// LC 3813. Vowel-Consonant Score
// https://leetcode.com/problems/vowel-consonant-score/description/
// Concept :: Strings + Loops + Difference b/w char and string + floor

// Approach :: Do as said in the ques , it is the most optimal solution i can across(one can get rid of set)
// During Contest :: Solved

class Solution {
public:
    int vowelConsonantScore(string s) {
        unordered_set<char> st = {'a','e','i','o','u'};
        int c = 0 , v = 0;
        for(char& ch : s){
            if(isdigit(ch) || ch == ' ') continue;
            if(st.find(ch) == st.end()){
                c++;
            }else{
                v++;
            }
        }

        return c>0 ? v/c  : 0;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)