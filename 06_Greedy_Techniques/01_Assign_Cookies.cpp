class Solution {
  public:
      int findContentChildren(vector<int>& g, vector<int>& s) {
          sort(g.begin(),g.end());
          sort(s.begin(),s.end());
          int i = g.size()-1;
          int j = s.size()-1;
          int cnt = 0;
          while(i>=0 && j>=0){
              if(s[j]>=g[i]){
                  i--;
                  j--;
                  cnt++;
              }else{
                  i--;
              }
          }
          return cnt;
      }
  };
// Time Compleixty : O(NlogN + MLogM  + O(min(M,N)))
// Space Complexity : O(1)