// LC 1888. Minimum Number of Flips to Make the Binary String Alternating
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/


// Concepts :: String Concatenation + Bit Manipulation + Cyclic Shift + Sliding Window + Binary Concept 

// Reacap
// Remember two days earlier
// there is one question , we will do the same thing here
// LC 1758. Minimum Changes To Make Alternating Binary String 
// by including sliding window

// Other way

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

// Intuition
// Optimized Sliding Window
// To achieve O(n) complexity, we maintain the mismatch states incrementally.

// I :: First Pass
// In the first loop, we compute the total mismatch count for both pattern:

// op[0] − against the pattern 101...
// op[1] − against the pattern 010...

// again, this is basically the previous problem.

// Second Pass
// Then, as the window slides one position to the right, only two elements change:

// The character exiting the left boundary and the character entering the right boundary.
// We can simulate the cyclic shift without physical string concatenation by utilizing a virtual index:

// Remove the mismatch contribution of the exiting character s[i] at its original index i.
// While appending the same character to the right boundary at the virtual index n+i.


// Simply return the minimum operation across all windows.

class Solution {
public:
    int minFlips(string s) {
        int op[2] = {0,0};
        int n = s.size();
        for(int i = 0;i<n;i++){
            op[(s[i]^i)&1]++;
        }

        int mini = min(op[0],op[1]);

        // simple sliding window
        // left side gets removed , right side gets added
        for(int i = 0;i<n-1;i++){
            op[(s[i]^i)&1]--;
            op[(s[i]^(n+i))&1]++;
            mini = min(mini,min(op[0],op[1]));
        }
        return mini;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)