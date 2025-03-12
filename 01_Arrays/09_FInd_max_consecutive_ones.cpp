// This is the only straightForward approach.
// if non-zero increase the count.
// if zero found break the streak by updating cnt = 0;
// Also observe and update the maxi.
class Solution {
  public:
      int findMaxConsecutiveOnes(vector<int>& nums) {
          int maxi = 0 ,  cnt = 0;
          int n = nums.size();
          for(int i = 0;i<n;i++){
              if(nums[i]!=0){
                  cnt++;
                  maxi = max(maxi,cnt);
              }else{
                  cnt = 0;
              }
          }
          return maxi;
      }
  };