// LC 986 :: https://leetcode.com/problems/interval-list-intersections/description/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        int n = A.size(), m = B.size();

        while(i < n && j < m){
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);

            if(start <= end){
                ans.push_back({start, end});
            }

            if(A[i][1] < B[j][1]){
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};
// Time Complexity : O(N + M)
// Space Complexity : O(N)