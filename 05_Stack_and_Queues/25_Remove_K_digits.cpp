class Solution {
  public:
      string removeKdigits(string num, int k) {
          string result;
          
          for (char digit : num) {
              // Remove characters from result if the current digit is smaller and we still have k to remove
              while (!result.empty() && result.back() > digit && k > 0) {
                  result.pop_back();
                  k--;
              }
              result.push_back(digit);
          }
  
          // Remove remaining digits from the end if needed
          while (k-- > 0 && !result.empty()) {
              result.pop_back();
          }
  
          // Remove leading zeros
          int start = 0;
          while (start < result.size() && result[start] == '0') {
              start++;
          }
  
          result = result.substr(start);
  
          return result.empty() ? "0" : result;
      }
  };
  