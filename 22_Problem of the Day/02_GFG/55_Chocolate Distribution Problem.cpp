// Chocolate Distribution Problem
// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
// Concepts :: Greedy + Sorting

// Approach :: Sort the array , so closest packet always remains closes , and choose the minimum among these.
class Solution {
public:
    int findMinDiff(vector<int>& arr, int m) {
        int n = arr.size();
        if(m == 0 || n == 0) return 0;

        sort(arr.begin(), arr.end());

        int mini = INT_MAX;
        for(int i = 0; i + m - 1 < n; i++){
            int diff = arr[i + m - 1] - arr[i];
            mini = min(mini, diff);
        }

        return mini;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
