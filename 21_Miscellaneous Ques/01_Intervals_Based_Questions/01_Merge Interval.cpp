// LC 56 :: https://leetcode.com/problems/merge-intervals/description/
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        
        sort(arr.begin(),arr.end(),
        [&](vector<int>& first, vector<int>& second){
            return first[0] < second[0];
        });
        
        
        vector<vector<int>> res;
        for(auto &vec : arr){
            if(res.empty() || res.back()[1] < vec[0]){
                res.push_back(vec);
            } else {
                res.back()[1] = max(res.back()[1], vec[1]);
            }
        }
        return res;
    }
};