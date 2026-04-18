// 3783. Mirror Distance of an Integer
// https://leetcode.com/problems/mirror-distance-of-an-integer

// Concepts :: Reversal of a Number

// Reversing an integer by iteratively extracting digits and reconstructing the number in reverse order.


class Solution {
public:
    int reverseNum(int num){

        int revNum = 0;

        while(num != 0){

            revNum = revNum*10 + num%10;
            num/=10;
        }

        return revNum;

    }
    int mirrorDistance(int n) {
        
        int revNum = reverseNum(n);
        return abs(n - revNum);
    }
};

// Time Complexity : O(logN)
// Space Complexity : O(1)