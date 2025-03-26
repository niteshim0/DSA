/* Since in rotate sorted array . There will always be a peak . The very next element to peak is our minimum element.*/

class Solution {
  public:
      int pivotFinder(vector<int>&nums){
          int n = nums.size();
          int start = 0;
          int end = n-1;
          while(start<=end){
              int mid = start + (end-start)/2;
              if(mid<end && nums[mid]>nums[mid+1]){
                  return mid;
              }else if(mid>start && nums[mid-1]>nums[mid]){
                  return mid-1;
              }else if(nums[start]>=nums[mid]){
                  end = mid-1;
              }else{
                  start = mid+1;
              }
          }
          return -1;
      }
      int findMin(vector<int>& nums) {
          int pivot = pivotFinder(nums);
          return nums[pivot+1];
      }
  };

  // Find how many times array has been rotated
  // Use the same concept :: The no of rotation is the index of min element
  int findKRotation(vector<int> &nums) {
    int n = nums.size();
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(mid<end && nums[mid]>nums[mid+1]){
            return mid+1;
        }else if(mid>start && nums[mid-1]>nums[mid]){
            return mid;
        }else if(nums[start]>=nums[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return 0;
}