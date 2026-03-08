// LC 3863. Minimum Operations to Sort a String
// https://leetcode.com/problems/minimum-operations-to-sort-a-string/description/

// Concepts :: Logical Thinking + Sorting + Limited Possiblity of Answers

// Approach :: There are only fixed no of cases arise
// if n == 1 -> always sorted -> return 0;
// if sorted string == given string -> return 0;
// if( n == 2) and its not sorted return -1 // only impossible case
// if(minChar is at firstIdx || maxChar is at lastIdx) then only 1 ops required
// if(maxChar is at fistIdx && minChar is at lastIdx) -> indicating something of reverse order -> and these both occur only once then ans will always be 3.
// in all other cases , its always possible to reach the ans in just 2 operations.

class Solution {
public:
    bool firstAndLastCheck(char maxChar,char minChar,string& str){
        int n = str.size();
        if(str[0]!=maxChar) return false;
        if(str[n-1]!=minChar) return false;

        for(int i = 1;i<n-1;i++){
            if(str[i] == minChar || str[i] == maxChar) return false;
        }
        return true;
    }
    int minOperations(string str) {
        int n = str.length();

        bool isSorted = true;
        char minChar = str[0];
        char maxChar = str[0];

        for (int i = 1; i < n; i++) {
            if (str[i] < str[i - 1])
                isSorted = false;

            minChar = min(minChar, str[i]);
            maxChar = max(maxChar, str[i]);
        }

        if (isSorted)
            return 0;

        if (n <= 2)
            return -1;

        if (str[0] == minChar || str[n - 1] == maxChar)
            return 1;

        if (firstAndLastCheck(maxChar,minChar,str)){
            // maxChar should present at only first position
            // minChar should be at last
            return 3;
        }

        return 2;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)