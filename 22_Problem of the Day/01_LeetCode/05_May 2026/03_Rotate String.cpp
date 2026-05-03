// LC 796 . 796. Rotate String
// https://leetcode.com/problems/rotate-string/description
// Concepts :: String Matching + Knuth–Morris–Pratt Algorithm
// Key Idea: Checking if one string is a rotation of another by concatenating it with itself.


class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string temp = s + s;
        return temp.find(goal) != string::npos;
    }
};

// Time Complexity : O(N) (avg)  O(N*N) (worst)
// Space Complexity : O(N)


// KMP Algorithm :: Don’t forget what you already matched."
// LPS tells: "If mismatch happens, how much of previous match can I reuse?"

class Solution {
public:
    vector<int> buildLPS(string& pattern){

        int n = pattern.size();
        vector<int> lps(n,0);

        int len;

        for(int i = 1 , len = 0 ; i < n ;){

            if(pattern[i] == pattern[len]){
                lps[i++] = ++len;
            }else{
                if(len) len = lps[len-1];
                else i++;
            }
        }

        return lps;
    }

    bool kmpSearch(string text, string pattern){

        vector<int> lps = buildLPS(pattern);

        int i = 0 , j = 0;

        while( i < text.size()){

            if(text[i] == pattern[j]){
                i++; j++;
                if(j == pattern.size()) return true;
            }else{
                if(j) j = lps[j-1];
                else i++;
            }
        }

        return false;
    }
    bool rotateString(string s, string goal) {
        
        if(s.size() != goal.size()) return false;

        return kmpSearch(s+s,goal);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


// Approach 3 :: Rolling Hash Approach (Rabin Karp Algorithm)

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        int n = s.size();
        string text = s + s;

        long long p = 31;          // base
        long long mod = 1e9 + 7;

        // compute p^(n-1)
        long long power = 1;
        for (int i = 0; i < n - 1; i++) {
            power = (power * p) % mod;
        }

        // hash of goal
        long long goalHash = 0;
        for (char c : goal) {
            goalHash = (goalHash * p + (c - 'a' + 1)) % mod;
        }

        // first window hash
        long long windowHash = 0;
        for (int i = 0; i < n; i++) {
            windowHash = (windowHash * p + (text[i] - 'a' + 1)) % mod;
        }

        // sliding window
        for (int i = 0; i <= text.size() - n; i++) {

            if (windowHash == goalHash) {
                // verify to avoid collision
                if (text.substr(i, n) == goal) return true;
            }

            // slide window
            if (i + n < text.size()) {
                windowHash = (windowHash - (text[i] - 'a' + 1) * power % mod + mod) % mod;
                windowHash = (windowHash * p + (text[i + n] - 'a' + 1)) % mod;
            }
        }

        return false;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)