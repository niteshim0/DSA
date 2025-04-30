class Solution {
  public:
      int reverse(int x) {
          bool sign = true;
          int maxi = INT_MAX;
          if(x<0) sign = false;
          long long temp = x<0 ? (-1*1ll*x) : x;
          long long reverseNum = 0;
          while(temp>0){
             int lastDigit = temp%10;
             reverseNum = reverseNum*10 + lastDigit;
             if(reverseNum > maxi) return 0;
             temp/=10;
          }
          if(!sign) return -reverseNum;
          return reverseNum;
      }
  };
// Time Complexity : O(log10(N))
// Space Complexity  : O(1)