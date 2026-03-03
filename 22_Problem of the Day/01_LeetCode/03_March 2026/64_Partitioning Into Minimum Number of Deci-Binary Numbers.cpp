// LC 1689. Partitioning Into Minimum Number of Deci-Binary Numbers
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

// Concepts :: Just use the brain (ADHOC Type Problem)

// Approach :: Think about if the input was only one digit. Then you need to add up as many ones as the value of this digit.If the input has multiple digits, then you can solve for each digit independently, and merge the answers to form numbers that add up to that input.Thus the answer is equal to the max digit.
// Its pretty simple straightforward ans but thinking it out is hell

// Dry Run
// Assume max digit in n is x.
// Because deci-binary only contains 0 and 1,
// we need at least x numbers to sum up a digit x.

// Now we contruct an answer,
// Take n = 135 as an example,
// we initialize 5 deci-binary number with length = 3,
// a1 = 000
// a2 = 000
// a3 = 000
// a4 = 000
// a5 = 000

// For the first digit, we fill the first n[0] number with 1
// For the second digit, we fill the first n[1] number with 1
// For the third digit, we fill the first n[2] number with 1

// So we have
// a1 = 111
// a2 = 011
// a3 = 011
// a4 = 001
// a5 = 001

// Finally, we have 111+11+11+1+1=135.

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
