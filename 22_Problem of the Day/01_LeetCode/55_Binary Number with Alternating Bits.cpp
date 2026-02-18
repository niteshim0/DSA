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

// Technique2 :: Use XOR trick
// 💡 Key Idea
// If bits alternate, then:
// n XOR (n >> 1) will produce a number with all 1s.
// A number with all 1s satisfies: x & (x + 1) == 0.
// let say n = 1 0 1 0 1 0 (an alternate bit number)
// then n>>1 = 0 1 0 1 0 1
// xor them  = 1 1 1 1 1 1 (all 1's) -- say it is x
// then x+1 =1 0 0 0 0 0 0 
// & them   =0 0 0 0 0 0 0 (it should result 0)

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)