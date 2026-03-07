// LC 1888. Minimum Number of Flips to Make the Binary String Alternating
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/


// Concepts :: String Concatenation + Bit Manipulation + Cyclic Shift + Sliding Window + Binary Concept 

// Reacap
// Remember two days earlier
// there is one question , we will do the same thing here
// LC 1758. Minimum Changes To Make Alternating Binary String 
// by including sliding window

class Solution {
public:
//The array op automatically evaluates the minimum operation for both patterns:

// op[0] − against the pattern 101...
// op[1] − against the pattern 010...
    int minOperations(string s) {
        int op[2] = {0, 0};
        for (int i = 0; i < s.length(); i++)
            op[(s[i] ^ i) & 1]++;
        return min(op[0], op[1]);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)
