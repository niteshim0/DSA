// https://leetcode.com/problems/reverse-bits/
// LC 190. Reverse Bits
// Concepts :: Binary to Decimal and Decimal to Binary Conversion + Bit Manipulation


// Approach :: Rememeber we have to deal with all 32 bits , so when reversing even if that number binary conversion is not that long , when we reverse those 0 contributes significantly to the answer.


// Technique 1 :: Use a 32 size vector to store the bits at every place and then use the same vector to get the reverse version of that number.

class Solution {
public:
    int reverseBits(int n) {
        if(n<=1) return n;

        vector<int> binaryNo(32,0);

        for(int i = 0;i<32;i++){
            int rem = n%2;
            binaryNo[i] = rem;
            n>>=1;
        }

        // binary No is already reversed 

        int reverseNo = 0;
        for(int i = 0;i<32;i++){
            reverseNo = reverseNo*2 + binaryNo[i];
        }

        return reverseNo;

    }
};

// Time Complexity : O(32) // constant solution
// Space Complexity : O(32)
// not good for interviews


// but can be improved 
// we will reverse along without taking help of any other spaces
class Solution {
public:
    int reverseBits(int n) {
        if(n<=1) return n;

        int ans = 0;

        for(int i = 0;i<32;i++){
            ans = ans<<1 | (n&1);
            n>>=1;
        }

        return ans;
    }
};

// Time Complexity : O(32) 
// Space Complexity : O(1)
// best for interviews


// Follow up: If this function is called many times, how would you optimize it?
// I think if something is called many times , precomputation is always one of the best option , that's exactly what we will do here
// Precomputation + Lookup Table

// --> Optimization Idea (Key Insight)

// 1.Reverse bits byte by byte (8 bits).
// 2.There are only 256 possible 8-bit values.
// 3.Precompute their reversed values once.
// 4.Reuse them for every function call.


// Explaination of its working
/*
32 bit integer  == 4 bytes
Originally :: [ byte3 ][ byte2 ][ byte1 ][ byte0 ]

//When reversing bits, byte order also reverses:

After reversal :: [ rev(byte0) ][ rev(byte1) ][ rev(byte2) ][ rev(byte3) ]

// Extracting Each Bye
n&(11111111) --> B0
(n>>8) & (11111111) --> B1
(n>>16) & (11111111) --> B2
(n>>24) & (11111111) --> B3

--> What table[x] gives

table[x] = bit-reversed value of that byte

Example:
x = 00010110
table[x] = 01101000

// And give them each of the reversed byte right position in reverse no
// i.e now MSB -> LSB order should be [rev(B0)][rev(B1)][rev(B2)][rev(B3)]

Why OR (|)?

To merge all four bytes into one number.
Think of it as assembling:

[ 10101010 ][ 00001111 ][ 11110000 ][ 00110011 ]
*/


class Solution {
public:
    int reverseBits(int n) {
       // Follow up: If this function is called many times, how would you optimize it?
       if(n<=1) return n;

       static bool initialized = false;
       static int table[256];
       const int MASK = 0b11111111;   // binary



       if(!initialized){
           for(int i = 0;i<256;i++){
             int x = i , res = 0;
             for(int j = 0;j<8;j++){
                res = (res<<1) | (x&1);
                x>>=1;
             }
             table[i] = res;
           }
          
       }

        return (table[n & MASK] << 24) |  // B0 goes I 
                                     
               (table[(n >> 8) & MASK] << 16) | // B1 goes II

               (table[(n >> 16) & MASK] << 8) |  // B2 goes III

               (table[(n >> 24) & MASK]); // B3 goes last(IV)


    }
};

// first time calls --> O(256*8)
// after that O(1)


// Time Complexity : O(1)
// Space Complexity : O(256);
// best for interviews



// if interview wanted something further , we will use one divide and conquer approach
// not simple , need to rememember
/*
--> Optimization without extra space
Divide & Conquer using Bit Masking (O(1), O(1))


Instead of reversing bit-by-bit, we swap bits in groups:
1. Swap 16-bit halves
2. Swap 8-bit blocks
3. Swap 4-bit blocks
4. Swap 2-bit blocks
5. Swap 1-bit blocks

Each step halves the problem.
// it overall reverses and gives the correct result.
*/


class Solution {
public:
    int reverseBits(int n) {

        // swap 16-bit halves
        n = (n >> 16) | (n << 16);

        // swap 8-bit blocks
        n = ((n & 0b11111111000000001111111100000000) >> 8) |
            ((n & 0b00000000111111110000000011111111) << 8);

        // swap 4-bit blocks
        n = ((n & 0b11110000111100001111000011110000) >> 4) |
            ((n & 0b00001111000011110000111100001111) << 4);

        // swap 2-bit blocks
        n = ((n & 0b11001100110011001100110011001100) >> 2) |
            ((n & 0b00110011001100110011001100110011) << 2);

        // swap individual bits
        n = ((n & 0b10101010101010101010101010101010) >> 1) |
            ((n & 0b01010101010101010101010101010101) << 1);

        return n;
    }
};

// Time Complexity :: O(1)
// Space Complexity : O(1)


// It can't be optimized further one improvement can be done binary--> hex because binary is usually long and error prone.


