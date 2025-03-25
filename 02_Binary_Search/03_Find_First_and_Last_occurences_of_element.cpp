class Solution {
  public:
      int findIdx(vector<int>&nums,int target,bool isFirstIdx){
          int  n = nums.size();
          int start = 0;
          int end = n-1;
          int ans = -1;
          while(start<=end){
              int mid = start + (end-start)/2;
              if(nums[mid]<target){
                  start = mid+1;
              }else if(nums[mid]>target){
                  end = mid-1;
              }else{
                  ans  = mid;
                  if(isFirstIdx){
                      end = mid-1;
                  }else{
                      start = mid+1;
                  }
              }
          }
          return ans;
      }
      vector<int> searchRange(vector<int>& nums, int target) {
          int first = findIdx(nums,target,true);
          if(first == -1) return {-1,-1};
          return {first,findIdx(nums,target,false)};
      }
  };