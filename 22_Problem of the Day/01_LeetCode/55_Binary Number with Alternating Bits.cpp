// 693. Binary Number with Alternating Bits
// https://leetcode.com/problems/binary-number-with-alternating-bits/description
// Concepts :: Bit Representation of Decimal + Iterating on bits 

// Approach :: Just track two adjacent bits , if they are same then continuous bits are same--> return false , otherwise return true.

// Technique 1 :: Iterating on bits
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        int temp = n;

        while(temp){
            int req = temp&1;
            if(req == prev) return false;
            prev = req;
            temp>>=1;
        }
        return true;
    }
};
// TC : log(n) where n = 2^31-1 == O(31) ~ O(1)
// SC : O(1)