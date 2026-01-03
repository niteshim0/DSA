// https://leetcode.com/problems/reverse-string-prefix/description/
// 3794. Reverse String Prefix


// My Solution
// AC
class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();
        string str = "";
        for(int i = k-1;i>=0;i--){
            str+=s[i];
        }
        string nS = "";
        for(int i = k;i<n;i++){
            nS+=s[i];
        }
        return str + nS;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)

// Upsolving Time Improved Solution
// just reverse the front part in same string

class Solution {
public:
    string reversePrefix(string s, int k) {
        int start = 0 , end = k-1;
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
        return s;
    }
};
// Time Complexity : O(K)
// Space Complexity : O(1)
