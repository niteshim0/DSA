class Solution {
  public:
      int singleNumber(vector<int>& nums) {
          int xr = 0;
          for(int &el : nums){
              xr = xr^el;
          }
          return xr;
      }
  };
  // Time Complexity : O(N)
  // Space Complexity : O(1)