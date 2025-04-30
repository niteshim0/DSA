class Solution {
  public:
      bool isPalindrome(int x) {
          if(x<0) return false;
          int temp = x;
          long long reverseNum = 0;
          while(temp>0){
              int lastDigit = temp%10;
              reverseNum = reverseNum*10 + lastDigit;
              temp/=10;
          }
          return reverseNum == x;
      }
  };
// Time Complexity : O(log1o(N))
// Space Complexity : O(1)