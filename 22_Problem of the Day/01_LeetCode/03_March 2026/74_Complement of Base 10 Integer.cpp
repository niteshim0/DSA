// LC 1009. Complement of Base 10 Integer
// https://leetcode.com/problems/complement-of-base-10-integer/description/
// Concepts :: Binary <-> Decimal Conversion + Bit Manipulation + Bit Propagation + Bitwise operators


// Approach :: Since we want complement , we just need to flip the bits , we will create mask with all 1's having same length as binary length of given number and the XOR the mask with given number , we will get our result , although the 0 and larger numer(31 bits) case need to be handled carefully.

// Technique 1 : Create Mask by Traversal
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mask = 0 ;
        int temp = n;

        while(temp){
            mask = (mask<<1 | 1);
            temp>>=1;
        }

        return n^mask;
    }
};
// Time Complexity : O(logn) (or dare I say O(1) , since ques consist of only integers , and they will not exceed 31 bits)
// Space Complexity : O(1)
// -> Most complete solution handles every case successfully.

// Technique 2 :: Counting the no of bits in given number ,and then creating mask
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mask = (1<<(int)(log2(n)+1)) - 1;
        return n^mask;
    }
};
// Time Complexity : O(logn) (or dare I say O(1) , since ques consist of only integers , and they will not exceed 31 bits)
// Space Complexity : O(1)
// -> Fails for larger numbers during mask creation

// Technique 3 :: Bit Propagation
// The mask trick fills all bits to the right of the highest set bit with 1s.
/* Why we shift by 1,2,4,8,16 ?
Because each step doubles the propagation range.

1 bit
2 bits
4 bits
8 bits
16 bits

This guarantees covering all 32 bits in constant time.
*/
class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 1;

        int mask = num;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;

        return num ^ mask;
    }
};
// TC :: O(1)
// SC :: O(1)

