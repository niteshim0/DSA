//1. Recursion Solution

class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        return fib(n-1) + fib(n-2);
    }
};

/* Recurrence Relation : for base case
                         if(n<=1) n;
                         T(n) = T(n-1) + T(n-2);

  Time Complexity : O(2^N) // exponential growth
  Space Complexity : O(N) // for recursion stack space
*/

// 2. Memoization Solution // Top-Down Solution

class Solution {
public:
    int fib(int n,vector<int>& dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = fib(n-1,dp) + fib(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fib(n,dp);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N) // for dp array + O(N) // for recursion stack space


// 3. Tabulation Solution (Bottom-Up Solution)

int fib(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
}
// Time Complexity : O(N)
// Space Complexity : O(N)


// 4. Space Optimized Solution (Bottom-Up But Less space)

class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int prev2 = 0;
        int prev1 = 1;
        int curri = 0;
        for(int i = 2;i<=n;i++){
            curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)

