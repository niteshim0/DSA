//LC 435 :: https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
        [&](auto &a,auto &b){
            return a[1] < b[1];
        });

        int end = intervals[0][1];
        int cnt = 0 , n = intervals.size();
        for(int i = 1;i<n;i++){
            if(end <= intervals[i][0]){
                end = intervals[i][1];
            }else{
                cnt++;
            }
        }

        return cnt;
    }
};


// Time Complexity : O(NLogN)
// Space Complexity : O(N)