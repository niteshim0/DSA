// https://leetcode.com/problems/rotate-array/description/

/*1.Brute Force : - Take the last k elements in a temp array.
                  - Move the starting n-k elements to last n-k places.
                  - Paste the temp elements array into original from start to k places. */

void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n; // if rotatation increases more than the size of array
        vector<int> temp;
        for(int i = n-k;i<n;i++){
            temp.push_back(nums[i]);
        }
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }
        for(int i = 0;i<k;i++){
            nums[i] = temp[i];
        }
}

//Time Complexity : O(n+k)
//Space Complexity : O(k)

/*2.Optimal Approach : It is based on observation.It can't happen with intuition.*/

class Solution {
  public:
      void reverse(vector<int>&nums,int start,int end){
          int temp;
          while(start<=end){
               temp = nums[start];
               nums[start] = nums[end];
               nums[end] = temp;
               start++;
               end--;
          }
      }
      void rotate(vector<int>& nums, int k) {
          int n = nums.size();
          k = k%n;
          reverse(nums,0,n-k-1);
          reverse(nums,n-k,n-1);
          reverse(nums,0,n-1);
      }
  };

//Time Complexity : O(N)
//Space Complexity : O(1)