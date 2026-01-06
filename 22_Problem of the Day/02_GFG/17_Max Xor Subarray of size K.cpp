// Max Xor Subarray of size K
// https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1
// 6 Jan , 26
// Concept :: Sliding Window(Fixed Window Size) , XOR (a^a == 0)

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
    
        int n = arr.size();
        int i = 0 , j = 0;
        
        int sum = 0;
        int maxSum = 0;
        
        while(j<n){
            sum^=arr[j];
            if(j-i+1 == k){
                maxSum = max(maxSum,sum);
                sum^=arr[i];
                i++;
            }
            j++;
        }
        
        return maxSum;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)