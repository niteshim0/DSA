class Solution {
  public:
      int singleNonDuplicate(vector<int>& nums) {
          // logic is the single element is always lies on even idx 
          // which changes the orientation of its left half and right half idx
          // they will be main focus on our elimination technique
          int n = nums.size();
          if(n==1) return nums[0];
          if(nums[0]!=nums[1]) return nums[0];
          if(nums[n-1]!=nums[n-2]) return nums[n-1];
          int start = 1;
          int end = n-2; // these are done to avoid extra checks
          while(start<=end){
              int mid = start + (end-start)/2;
              if((nums[mid]!=nums[mid-1])&& (nums[mid]!=nums[mid+1])){
                  return nums[mid];
              }else if((nums[mid]==nums[mid+1]&&(mid%2)==0) || (nums[mid]!=nums[mid+1]&&(mid%2==1))){
                  start = mid+1;
              }else{
                  end = mid-1;
              }
          }
          return -1;
      }
  };