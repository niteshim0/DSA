// 1. Recursive Solution
//  No solution exist for this version
// 2. Memoization Solution
// No solution exist for this version
// 3. Tabulation Solution
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
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

        int mini = 1e9;
        for(int target = 0;target<=sum/2;target++){
            if(dp[n-1][target]==true){
                int s1 = target;
                int s2 = sum - target;
                mini = min(mini,abs(s1-s2));
            }
        }
        return mini;
        // Time Complexity : O(N*Sum) + O(N) + O(sum/2)
        // Space Complexity : O(N*Sum)
    }
};
// 4. Space Optimised Tabulation Solution
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
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

        int mini = 1e9;
        for(int target = 0;target<=sum/2;target++){
            if(prev[target]==true){
                int s1 = target;
                int s2 = sum - target;
                mini = min(mini,abs(s1-s2));
            }
        }
        return mini;
        // Time Complexity : O(N*Sum) + O(N) + O(sum/2)
        // Space Complexity : O(Sum)
    }
};