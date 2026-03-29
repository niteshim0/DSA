// Partitions with Given Difference
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

// Concepts :: Dynamic Programming + Pick/ NotPick Problem


// Approach :: I will convert this problem in counting the no of subsets with 
// a particular target
// calculate the totalSum of entire array 
// minus the diff from it (how it will give us target (totalSum - diff ))
// if it turns out to be negative , then any subset is not possible -> since array is consists of only positive numbers(positive numbers sum can't be negative)
// now divide this sum into 2 parts say s1 , s2 and diff(already we have separatived)

// here s1 == s2 , so that they can be divided into two equal parts i.e divison should be even , if odd then divison is not possible

// so now we have to calculate those subsets whose sum is = totalSum - diff / 2;
// in this we have one array with s1 and other array with s1 + diff , making diff always equal to given difference , so we need to calculate only s1 with that particular target




// Technique 1 :: Memoization (Top Down Approach)

class Solution {
public:
    int mod = 1e9 + 7;
    
    int countSubsets(int idx, vector<int>& arr, int sum, vector<vector<int>>& dp){
        
        if(idx == 0){
            if(arr[0] == 0 && sum == 0) return 2;
            if(sum == 0 || arr[0] == sum) return 1;
            return 0;
        }
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        int notPick = countSubsets(idx-1, arr, sum, dp);
        int pick = (sum >= arr[idx]) ? countSubsets(idx-1, arr, sum-arr[idx], dp) : 0;
        
        return dp[idx][sum] = (pick + notPick) % mod;
    }

    int countPartitions(vector<int>& arr, int diff) {
       
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        totalSum -= diff;
        
        if(totalSum < 0 || totalSum % 2) return 0;
        
        int target = totalSum / 2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return countSubsets(n-1, arr, target, dp);
    }
};

// Time Complexity : O(N * totalSum/2)
// Space Complexity : O(N*totalSum/2) + O(N) // recursion stack space


// Approach 2 :: Tabulation (Botttom UP Approach)

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
       
    }
};

// Time Complexity : O(N) + O(N*totalSum/2+1)
// Space Complexity : O(N*totalSum/2+1);


// Approach 3 :: Space Optimized Approach

class Solution {
  public:
   // Space Optimised Tabulation Solution
    int countSubsets(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 0);
        
        // Base case initialization
        prev[0] = 1;
        if (arr[0] == 0) prev[0] = 2;
        else if (arr[0] <= target) prev[arr[0]] = 1;
        
        for (int idx = 1; idx < n; idx++) {
            vector<int> curr(target+1,0);
            for (int sum = 0; sum <= target; sum++) {
                int notPick = prev[sum];
                int pick = (sum >= arr[idx]) ? prev[sum - arr[idx]] : 0;
                curr[sum] = pick + notPick;
            }
            prev = curr;
        }
        
        return prev[target];
    }

    int countPartitions(vector<int>& arr, int d) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // Check if (totalSum - d) is non-negative and even
        if (totalSum < d || (totalSum - d) % 2 != 0)
            return 0;

        int target = (totalSum - d) / 2;
        return countSubsets(arr, target);
       
    }
};

 // Time Complexity : O(N) + O(N*totalSum/2+1)
// Space Complexity : O(totalSum/2+1);
