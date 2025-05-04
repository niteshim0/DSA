// 1. Brute Force Approach

class Solution {
  public:
      int totalFruit(vector<int>& fruits) {
          int n = fruits.size();
          int maxLen = 0;
          for(int i = 0;i<n;i++){
              set<int> st;
              for(int j = i;j<n;j++){
                  st.insert(fruits[j]);
                  if(st.size()<=2){
                      maxLen = max(maxLen,j-i+1);
                  }else{
                      break;
                  }
              }
          }
          return maxLen;
      }
  };
// Time Complexity : O(N*(N+1)/2)
// Space Complexity : O(3)

// 2. Sliding Window Approach

class Solution {
  public:
      int totalFruit(vector<int>& fruits) {
          int k = 2;
          unordered_map<int,int> mp;
          int l = 0;
          int r = 0;
          int n = fruits.size();
          int maxLen = 0;
          int cnt =0;
          while(r<n){
              mp[fruits[r]]++;
              while(mp.size()>k){
                  int x = fruits[l];
                  mp[x]--;
                  if(mp[x]==0) mp.erase(x);
                  l++;
              }
              if(mp.size()<=k){
                   maxLen = max(maxLen,r-l+1);
              }
              r++;
          }
          return maxLen;
      }
  };
// Time Complexity : O(2*N)
// Space Complexity : O(1)

// 3. Optimal Sliding Window Approach

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        unordered_map<int,int> mp;
        int l = 0;
        int r = 0;
        int n = fruits.size();
        int maxLen = 0;
        int cnt =0;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>k){
                int x = fruits[l];
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
                l++;
            }
            if(mp.size()<=k){
                 maxLen = max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};
// Time Complexity : O(N)
// Space Complexity: O(1)