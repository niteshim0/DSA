class Solution {
  public:
      int singleNumber(vector<int>& nums) {
          int ans = 0;
          for(int i = 0;i<32;i++){
              int mask = 1<<i;
              int cnt = 0;
              for(auto &el : nums){
                 if(el&mask){
                   cnt++;
                 }
              }
              if(cnt%3){
                  ans = ans|mask;
              }
          }
          return ans;
      }
  };
  // Time Complexity : O(32*N)
  // Space Complexity : O(1)


  // Better Approach
  class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int n = nums.size();
            for(int i = 1;i<n;i+=3){
                if(nums[i]!=nums[i-1]){
                    return nums[i-1];
                }
            }
            return nums[n-1];
        }
    };
  // Time Complexity : O(NlogN + N/3)
  // Space Complexity : O(1)


  class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int ones = 0;
            int twos = 0;
            for(auto &el  : nums){
                ones = (ones^el)&(~twos);
                twos = (twos^el)&(~ones);
            }
            return ones;
        }
    };
// Time Complexity : O(n)
// Space Complexity: O(1)    