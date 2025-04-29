class Solution {
  public:
      vector<int> singleNumber(vector<int>& nums) {
          long long xr = 0;
          for(auto &el : nums){
              xr^=el;
          }
          long long rightMostDiff = (xr^(xr-1))&(xr);
          int b1 = 0;
          int b2 = 0;
          for(auto &el : nums){
              if(rightMostDiff&el){
                  b1^=el;
              }else{
                  b2^=el;
              }
          }
          return {b1,b2};
      }
  };
  // Time Complexity : O(2N)
  // Space Complexity : o(1)