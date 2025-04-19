class Solution {
  public:
      static int cmp(vector<int>&a , vector<int>& b){
         return a[1]<b[1];
      }
      int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          sort(intervals.begin(),intervals.end(),cmp);
          int n = intervals.size();
          int ending = INT_MIN;
          int cnt = 0;
          for(auto &vec : intervals){
              if(vec[0]>=ending){
                  ending = vec[1];
                  cnt++;
              }
          }
          return n-cnt;
      }
  };
// Time Complexity : O(NlogN + O(N))
// Space Complexity : O(2*N)