// 1. Recursion Solution

int climbStairs(int n) {
        if(n<=2) return n;
        return climbStairs(n-1) + climbStairs(n-2);
}

/* Recurrence Relation
Let T(n) be the time taken by climbStairs(n):
T(n)=T(n−1)+T(n−2)+O(1)

With base cases:
T(1)=O(1),T(2)=O(1)

Time Complexity : O(2^n)
Space Complexity : O(N) due to recursion stack space
*/

// 2. Memoization Solution(Top Down Approach)

class Solution {
public:
    int climbStairs(int n,vector<int>& dp){
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = climbStairs(n-1,dp) + climbStairs(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climbStairs(n,dp);
    }
};

// Time Complexity : O(N) // from exponential to linear growth
// Space Complexity : O(N)(for recursion stack space + O(N) // for dp array

// 3. Tabulation Solution (Bottom Up Approach)

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1,-1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// 4. Space Optimized Solution

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        if(n==2) return n;
        int prev2 = 1;
        int prev1 = 2;
        for(int i = 3;i<=n;i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)