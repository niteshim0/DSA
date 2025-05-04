// 1. Brute Force Approach

class Solution {
  public:
      int longestOnes(vector<int>& nums, int k) {
          int maxLen = 0;
          int n = nums.size();
          int cnt = 0;
          for(int i = 0;i<n;i++){
              cnt = 0;
              for(int j = i;j<n;j++){
                  if(nums[j] == 0) cnt++;
                  if(cnt<=k){
                     maxLen = max(maxLen,j-i+1);
                  }else{
                      break;
                  }
              }
          }
          return maxLen;
      }
  };
// Time Complexity : O(N*(N+1)/2)
// Space Complexity : O(1)

// 2. Sliding Window Approach

class Solution {
  public:
      int longestOnes(vector<int>& nums, int k) {
          int n = nums.size();
          int l = 0;
          int r = 0;
          int maxLen = 0;
          int zeroes = 0;
          while(r<n){
              if(nums[r] == 0) zeroes++;
              while(zeroes>k){
                  if(nums[l]==0) zeroes--;
                  l++;
              }
              if(zeroes<=k){
                  maxLen = max(maxLen,r-l+1);
              }
              r++;
          }
          return maxLen;
      }
  };
// Time Complexity : O(2*N)
// Space Complexity : O(1)

// 3 . Optimal Sliding  Window Approach

class Solution {
  public:
      int longestOnes(vector<int>& nums, int k) {
          int n = nums.size();
          int l = 0;
          int r = 0;
          int maxLen = 0;
          int zeroes = 0;
          while(r<n){
              if(nums[r] == 0) zeroes++;
              if(zeroes>k){
                  if(nums[l]==0) zeroes--;
                  l++;
              }
              if(zeroes<=k){
                  maxLen = max(maxLen,r-l+1);
              }
              r++;
          }
          return maxLen;
      }
  };
// Time Complexity : O(N)
// Space Complexity : O(1)