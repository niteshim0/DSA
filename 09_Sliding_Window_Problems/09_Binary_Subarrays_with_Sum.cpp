class Solution {
  public:
      int numSubarraysWithSum(vector<int>& nums, int goal) {
           int i = 0;
          int j = 0;
          int n = nums.size();
          int totalSubarrayCnt = 0;
          int currentSum = 0;
          int prefixZeros = 0;
          while(j<n){
              currentSum+=nums[j];
               while(i<j && (nums[i] == 0 || currentSum>goal)){
                  if(nums[i] == 1){
                      prefixZeros = 0;
                  }else{
                      prefixZeros+=1;
                  }
                  currentSum-=nums[i];
                  i++;
              }
              if(currentSum == goal){
                  totalSubarrayCnt+=(1+prefixZeros);
              }
              j++;
          }
          return totalSubarrayCnt;
      }
  };
// Time Complexity : O(2N)
// Space Complexity: O(1)