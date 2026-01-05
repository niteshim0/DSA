// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
// Max Sum Subarray of size K


// Concept :: Sliding Window with Fixed Window Size
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        int maxSum = 0;
        
        int i = 0 , j = 0;
        int n = arr.size();
        
        int totalSum = 0;
        
        while(j<n){
            totalSum+=arr[j];
            if(j-i+1 == k){
                maxSum = max(maxSum,totalSum);
                totalSum-=arr[i];
                i++;
            }
            j++;
        }
        
        return maxSum;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)