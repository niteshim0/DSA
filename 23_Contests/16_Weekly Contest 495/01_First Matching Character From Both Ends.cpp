// LC 3884. First Matching Character From Both Ends
// https://leetcode.com/problems/first-matching-character-from-both-ends/description/
// Concepts :: Traversals


class Solution {
public:
    int firstMatchingIndex(string s) {

        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i] == s[n-i-1]) return i;
        }

        return -1;
    }
};

// Time Complexity : O(N)
// Space Complexity:  O(1)