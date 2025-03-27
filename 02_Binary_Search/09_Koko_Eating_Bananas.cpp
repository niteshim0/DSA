class Solution {
  public:
      int feasibleSpeed(vector<int>& piles,int mid,int h){
          int hrs = 0;
          for(int &pile : piles){
              hrs+=(pile/mid);
              if(hrs>h) return hrs;// to counter integer overflow
              pile%mid!=0 ? hrs+=1 : hrs+=0;
          }
          return hrs;
      }
      int minEatingSpeed(vector<int>& piles, int h) {
          int start = 1;
          int end = *max_element(piles.begin(),piles.end());
          int minSpeed = 1;
          while(start<=end){
              int mid = start + (end-start)/2;
              if(feasibleSpeed(piles,mid,h)<=h){
                  minSpeed = mid;
                  end = mid-1;
              }else{
                  start = mid+1;
              }
          }
          return minSpeed;
      }
  };