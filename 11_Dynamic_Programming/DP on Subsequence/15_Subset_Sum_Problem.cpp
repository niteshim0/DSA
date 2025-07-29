// 1. Recursive Solution
class Solution {
  public:
    // Recursive Solution
    bool solve(int idx,vector<int>& arr,int sum){
        if(sum == 0) return true;
        if(idx == 0) return arr[idx] == sum;
        
        bool notPick = solve(idx-1,arr,sum);
        bool pick = sum>=arr[idx] ? solve(idx-1,arr,sum-arr[idx]) : false;
        
        return pick || notPick;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return solve(n-1,arr,sum);
        
        // Time Complexity : O(2^N)
        // Space Complexity : O(N) // for auxiliary stack space
    }
};
// 2. Memoization Solution
class Solution {
  public:
    // Memoization Solution
    bool solve(int idx,vector<int>& arr,int sum,vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(idx == 0) return arr[idx] == sum;
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        bool notPick = solve(idx-1,arr,sum,dp);
        bool pick = sum>=arr[idx] ? solve(idx-1,arr,sum-arr[idx],dp) : false;
        
        return dp[idx][sum] = pick || notPick;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
        
        // Time Complexity : O(N*target)
        // Space Complexity : O(N) // for auxiliary stack space + O(N*target)//for dp array
    }
};
// 3. Tabulation Solution
class Solution {
public:
    // Tabulation Solution
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base case: A subset sum of 0 is always possible (take nothing)
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Initialize for first element
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= sum; target++) {
                bool notPick = dp[idx - 1][target];
                bool pick = (target >= arr[idx]) ? dp[idx - 1][target - arr[idx]] : false;

                dp[idx][target] = pick || notPick;
            }
        }

        return dp[n - 1][sum];
        
        // Time Complexity : O(N*sum)
        // Space Complexity : O(N*sum);
    }
};
// 4. Space Optimised Tabulation Solution
class Solution {
public:
    // Space Optimised Tabulation Solution
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1, false) , curr(sum+1,false);

        // Base case: A subset sum of 0 is always possible (take nothing)
        prev[0] = curr[0] = true;

        // Initialize for first element
        if (arr[0] <= sum)
            prev[arr[0]] = true;

        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= sum; target++) {
                bool notPick = prev[target];
                bool pick = (target >= arr[idx]) ? prev[target - arr[idx]] : false;

                curr[target] = pick || notPick;
            }
            prev = curr;
        }

        return prev[sum];
        
        // Time Complexity : O(N*sum)
        // Space Complexity : O(sum);
    }
};