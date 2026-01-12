// https://leetcode.com/problems/minimum-time-visiting-all-points/description/
// LC 1266. Minimum Time Visiting All Points

// Concept :: Coordinate Geometry
// Idea :: cover as much distance by diagonal way , then go in straight line(horizontal or vertical)


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        int n = points.size();

        for(int i = 1;i<n;i++){
            int x = abs(points[i][0] - points[i-1][0]);
            int y = abs(points[i][1] - points[i-1][1]);

            ans+=max(x,y);
        }

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)