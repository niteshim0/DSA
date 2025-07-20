class Solution {
public :
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size() , n2 = text2.size();
        vector<int> prev(n2+1,0),curr(n2+1,0);
       // base case is already included in initialization

        for(int idx1 = 1;idx1<=n1;idx1++){
            for(int idx2 = 1;idx2<=n2;idx2++){
                if(text1[idx1-1] == text2[idx2-1]){
                    curr[idx2] = 1 + prev[idx2-1];
                }else{
                    curr[idx2] = max(prev[idx2],curr[idx2-1]);
                }
            }
            prev = curr;
        }

        return prev[n2];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return  longestCommonSubsequence(s,t);
    }
};

// Time Complexity : O(n1 * n2)
// Space Complexity : O(n2)