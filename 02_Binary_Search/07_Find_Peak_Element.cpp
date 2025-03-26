// Whole scenario is make graphs of increasing , peak , decreasing and on the which part you lie on move accordingly to that
class Solution {
  public:
      int findPeakElement(vector<int>& nums) {
          int n = nums.size();
          int start = 1;
          int end = n-2;
          if(n==1) return 0;
          if(nums[0]>nums[1]) return 0;
          if(nums[n-1]>nums[n-2]) return n-1;
  
          while(start<=end){
              int mid = start + (end-start)/2;
              if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                  return mid;
              }else if(nums[mid]>nums[mid+1]){ // decreasing side of peak
                  end = mid-1;
              }else{ // increasing side of peak
                  start = mid+1;
              }
          }
          return -1;
      }
  };