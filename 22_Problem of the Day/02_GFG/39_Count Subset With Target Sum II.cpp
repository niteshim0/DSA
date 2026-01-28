// Count Subset With Target Sum II
// https://www.geeksforgeeks.org/problems/count-the-subset-with-sum-equal-to-k/1
// Concept :: Recursion + Dynamic Programming + Memoization


// Approach :: For each element , we have two options whether to take it or leave it in our subset.
// if we reaches end and our sum is equal to k , it means we have found 1 element which satisfies the condition , add it to ans
// classic pick,notPick type problem

// Approach I : Recursive Version
class Solution {
  public:
    int subsetCounter(vector<int>&arr,int k,int idx){
        if(idx == arr.size()){
            return k == 0 ? 1 : 0;
        }
        
        int pick = 0;
        if(arr[idx]<=k){
            pick = subsetCounter(arr,k-arr[idx],idx+1);
        }
        int notPick = subsetCounter(arr,k,idx+1);
        
        return pick + notPick;
    }
    int countSubset(vector<int> &arr, int k) {
        int negSum = 0 , posSum = 0;
        for(int &x : arr){
            if(x>0) posSum+=x;
            else negSum+=x;
        }
        return subsetCounter(arr,k,0);
    }
};
// Time Complexity : O(2^N)
// Space Complexity : O(N)

// Appraoch II : Memoization (Top Down Approach)

class Solution {
  public:
    int subsetCounter(vector<int>&arr,int k,int idx,vector<vector<int>>& memo){
        if(idx == arr.size()){
            return k == 0 ;
        }
        if(memo[idx][k]!=-1) return memo[idx][k];
        int pick = 0;
        if(arr[idx]<=k){
            pick = subsetCounter(arr,k-arr[idx],idx+1,memo);
        }
        int notPick = subsetCounter(arr,k,idx+1,memo);
        
        return memo[idx][k] = pick + notPick;
    }
    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        int negSum = 0 , posSum = 0;
        for(int &x : arr){
            if(x>0) posSum+=x;
            else negSum+=x;
        }
        if(k>posSum || k<negSum) return 0;
        vector<vector<int>> memo(n+1,vector<int>(k+1,-1));
        return subsetCounter(arr,k,0,memo);
    }
};

// Time Complexity : O(N*K)
// Space Complexity : O(N*K)


// Approach III : Tabulation (Bottom Up Approach)
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();

        int posSum = 0, negSum = 0;
        for (int x : arr) {
            if (x >= 0) posSum += x;
            else negSum += x;
        }

        if (k < negSum || k > posSum) return 0;

        int offset = -negSum;
        int range = posSum - negSum;

        vector<vector<long long>> dp(n + 1, vector<long long>(range + 1, 0));

        dp[n][offset] = 1;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int sum = 0; sum <= range; sum++) {
                long long notPick = dp[idx + 1][sum];
                long long pick = 0;

                int prevSum = sum - arr[idx];
                if (prevSum >= 0 && prevSum <= range) {
                    pick = dp[idx + 1][prevSum];
                }

                dp[idx][sum] = pick + notPick;
            }
        }

        return dp[0][k + offset];
    }
};

// Time Complexity : O(N*K)
// Space Complexity : O(N*K)

// Approach IV : Space Optimized Tabulation Version
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();

        int posSum = 0, negSum = 0;
        for (int x : arr) {
            if (x >= 0) posSum += x;
            else negSum += x;
        }

        if (k < negSum || k > posSum) return 0;

        int offset = -negSum;
        int range = posSum - negSum;

        vector<long long> prev(range + 1, 0);
        vector<long long> curr(range + 1,0);

        prev[offset] = 1;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int sum = 0; sum <= range; sum++) {
                long long notPick = prev[sum];
                long long pick = 0;

                int prevSum = sum - arr[idx];
                if (prevSum >= 0 && prevSum <= range) {
                    pick = prev[prevSum];
                }

                curr[sum] = pick + notPick;
            }
            prev = curr;
        }

        return prev[k + offset];
    }
};


// Time Complexity : O(N*K)
// Space Complexity : O(K)