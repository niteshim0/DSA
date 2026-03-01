// LC 1689. Partitioning Into Minimum Number of Deci-Binary Numbers
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

// Concepts :: Just use the brain (ADHOC Type Problem)

// Approach :: Think about if the input was only one digit. Then you need to add up as many ones as the value of this digit.If the input has multiple digits, then you can solve for each digit independently, and merge the answers to form numbers that add up to that input.Thus the answer is equal to the max digit.
// Its pretty simple straightforward ans but thinking it out is hell

class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;

        for(char& ch : n){
            int digit = ch - '0';
            maxi = max(maxi,digit);
        }

        return maxi;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
