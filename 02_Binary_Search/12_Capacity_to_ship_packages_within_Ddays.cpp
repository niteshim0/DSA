class Solution {
  public:
      int weightRequired(vector<int>& weights,int mid){
          int load = 0;;
          int days = 1;
          for(int &weight : weights){
              if(load+weight>mid){
                  days++;
                  load = weight;
              }else{
                  load+=weight;
              }
          }
          return days;
      }
      int shipWithinDays(vector<int>& weights, int days) {
          int start = *max_element(weights.begin(),weights.end());
          int end = 0;
          for(int &x : weights){
              end+=x;
          }
          int ans = start;
          while(start<=end){
              int mid = start + (end-start)/2;
              if(weightRequired(weights,mid)<=days){
                  ans = mid;
                  end = mid-1;
              }else{
                  start = mid+1;
              }
          }
          return ans;
      }
  };