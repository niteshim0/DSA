// LC 2839. Check if Strings Can be Made Equal With Operations I
// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/

// Concept :: Enumeration + Simulation


// Key Idea :: Verifying character reachability based on fixed index swap constraints.

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1[0] != s2[0] && s1[0] != s2[2]) return false;
        if(s1[1] != s2[1] && s1[1] != s2[3]) return false;
        if(s1[2] != s2[0] && s1[2] != s2[2]) return false;
        if(s1[3] != s2[1] && s1[3] != s2[3]) return false;
        return true;
    }
};