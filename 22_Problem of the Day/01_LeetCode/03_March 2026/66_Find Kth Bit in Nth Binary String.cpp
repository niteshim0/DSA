// LC 1545.Find Kth Bit in Nth Binary String
// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/

// Concepts :: Simulation + Recursion + Divide and Conquer + Bit Manipulation


// Approach I : Brute Force
// Simply simulate the process

class Solution {
public:
    string invertAndReverse(string& str){
        string need = "";
        for(char& ch : str){
            if(ch == '0') need+='1';
            else need+='0';
        }
        reverse(need.begin(),need.end());
        return need;
    }
    char findKthBit(int n, int k) {
        string prev = "0";
        string current = "";

        for(int i = 2;i<=n;i++){
            current = prev + "1" + invertAndReverse(prev);
            prev = current;
            if(prev.size()>=k) break;
        }

        return prev[k-1];
    }
};

// Time Complexity : O(2^N)
// Space Complexity : O(2^N)

// Approach II :: Recursion
/* --> Intuition
Intuition
Instead of building the string from the base condition, let’s work backward from the largest string, which is efficient for large values of k.

According to the problem, each string Sn is formed from Sn−1.So, to find a specific bit in S, we can recursively break down Sn to Sn−1 until reaching S1.This suggests a recursive approach.

We can break down our recursive method into three parts:

If k is in the first half, it lies in Sn−1.We can recursively call our function with n-1 and the same k.

If k is exactly in the middle, we know the value is 1 based on the string construction rules, so we return 1.

The latter half of Sn is actually Sn−1, but flipped and reversed. To account for the reversal, we need to find the kth bit from the end. We can do so by calling the findKthBit function on Sn−1, but instead of k, we use the length of Sn minus k. The answer we get will be the kth bit but flipped. We just need to flip it back before returning it as our final answer.
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int len = 1<<n;
        int halfLen = len/2;

        if(k<halfLen) return findKthBit(n-1,k);
        else if( k == halfLen) return '1';
        else{
            char correspondingBit = findKthBit(n-1,len-k);
            return correspondingBit == '0' ? '1' : '0';
        }
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

// Approach 3: Iterative Divide and Conquer

// Intuition
// We can convert the recursive approach to an iterative one to avoid the excess stack space taken by the recursion.

// Our main idea stays the same: start with the largest string and repeatedly halve it until reaching the smallest string, S1.

// In the recursive approach, finding a bit in the second half of the string allowed us to immediately flip it due to the recursion handling any further inversions. Since that isn’t possible iteratively, we maintain an invertCount variable to track how many times we enter an inverted section. Once we find the kth bit, we check the parity of invertCount to determine if it needs to be flipped.

// We begin with the largest string length 2n−1 and loop while k is greater than 1. If k is in the middle, it represents the 1 added during string construction, so we simply return the bit based on invertCount. If k is in the second half, we mirror k to the corresponding bit in the first half and increment invertCount to indicate the inversion. Then, we move to the previous string in the series by halving the length.

// When the loop completes, k represents the first bit of the string (corresponding to S1). We return this bit, flipping it if necessary based on invertCount.

class Solution {
public:
    char findKthBit(int n, int k) {
        int invertCount = 0;
        int len = (1<<n) - 1;
        int halfLen = len/2;

        while(k>1){
            if(k == halfLen + 1){
                return invertCount%2 == 0 ? '1' : '0';
            }
            if(k > halfLen){
                k = len+1-k;
                invertCount++;
            }

            len/=2;
            halfLen/=2;
        }

        return invertCount%2 == 0 ? '0' : '1';
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

// more than sufficient till here , now I am going for overkill

// Approach 4 :: Bit Manipulation
class Solution {
public:
    char findKthBit(int n, int k) {

        int rightMostSetBit = k & -k; //Maximum power of 2 one can acheive for that k

        bool isInInvertedPart = ((k / rightMostSetBit) >> 1 & 1) == 1; // checking is it kth bit lies on inverted side

        bool originalBitIsOne = (k & 1) == 0;

        if (isInInvertedPart) {
            // If we're in the inverted part, we need to flip the bit
            return originalBitIsOne ? '0' : '1';
        } else {
            // If we're not in the inverted part, return the original bit
            return originalBitIsOne ? '1' : '0';
        }
    }
};

// TC : O(1)
// SC : O(1)