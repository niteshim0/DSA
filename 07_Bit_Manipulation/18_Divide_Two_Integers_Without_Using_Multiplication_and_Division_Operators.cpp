class Solution {
  public:
      int divide(int dividend, int divisor) {
          if(dividend == divisor) return 1;
          bool sign = true;
          if(dividend>=0 && divisor<0) sign = false;
          if(dividend<0 && divisor>=0) sign = false;
  
          long long n = dividend<0 ? (long)dividend*-1 : dividend*1;
          long long d = divisor<0 ? (long)divisor*-1 : divisor*1;
          long long ans = 0;
          while(n>=d){
              int cnt = 0;
              while(n>=(d<<(cnt+1))){
                  cnt++;
              }
              ans+=(1<<cnt);
              n-=(d<<cnt);
          }
          if(ans == 1<<31 && sign) return INT_MAX;
          if(ans == 1<<31 && !sign) return INT_MIN;
  
          return sign ? ans : -ans;
      }
  };
  // Time Complexity : O(log(ans))
  // Space Complexity : O(1)