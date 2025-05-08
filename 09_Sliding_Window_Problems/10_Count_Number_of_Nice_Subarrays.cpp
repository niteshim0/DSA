class Solution {
  public:
      long long subarrAtMostKOdd(vector<int> &nums,int k){
          int n = nums.size();
          int i = 0;
          int j = 0;
          int cnt = 0;
          int res = 0;
          while(j<n){
             if(nums[j]&1){
                 cnt++;
             }
             if(cnt>k){
                 while(cnt>k){
                     if(nums[i]&1){
                         cnt-=1;
                     }
                     i++;
                 }
             }
             res+=(j-i+1);
             j++;
          }
          return res;
      }
      int numberOfSubarrays(vector<int>& nums, int k) {
          return subarrAtMostKOdd(nums,k) - subarrAtMostKOdd(nums,k-1);
      }
  };
// Time Complexity : O(2*2N)
// Space Complexity: O(1)