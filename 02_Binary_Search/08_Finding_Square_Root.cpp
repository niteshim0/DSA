// its typical Predicate Function Binary Search
// Where our answer lies on whether true or false side
// we move towards true side to get the ans

class Solution {
  public:
      int mySqrt(int x) {
          long long start = 0;
          long long end = x;
          while(start<=end){
              long long mid = start + (end-start)/2;
              if(mid*mid == x) return (int)mid;
              else if(mid*mid<x){
                  start = mid+1;
              }else{
                  end = mid-1;
              }
          }
          return (int)end;
      }
  };

// Finding the nth square root of integer
class Solution {
  public:
    int binExp(long long mid , long long n, long long m){
        long long ans = 1;
        while(n){
            if(n&1){
                ans = ans*mid*1ll;
            }
            if(ans>m) return 2;
            mid = mid*mid*1ll;
            n>>=1;
        }
        if(ans == m) return 1;
        return 0;
    }
    int nthRoot(int n, int m) {
        long long start = 0;
        long long end = m;
        while(start<=end){
            long long mid = start + (end-start)/2;
            if(binExp(mid,n,m) == 1) return mid;
            else if(binExp(mid,n,m)==2){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }
};