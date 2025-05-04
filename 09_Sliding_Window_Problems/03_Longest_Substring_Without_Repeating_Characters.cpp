// 1. Brute Force Approach
class Solution {
  public:
      int lengthOfLongestSubstring(string s) {
          int n = s.size();
          int longest = 0;
          for(int i = 0; i < n; i++) {
              vector<int> hash(256, 0);
              for(int j = i; j < n; j++) {
                  if(hash[s[j]] == 1) break;
                  hash[s[j]] = 1;            
                  longest = max(longest, j - i + 1);
              }
          }
          return longest;
      }
  };
  // Time Complexity : O(N*(N+1)/2)
  // Space Complexity : O(256)

  // 2. Sliding Window Approach
  class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.size();
            vector<int> hash(256,-1);
            int l = 0;
            int r = 0;
            int maxLen = 0;
            while(r<n){
                if(hash[s[r]]!=-1){
                    if(hash[s[r]]>=l){
                        l = hash[s[r]] + 1;
                    }
                }
                maxLen = max(maxLen,r-l+1);
                hash[s[r]] = r;
                r++;
            }
            return maxLen;
        }
    };
// Time Complexity : O(N)
// Space Complexity :O(256)