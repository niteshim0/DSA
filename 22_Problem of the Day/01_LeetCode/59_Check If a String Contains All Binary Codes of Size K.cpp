// 1461. Check If a String Contains All Binary Codes of Size K
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Concepts :: Power Set Formula + Substring Logic + Sliding Window + Hashset

// Approach :: We will include all the k sizes substring in our hashset , if its size turns out to be 1<<k , it means all the substring gets found otherwise not.

// Every substring of length k represents one binary code.

// If we collect all distinct substrings of length k and their count becomes 2^k, then all codes exist.

// If even one is missing, answer is false.


class Solution {
public:
    string generateSubstr(int start,int end,string& s){
        string str = "";
        for(int i = start;i<=end;i++){
            str.push_back(s[i]);
        }

        return str;
    }
    bool hasAllCodes(string s, int k) {
        int distinctSubstr = 1<<k;
        unordered_set<string> st;

        int i = 0 , j = 0 , n = s.size();

        while(j<n){
            if(j-i+1 == k){
                string str = generateSubstr(i,j,s);
                st.insert(str);
                i++;
            }
            j++;
        }

        return distinctSubstr == st.size();
    }
};

// Time & Space Complexity

// Time: O(n * k)
// (k for substring generation at each step)

// Space: O(2^k * k)
// (storing all binary substrings)