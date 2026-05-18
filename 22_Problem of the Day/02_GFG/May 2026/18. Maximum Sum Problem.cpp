// Maximum Sum Problem
// https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1

// Concepts :: Recursion  + Dynamic Programming


class Solution {
  public:
    int maxSum(int n) {
        
        vector<int> dp(n+1,0);
        
        for(int i = 0 ; i<=n ; i++){
            
            dp[i] = max(i,(dp[i/2] + dp[i/3] + dp[i/4]));
        }
        
        return dp[n];
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)









class Solution {
public:

    /*
    ==========================================================
                    BYTELANDIAN GOLD COINS
    ==========================================================

    Core Idea:
    For every coin n, we have two choices:

    1) Keep the coin as it is
       profit = n

    2) Break the coin
       profit = f(n/2) + f(n/3) + f(n/4)

    Transition:
    f(n) = max(
                n,
                f(n/2)+f(n/3)+f(n/4)
              )

    ----------------------------------------------------------

    Why DP / Memoization?

    Because recursion generates repeated states.

    Example:

    f(12)
      / | \
     6  4  3

    f(6) again generates:
      3,2,1

    f(4) again generates:
      2,1,1

    Notice:
    f(3), f(2), f(1) are repeated.

    Store results once and reuse.

    ----------------------------------------------------------

    Pattern Type:

    ✓ Recursion with choices
    ✓ DP + Memoization
    ✓ Split / Break DP
    ✓ Maximize after partition
    ✓ Divide and conquer DP
    ✓ State caching

    ----------------------------------------------------------

    Similar DP Pattern:

    f(x)=max(
            keep_as_it_is,
            split_into_subproblems
           )

    ----------------------------------------------------------

    Related Interview Problems:

    Easy:
    - House Robber
    - Climbing Stairs
    - Frog Jump
    - Min Cost Climbing Stairs

    Break / Split:
    - Integer Break
    - Rod Cutting
    - Maximum Product Cutting
    - Bytelandian Gold Coins

    Partition DP:
    - Matrix Chain Multiplication
    - Burst Balloons
    - Palindrome Partitioning II
    - Minimum Cost to Cut a Stick

    Memoization:
    - Word Break
    - Different Ways to Add Parentheses
    - Scramble String
    - Stone Game

    Hard:
    - Cherry Pickup
    - Merge Stones
    - Remove Boxes
    - Strange Printer

    ----------------------------------------------------------

    Complexity:

    Time:
    O(number of unique states)

    Space:
    O(number of stored states)

    ----------------------------------------------------------

    Why unordered_map?

    Constraints may reach 10^9

    vector<int>(n+1)
    becomes impossible.

    Store only visited states.

    ==========================================================
    */

    unordered_map<int,long long> dp;

    long long solve(int n){

        // Base case
        if(n==0)
            return 0;

        // Already computed
        if(dp.count(n))
            return dp[n];

        // Choice 1:
        // Keep coin as it is
        long long keep=n;

        // Choice 2:
        // Break coin
        long long split=
            solve(n/2)
            +solve(n/3)
            +solve(n/4);

        // Store maximum
        return dp[n]=max(keep,split);
    }

    int maxSum(int n) {
        return solve(n);
    }
};