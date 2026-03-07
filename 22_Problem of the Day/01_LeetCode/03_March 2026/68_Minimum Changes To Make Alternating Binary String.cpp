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