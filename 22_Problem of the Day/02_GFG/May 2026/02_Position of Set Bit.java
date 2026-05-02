// 02. Position of Set Bit
// https://www.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

// Concepts :: Bit Manipulation

// Approach :: First check if it contains only one set bit(power of 2) or not
// if it does then do right shift till you find that set bit.

class Solution {
    public int findPosition(int n) {
        
        // Check if n has only one set bit
        if(n == 0 || (n & (n - 1)) != 0) return -1;
        
        int pos = 1;
        
        while((n & 1) == 0){
            n = n >> 1;
            pos++;
        }
        
        return pos;
    }
}