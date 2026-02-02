// https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
// Max Circular Subarray Sum
// Concept :: Kadane's Algorithm + Circular Array Concept

// Approach :: We will apply normal kadane to find what maxSum we can get as well as what minSubarraySum we can get , for reaching to maxSum in circular array , it is always possible by subtracting the minSum one.

class Solution {
public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = 0;
        int maxKadane = arr[0], curMax = 0;
        int minKadane = arr[0], curMin = 0;

        for (int x : arr) {
            totalSum += x;

            curMax = max(x, curMax + x);
            maxKadane = max(maxKadane, curMax);

            curMin = min(x, curMin + x);
            minKadane = min(minKadane, curMin);
        }

  
        if (maxKadane < 0)
            return maxKadane;

        return max(maxKadane, totalSum - minKadane);
    }
};


// Time Complexity : O(N)
// Space Commplexity : O(1)