class Solution {
  public:
      int divSum(vector<int>& nums,int mid,int threshold){
          int res = 0;
          for(int &num : nums){
              res+=(num/mid);
              (num%mid)!=0 ?res+=1 : res+=0;
              if(res>threshold) return res; // countering the integer overflow
          }
          return res;
      }
      int smallestDivisor(vector<int>& nums, int threshold) {
          int start = 1;
          int end   = *max_element(nums.begin(),nums.end());
          int ans = end;
          while(start<=end){
              int mid = start + (end-start)/2;
              if(divSum(nums,mid,threshold)<=threshold){
                  ans = mid;
                  end = mid-1;
              }else{
                  start = mid+1;
              }
          }
          return ans;
      }
  };