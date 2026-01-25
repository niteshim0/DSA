// Number of Valid Parentheses
// https://www.geeksforgeeks.org/problems/valid-number-of-parenthesis/1
// Concept :: Recursion  + Stack + Valid Parantheses

class Solution {
  public:
    int wayFinder(int sum,int n){
        if(sum < 0) return 0;
        if(n == 0){
            return (sum == 0 ? 1 : 0);
        }
        
        return wayFinder(sum+1,n-1) + wayFinder(sum-1,n-1);
    }
    int findWays(int n) {
        
        return n&1 ? 0 : wayFinder(0,n);
        
    }
};

// Time Complexity : O(2^(N/2));
// Space Complexity : O(N/2) // Auxiliary stack space