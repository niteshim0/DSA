// 31. Express as Consecutive Number Sum
//Concepts :: Sum of N Natural Numbers + Power of 2 Check

/*
 * PROBLEM: Express n as Sum of 2+ Consecutive Positive Numbers
 *
 * MATH DERIVATION:
 * ----------------
 * Sum of k consecutive numbers starting from a:
 *   n = a + (a+1) + ... + (a+k-1)
 *   n = k*a + k*(k-1)/2
 *   2n = k*(2a + k - 1)
 *
 * For a >= 1:
 *   2a = (2n/k) - k + 1 >= 2
 *   => 2n >= k*(k+1)
 *   => k <= sqrt(2n)       [loop bound]
 *
 * CONDITIONS for valid (a, k):
 *   1. k must divide 2n
 *   2. twoA = (2n/k) - k + 1 must be >= 2   (so a >= 1)
 *   3. twoA must be even                     (so a is integer)
 *
 * EDGE CASE:
 *   Powers of 2 can NEVER be expressed — only numbers that fail all k.
 *
 * COMPLEXITY: Time O(sqrt(n)), Space O(1)
 */

class Solution {
  public:
    bool canBeExpressed(int n) {

        // k = number of consecutive terms (try k = 2, 3, 4, ...)
        // loop runs while k*(k+1) <= 2n  i.e. k <= sqrt(2n)
        for (int k = 2; (long long)k * (k + 1) <= 2LL * n; k++) {

            long long num = 2LL * n;

            // condition 1: k must divide 2n, else no integer solution
            if (num % k != 0) continue;

            // twoA = 2a = (2n/k) - k + 1
            long long twoA = num / k - k + 1;

            // condition 2: a >= 1  =>  twoA >= 2
            // condition 3: a integer  =>  twoA even
            if (twoA >= 2 && twoA % 2 == 0) {
                return true;   // found valid starting point a = twoA/2
            }
        }

        // no valid k found => n is a power of 2
        return false;
    }
};

class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        
        return (n & (n-1));
        
    }
};