// LC 1680 . Concatenation of Consecutive Binary Numbers
// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/

// Concepts :: Brute Force + Decimal<->Binary Conversion + Bit Shifting(Left and Right) + MOD Knowledge + Binary Lenght Calculation


// Approach I :: Brute Force
// Do what the ques says , whatever you feel like it

class Solution {
public:
    const int MOD = 1e9 + 7;
    int convertToDecimal(string& req){
        long long ans = 0;

        for(char c : req){
            ans = ((ans * 2) % MOD + (c - '0')) % MOD;
        }

        return ans;
    }
    string convertToBinary(int n){
        int temp = n;
        string ans = "";
        while(temp!=0){
            if(temp&1){
                ans = '1' + ans;
            }else{
                ans = '0' + ans;
            }
            temp>>=1;
        }
        return ans;
    }
    int concatenatedBinary(int n) {
        string req = "";
        for(int i = 1;i<=n;i++){
            req+=convertToBinary(i);
        }
        return convertToDecimal(req);
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(N*N) // string concatenation is real culprit


// think of removing the string concatenation
// if we don't need to go to conversion to binary then we also don't need string concatenation , so how to get rid of it
// you can see its not binary no req , its rather binary lenght required , because at the time of concatenatoin , the concatenation string goes with high power
// so just calculate the binary length , and then left shift the ans by that much ,
// we are good

// Approach II :: Bit Shifting + log2(N) for lenght calc
class Solution {
public:
    const int MOD = 1e9 + 7;
    int binaryLength(int n){
        return floor(log2(n)) + 1;
    }
    int concatenatedBinary(int n) {
        long long ans = 0;
        int len = 0;

        for(int i = 1; i <= n; i++){
            len = binaryLength(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }

        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)


// Approach III :: Only bit shifting , no binarylen calculation

// length only changes when number is power of 2 , we will just check it

class Solution {
public:
    const int MOD = 1e9 + 7;

    int concatenatedBinary(int n) {
        long long ans = 0;
        int len = 0;

        for(int i = 1; i <= n; i++){
            if((i & (i - 1)) == 0) len++;

            ans = ((ans << len) % MOD + i) % MOD;
        }

        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)

