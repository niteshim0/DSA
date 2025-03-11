// https://leetcode.com/problems/missing-number/description/

/*1.Brute Force : - Iterate the array from 1 to N .
                : - Use second loop to check whether that particular no(1 to N) exists in an Array or not. */


/*2.Better Approach : Use Cyclic Sort or Hash the elements from 1 to N.*/
class Solution {
  public:
      void swap(vector<int>&arr,int first,int second){
          int temp = arr[first];
          arr[first] = arr[second];
          arr[second] = temp;
      }
      void cyclicSort(vector<int>&arr){
          int i = 0;
          int n = arr.size();
          while(i<n){
              int correctIdx = arr[i];
              if(correctIdx == n){
                  i++;
              }else if(arr[i]!=arr[correctIdx] && correctIdx!=n){
                  swap(arr,i,correctIdx);
              }else{
                  i++;
              }
          }
      }
      int missingNumber(vector<int>& nums) {
          cyclicSort(nums);
          int n = nums.size();
          for(int i = 0;i<n;i++){
              if(nums[i]!=i){
                  return i;
              }
          }
          return nums.size();
      }
  };


/*Optimal Approach : Use the XOR concept or Sum of First N Natural Numbers.*/

class Solution {
  public:
      int missingNumber(vector<int>& nums) {
          int xor1 = 0;
          int xor2 = 0;
          int n = nums.size();
          for(int i = 0;i<n;i++){
              xor1^=i;
              xor2^=nums[i];
          }
          xor1^=n;
          return xor1^xor2;
      }
  };


  class Solution {
    public:
        int missingNumber(vector<int>& nums) {
              int sum=0;
            int n=nums.size();
            for(int i=0;i<n;i++)
            {
                 sum+=nums[i];}
            return n*(n+1)/2-sum;
            
        }
    };