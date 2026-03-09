// Largest number in one swap
// https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1
// Concepts :: Greedy

// Approach :: Traverse from right to left and track the maxIdx , if violations arises swap those.

class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        int maxIdx = n - 1;
        int left = -1, right = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(s[i] > s[maxIdx]) {
                maxIdx = i;
            }
            else if(s[i] < s[maxIdx]) {
                left = i;
                right = maxIdx;
            }
        }

        if(left != -1) swap(s[left], s[right]);
        return s;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)