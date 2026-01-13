// Minimum Window Subsequence
// https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

// Approach I : Simply Brute Force (constraints on the lower side on this ques)

class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        if (m > n) return "";

        int minLen = INT_MAX;
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[0]) continue;

            int ptr1 = i, ptr2 = 0;

            while (ptr1 < n && ptr2 < m) {
                if (s1[ptr1] == s2[ptr2]) {
                    ptr2++;
                }
                ptr1++;
            }

            if (ptr2 == m) {
                int len = ptr1 - i;
                if (len < minLen) {
                    minLen = len;
                    ans = s1.substr(i, len);
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(1)



// Approach II : Optimal Approach (Two Pointer + Backtracking)

/*💡 Idea

1.Forward scan to find a window where s2 is a subsequence of s1
2.Once found, backtrack to shrink the window from the left
3.Keep track of the minimum length window
4.Continue scanning for better answers

This ensures we don’t restart from every index → much faster.*/


class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX;
        int start = -1;

        int i = 0; 
        while (i < n) {
            
            int j = 0;
            
            // Forward scan
            while (i < n) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == m) break;
                }
                i++;
            }

            if (j < m) break; // s1 reaches its ends ,
            //but still there is no any sign of s2
            // no point in searching anymore
            
            int end = i;
            j = m - 1;
            
            // Backtracking
            while (i >= 0) {
                if (s1[i] == s2[j]) {
                    j--;
                    if (j < 0) break;
                }
                i--;
            }

            int len = end - i + 1;
            if (len < minLen) {
                minLen = len;
                start = i;
            }

    
            i = i + 1;
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};

// Time Complexity : O(N) // Sometimes two loops doesn't mean O(N^2)
// Space Complexity : O(N)