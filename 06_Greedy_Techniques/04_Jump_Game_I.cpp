class Solution {
  public:
      bool canJump(vector<int>& nums) {
          int n = nums.size();
          int maxIdx = 0;
          for(int i = 0; i<n;i++){
              if(i>maxIdx) return false;
              maxIdx = max(maxIdx,i+nums[i]);
          }
          return true;
      }
  };
// Time Complexity : O(N)
// Space Complexity : O(1)