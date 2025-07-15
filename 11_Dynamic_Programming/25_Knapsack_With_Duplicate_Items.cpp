// 1. Recursive Solution
class Solution {
  public:
    int knapDupl(vector<int>& val, vector<int>& wt, int idx, int capacity){
        if(idx == 0){
            return (capacity / wt[0]) * val[0];
        }

        int notPick = knapDupl(val, wt, idx - 1, capacity);
        int pick = (wt[idx] <= capacity ? (val[idx] + knapDupl(val, wt, idx, capacity - wt[idx])) : INT_MIN);

        return max(pick, notPick);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        return knapDupl(val, wt, n - 1, capacity);
    }
};
/*
Time Complexity : O(2^W) //T(n, W) = O(2^W) (because each time you can either reduce idx or reduce capacity, leading to exponential branching)

Space Complexity : In the worst case, you keep picking the same item (i.e., pick branch), so capacity reduces one unit at a time — resulting in a recursion depth of up to W. Space complexity: O(W) (due to recursion stack)

Recursive Calls : In the worst case, where both pick and notPick are always valid, you can have up to 2 recursive calls per function.
So the number of recursive calls can be up to 2^(W + n) in the worst-case tree (exponential).


*/
// 2. Memoization Solution
class Solution {
  public:
    int knapDupl(vector<int>& val, vector<int>& wt, int idx, int capacity,vector<vector<int>>& dp){
        if(idx == 0){
            return (capacity / wt[0]) * val[0];
        }
        
        if(dp[idx][capacity]!=-1) return dp[idx][capacity];

        int notPick = knapDupl(val, wt, idx - 1, capacity,dp);
        int pick = (wt[idx] <= capacity ? (val[idx] + knapDupl(val, wt, idx, capacity - wt[idx],dp)) : INT_MIN);

        return dp[idx][capacity] = max(pick, notPick);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return knapDupl(val, wt, n - 1, capacity,dp);
    }
};
/*
Time Complexity :: O(n * capacity)
Space Complexity :: O(n * capacity) + O(capacity,n)
Recursion Depth	:: O(n)
Optimized	:: Yes (memoization)
*/
// 3. Tabulation Solution
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        
        for(int cap = 0;cap<=capacity;cap++){ // Base Case
            dp[0][cap] = (cap/wt[0])*val[0];
        }
        
        for(int idx = 1;idx<n;idx++){
            for(int cap = 0;cap<=capacity;cap++){
                int notPick = dp[idx-1][cap];
                int pick = (wt[idx] <= cap ? val[idx] + dp[idx][cap-wt[idx]] : INT_MIN);

                dp[idx][cap] = max(pick, notPick);
            }
        }
        
        return dp[n-1][capacity];
    }
};
/*
Time Complexity :: O(n * capacity)
Space Complexity :: O(n * capacity) 
Optimized	:: Optimization	Possible to O(capacity)
*/
// 4. Space Optimised Tabulation Solution
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> dp(capacity + 1, 0);

        // Base Case: only first item is available
        for (int cap = 0; cap <= capacity; cap++) {
            dp[cap] = (cap / wt[0]) * val[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int cap = 0; cap <= capacity; cap++) {
                int notPick = dp[cap];
                int pick = (wt[idx] <= cap) ? val[idx] + dp[cap - wt[idx]] : INT_MIN;
                dp[cap] = max(pick, notPick);
            }
        }

        return dp[capacity];
    }
};
/*
Time Complexity : O(n*capacity)
Space Complexity : O(capacity)

*/