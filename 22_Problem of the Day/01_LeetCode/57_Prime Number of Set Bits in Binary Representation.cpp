// LC 762. Prime Number of Set Bits in Binary Representation
// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Concepts :: Sieve Of Erasthones + Set Bit Count


// Approach :: Iterate from left to right , and take calculate the set bit cnt in the process and check whether that cnt is prime or not , and increase your cnt as such (For prime check , one can use sieve of erasthones , or simple prime check , both will suffice)
// sieve will be overkill for such an easy problem (since set cnt Bit<=32 for integer range)

// Technique 1 :: Using Sieve
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int n = 33; // max set bits for int is 32
        vector<int> isPrime(n, 1);

        isPrime[0] = isPrime[1] = 0;

        for(int i = 2; i * i < n; i++){
            if(isPrime[i]){
                for(int j = i * i; j < n; j += i){
                    isPrime[j] = 0;
                }
            }
        }

        int cnt = 0;
        for(int i = left; i <= right; i++){
            int setBitCnt = __builtin_popcount(i);
            if(isPrime[setBitCnt]) cnt++;
        }

        return cnt;
    }
};

// Time Complexity : O(32loglog32) + O(right-left+1) ~ O(right-left+1)
// Space Complexity : O(32) ~ O(1)


// Technique 2
class Solution {
public:
    bool isPrime(int n){
        
        if(n<=1) return false;

        for(int i = 2;i*i<=n;i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++){
            int setBitCnt = __builtin_popcount(i);
            if(isPrime(setBitCnt)) cnt++;
        }

        return cnt;
    }
};
// Time Complexity : O(right-left+1)
// Space Complexity : O(1)


// Technique 3 :: BitMask Trick
// The number of set bits is at most 32. I pre-encode all prime counts into a single integer mask. After counting set bits using __builtin_popcount, I just check if the corresponding bit is set in the mask.

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // bitmask with prime positions set
        int primeMask = 
            (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) |
            (1 << 11) | (1 << 13) | (1 << 17) |
            (1 << 19) | (1 << 23) | (1 << 29) | (1 << 31);

        int cnt = 0;

        for (int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            if (primeMask & (1 << setBits)) {
                cnt++;
            }
        }
        return cnt;
    }
};

// TC : O(right-left+1)
// SC : O(1)

