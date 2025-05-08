// 1. Brute Force Approach

class Solution {
  public:
      int characterReplacement(string s, int k) {
          int n = s.size();
          int maxLen = 0;
          for(int i = 0 ;i<n;i++){
              vector<int> hash(26,0);
              int maxFreq = 0;
              for(int j = i;j<n;j++){
                  hash[s[j]-'A']++;
                  maxFreq = max(maxFreq,hash[s[j]-'A']);
                  int changes = j-i+1 - maxFreq;
                  if(changes<=k){
                      maxLen = max(maxLen,j-i+1);
                  }else{
                      break;
                  }
              }
          }
          return maxLen;
      }
  };
// Time Complexity : O(N*N)
// Space Complexity : O(26)


// 2. Sliding Window Approach

class Solution {
  public:
      int characterReplacement(string s, int k) {
          vector<int> hash(26,0);
          int maxFreq = 0;
          int maxLen = 0;
          int n = s.size();
          int l = 0;
          int r = 0;
          while(r<n){
              hash[s[r]-'A']++;
              maxFreq = max(maxFreq,hash[s[r]-'A']);
              while(r-l+1-maxFreq>k){
                  hash[s[l]-'A']--;
                  maxFreq = max(maxFreq,hash[s[l]-'A']);
                  l++;
              }
              if(r-l+1-maxFreq<=k){
                  maxLen = max(maxLen,r-l+1);
              }
              r++;
          }
          return maxLen;
      }
  };
// Time Complexity : O(N+N)
// Space Complexity : O(26)

// 3. Optimal Sliding Window Approach

class Solution {
  public:
      int characterReplacement(string s, int k) {
          vector<int> hash(26,0);
          int maxFreq = 0;
          int maxLen = 0;
          int n = s.size();
          int l = 0;
          int r = 0;
          while(r<n){
              hash[s[r]-'A']++;
              maxFreq = max(maxFreq,hash[s[r]-'A']);
              if(r-l+1-maxFreq>k){
                  hash[s[l]-'A']--;
                  maxFreq = max(maxFreq,hash[s[l]-'A']);
                  l++;
              }
              if(r-l+1-maxFreq<=k){
                  maxLen = max(maxLen,r-l+1);
              }
              r++;
          }
          return maxLen;
      }
  };
//  Time Complexity : O(N)
// Space Complexity : O(26)