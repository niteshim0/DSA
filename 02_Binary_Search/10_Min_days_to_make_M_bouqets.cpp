class Solution {
  public:
      int feasibleDays(vector<int>& arr,int mid,int k){
          int bouquets = 0;
          int cnt = 0;
          for(int &x : arr){
              if(x<=mid){
                  cnt+=1;
              }else{
                  bouquets+=(cnt/k);
                  cnt = 0;
              }
          }
          bouquets+=(cnt/k);
          return bouquets;
      }
      int minDays(vector<int>& bloomDay, int m, int k) {
          int n = bloomDay.size();
          if(m*1ll*k > n) return -1;
          int start = *min_element(bloomDay.begin(),bloomDay.end());
          int end = *max_element(bloomDay.begin(),bloomDay.end());
          int ans = -1;
          while(start<=end){
              int mid = start + (end-start)/2;
              if(feasibleDays(bloomDay,mid,k)>=m){
                  ans = mid;
                  end = mid-1; 
              }else{
                  start = mid+1;
              }
          }
          return ans;
  
      }
  };