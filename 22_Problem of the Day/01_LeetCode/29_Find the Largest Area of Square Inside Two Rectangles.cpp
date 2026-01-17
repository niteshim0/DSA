// LC 3047. Find the Largest Area of Square Inside Two Rectangles
// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
// Concept :: Brute Force is Optimal + Coordinate Geometry + Math

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {

        int n = bottomLeft.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int left   = max(bottomLeft[i][0], bottomLeft[j][0]);
                int right  = min(topRight[i][0],   topRight[j][0]);
                int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                int top    = min(topRight[i][1],   topRight[j][1]);

                if (left < right && bottom < top) {
                    long long side = min(right - left, top - bottom);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O((N^2+N)/2)
// Space Complexity : O(1)
