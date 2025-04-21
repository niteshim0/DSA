class Solution {
  public:
      vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          int n = intervals.size();
          int i = 0;
          vector<vector<int>> res;
          while(i<n && intervals[i][1]<newInterval[0]){
              res.push_back(intervals[i]);
              i++;
          }
          // collides
          while(i<n && intervals[i][0]<=newInterval[1]){
              newInterval[0] = min(newInterval[0],intervals[i][0]);
              newInterval[1] = max(newInterval[1],intervals[i][1]);
              i++;
          }
          res.push_back(newInterval);
          while(i<n){
              res.push_back(intervals[i]);
              i++;
          }
          return res;
      }
  };
  // Time Complexity : O(N)
  // Space Complexity : O(N)

  class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            int n = intervals.size();
            if(n == 0) return {newInterval};
    
            // finding the insertion position
            int start = 0;
            int end = n-1;
            int target = newInterval[0];
            while(start <= end){
                int mid = start + (end - start) / 2;
                if(intervals[mid][0] < target){
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            
            intervals.insert(intervals.begin() + start, newInterval);
    
            vector<vector<int>> res;
            for(auto &vec : intervals){
                if(res.empty() || res.back()[1] < vec[0]){
                    res.push_back(vec);
                } else {
                    res.back()[1] = max(res.back()[1], vec[1]);
                }
            }
            return res;
        }
    };
// Time Complexity : O(N)
// Space Complexity : O(N)