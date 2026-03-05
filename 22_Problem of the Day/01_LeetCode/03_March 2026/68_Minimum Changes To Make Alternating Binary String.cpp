// LC 1758. Minimum Changes To Make Alternating Binary String
// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description

// Concepts :: Swapping + Logic + Alternate Thinking

// Approach :: For string to be alternating , there are only two possible ways ,
// either they start with '0' or they start with '1' , we will check for both , in which we require minimum change , that will be our answer

class Solution {
public:
    int minOperations(string s) {
        int cnt1 = 0 , cnt2 = 0;
        char start1 = '0' , start2 = '1';

        for(char &ch : s){
            if(ch != start1) cnt1++;
            if(ch != start2) cnt2++;
            swap(start1,start2);
        }

        return min(cnt1,cnt2);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)