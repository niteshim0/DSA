// 4 Jan , 2026
// LC 1390. Four Divisors
// https://leetcode.com/problems/four-divisors/description

// Concept :: Math :: No of Divisors
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int totalSum = 0;
        vector<int> ans(6,0);
        for(int& num : nums){
            int cnt = 0;
            int idx = 0;
            for(int i = 1;i*i<=num;i++){
                if(cnt>4) break;
                if(num%i == 0){
                    ans[idx++] = i;
                    cnt++;
                    if(i!=num/i){
                        ans[idx++] = num/i;
                        cnt++;
                    }
                }
            }
            if(cnt == 4){
                for(int i = 0;i<6;i++){
                    if(i<4) totalSum+=ans[i];
                    ans[i] = 0;
                }
            }
        }
        return totalSum;
    }
};

// Time Complexity : O(N*sqrt(maxNumber in entire array)*4);
// Space Complexity : O(6)


// Approach II
// Little Bit More Optimized and there is Gotcha in it
// We need every number to have exactly 4 divisors
// so for every num>1 , two divisors can be 1 and num
// and other divisors can be someDiv  && someNum/someDiv 
// if someDiv == someNum/someDiv , only three divisors
// if someDiv != someNum/someDiv , only 4 divisors , thats what we want
// ans would be = 1 + n + someDiv + someNum/someDiv

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int totalSum = 0;
        for(int& num : nums){
            int lastDiv = 0;
            for(int div = 2;div*div<=num;div++){
                   if(num%div == 0){
                        if(lastDiv == 0){
                            lastDiv = div;
                        }else{
                            lastDiv = 0; // more than 4 divisors
                            break;
                        }
                   }
            }

            if(lastDiv>0 && lastDiv!=num/lastDiv){ // more than 4 divisors && only 3 divisors
                totalSum+=(1+num+lastDiv+num/lastDiv);
            }
        }
        return totalSum;
    }
};
// Time Complexity : O(N*sqrt(M))
// Space Complexity : O(1)

// Approach III
//A number has exactly four divisors only if it is either the cube of a prime or the product of two distinct primes
class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int n : nums) {

            // Case 1: n = p^3
            int p = round(cbrt(n));
            if ((long long)p * p * p == n && isPrime(p)) {
                totalSum += (1 + p + p * p + n);
                continue;
            }

            // Case 2: n = p * q (p != q, both prime)
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    int p = i;
                    int q = n / i;

                    if (p != q && isPrime(p) && isPrime(q)) {
                        totalSum += (1 + p + q + n);
                    }
                    break; // only first factor matters
                }
            }
        }

        return totalSum;
    }
};

// Time Complexity : O(N*sqrt(M))
// Space Complexity : O(1)
// Due to early exits in each case , more faster




