/*In rotated array : one thing is for sure either left or right half is always sorted.*/
/*Find the sorted half.*/
/*Find on which side the element lies and move accordingly.*/

class Solution {
  public:
      int search(vector<int>& nums, int target) {
          int n = nums.size();
          int start = 0;
          int end = n-1;
          while(start<=end){
              int mid = start + (end-start)/2;
              if(nums[mid] == target) return mid;
              if(nums[start]<=nums[mid]){//left part sorted
                  if(nums[start]<=target && target<=nums[mid]){
                      end = mid-1;
                  }else{
                      start = mid+1;
                  }
              }else{
                  if(nums[end]>=target && target>=nums[mid]){
                      start = mid+1;
                  }else{
                      end = mid-1;
                  }
              }
          }
          return -1;
      }
  };


  // With duplicate elements
  class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int start = 0;
            int end = n-1;
            while(start<=end){
                int mid = start + (end-start)/2;
                if(nums[mid] == target) return mid;
                if(nums[start]<=nums[mid]){//left part sorted
                    if(nums[start]<=target && target<=nums[mid]){
                        end = mid-1;
                    }else{
                        start = mid+1;
                    }
                }else{
                    if(nums[end]>=target && target>=nums[mid]){
                        start = mid+1;
                    }else{
                        end = mid-1;
                    }
                }
            }
            return -1;
        }
    };
// Time Complexity : O(N)