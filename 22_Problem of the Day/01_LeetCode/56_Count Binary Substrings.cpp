// LC 696. Count Binary Substrings
// https://leetcode.com/problems/count-binary-substrings/
// Concepts :: Two Pointers + Brain Required + Simulate on different test cases to observe a pattern

// Approach
// Idea
// A valid binary substring must:
// Have equal number of 0s and 1s
// All 0s are grouped together and all 1s are grouped together
// So every valid substring exists at the boundary of two consecutive groups

// Therefore, we only need to look at adjacent groups of same characters.


class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0 ;
        int n = s.size();
        int prev = 0 ;
        int cur = 1;

        for(int i = 1;i<n;i++){
            if(s[i-1] != s[i]){  // boundary encountered
                ans+=min(cur,prev);
                prev = cur;
                cur = 1;
            }else{
                cur++; // extend current group
            }
        }

        ans+=min(prev,cur);

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

// Explaination
// I maintain two counters:
// cur for the current group length and prev for the previous group length.
// Whenever the character changes, I add min(prev, cur) to the answer, shift cur into prev, and reset cur.
// At the end, I handle the last group similarly

// another a group based logic , similar , just that we are counting the groups on the fly in my prev solution

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int cnt = 1 , n = s.size();
        int ans = 0;

        for(int i = 1;i<n;i++){
            if(s[i] == s[i-1]) cnt++;
            else{
                groups.push_back(cnt);
                cnt = 1;
            }
        }

        groups.push_back(cnt);

        for(int i = 1;i<groups.size();i++){
            ans+=min(groups[i-1],groups[i]);
        }

        

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

