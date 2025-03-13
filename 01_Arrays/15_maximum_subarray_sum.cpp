// https://leetcode.com/problems/maximum-subarray/

/*1.Brute Force : Generate all the subarrays.
                  Take their sum and return the maximum among them.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            long long sum = 0;
            for(int j = i;j<n;j++){
                sum+=nums[j];
                if(sum>maxi){
                    maxi = sum;
                }
            }
        }
        return maxi;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(1)

/*2.Optimal Approach : It doesn't make sense to carry negative sum forward.
                     : Whenever we encounter negative sum we will restart the sum to 0.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int &num : nums){
            if(sum<0){
                sum = 0;
            }
            sum+=num;
            if(sum>maxi){
                maxi = sum;
            }
        }
        return maxi;
    }
};

// Time Complexity : O(N)
// Space Complexity: O(1)

// Follow up : print the maximum subarray

class Solution {
  public:
      int maxSubArray(vector<int>& nums) {
          int sum = 0;
          int n = nums.size();
          int maxi = INT_MIN;
          int start = -1;
          int ansStart = -1,ansEnd = -1;
          for(int i = 0;i<n;i++){
              if(sum == 0){
                start = i;
              }
              sum+=num;
              if(sum>maxi){
                  maxi = sum;
                  ansStart = start;
                  ansEnd = i;
              }
              if(sum<0){
                sum = 0;
            }
          }
          for(int i = ansStart;i<=ansEnd;i++){
            cout<<nums[i]<<" ";
          }
      }
};
// Time Complexity : O(N)
// Space Complexity : O(1)