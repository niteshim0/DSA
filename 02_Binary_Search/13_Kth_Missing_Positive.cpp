// Brute Force
class Solution {
  public:
      int findKthPositive(vector<int>& arr, int k) {
          for(int &x : arr){
              if(x<=k){
                  k++;
              }else{
                  break;
              }
          }
          return k;
      }
  };

// Binary Search
class Solution {
  public:
      int findKthPositive(vector<int>& arr, int k) {
          int n = arr.size();
          int start = 0;
          int end = n-1;
          while(start<=end){
              int mid = start +(end-start)/2;
              int missing = arr[mid]-(mid+1);
              if(missing<k){
                  start = mid+1;
              }else{
                  end = mid-1;
              }
          }
          return start + k;
      }
  };