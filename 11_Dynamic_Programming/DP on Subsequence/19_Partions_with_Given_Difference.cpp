// 1. Recursive Solution
class Solution {
  public:
    // Recursive Solution
    int solve(int idx,vector<int>& arr,int sum){
        if(idx == 0){
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || arr[0] == sum) return 1;
            return 0;
        }
        
        int notPick  = solve(idx-1,arr,sum);
        int pick = (sum>=arr[idx]) ? solve(idx-1,arr,sum-arr[idx]) : 0;
        
        return pick + notPick;
        
    }
    int countSubsets(vector<int>& arr,int sum){
        int n = arr.size();
        return solve(n-1,arr,sum);
    }
    int countPartitions(vector<int>& arr, int d) {
       int totalSum = accumulate(arr.begin(),arr.end(),0);
       totalSum-=d;
       if(totalSum<0 || totalSum%2) return false;
       return countSubsets(arr,totalSum/2);
       // Time Complexity : O(N) + O(2^N)
       // Space Complexity : O(N)
    }
};
// 2. Memoization Solution
class Solution {
  public:
    // Memoization Solution
    int solve(int idx,vector<int>& arr,int sum,vector<vector<int>>& dp){
        if(idx == 0){
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || arr[0] == sum) return 1;
            return 0;
        }
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        int notPick  = solve(idx-1,arr,sum,dp);
        int pick = (sum>=arr[idx]) ? solve(idx-1,arr,sum-arr[idx],dp) : 0;
        
        return dp[idx][sum] = pick + notPick;
        
    }
    int countSubsets(vector<int>& arr,int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
    }
    int countPartitions(vector<int>& arr, int d) {
       int totalSum = accumulate(arr.begin(),arr.end(),0);
       totalSum-=d;
       if(totalSum<0 || totalSum%2) return false;
       return countSubsets(arr,totalSum/2);
       // Time Complexity : O(N) + O(N*totalSum/2+1)
       // Space Complexity : O(N) + O(N*totalSum/2+1);
    }
};
// 3. Tabulation Solution
class Solution {
  public:
   // Tabulation Solution
    int countSubsets(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        // Base case initialization
        dp[0][0] = 1;
        if (arr[0] == 0) dp[0][0] = 2;
        else if (arr[0] <= target) dp[0][arr[0]] = 1;
        
        for (int idx = 1; idx < n; idx++) {
            for (int sum = 0; sum <= target; sum++) {
                int notPick = dp[idx - 1][sum];
                int pick = (sum >= arr[idx]) ? dp[idx - 1][sum - arr[idx]] : 0;
                dp[idx][sum] = pick + notPick;
            }
        }
        
        return dp[n - 1][target];
    }

    int countPartitions(vector<int>& arr, int d) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // Check if (totalSum - d) is non-negative and even
        if (totalSum < d || (totalSum - d) % 2 != 0)
            return 0;

        int target = (totalSum - d) / 2;
        return countSubsets(arr, target);
        // Time Complexity : O(N) + O(N*totalSum/2+1)
       // Space Complexity : O(N*totalSum/2+1);
    }
};

// 4. Space Optimised Tabulation Solution
class Solution {
  public:
   // Tabulation Solution
    int countSubsets(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        // Base case initialization
        dp[0][0] = 1;
        if (arr[0] == 0) dp[0][0] = 2;
        else if (arr[0] <= target) dp[0][arr[0]] = 1;
        
        for (int idx = 1; idx < n; idx++) {
            for (int sum = 0; sum <= target; sum++) {
                int notPick = dp[idx - 1][sum];
                int pick = (sum >= arr[idx]) ? dp[idx - 1][sum - arr[idx]] : 0;
                dp[idx][sum] = pick + notPick;
            }
        }
        
        return dp[n - 1][target];
    }

    int countPartitions(vector<int>& arr, int d) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // Check if (totalSum - d) is non-negative and even
        if (totalSum < d || (totalSum - d) % 2 != 0)
            return 0;

        int target = (totalSum - d) / 2;
        return countSubsets(arr, target);
        // Time Complexity : O(N) + O(N*totalSum/2+1)
       // Space Complexity : O(N*totalSum/2+1);
    }
};
