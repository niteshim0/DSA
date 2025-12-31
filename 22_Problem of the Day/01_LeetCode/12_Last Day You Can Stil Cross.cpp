// LC 1970 : Last Day Where You Can Still Cross
// https://leetcode.com/problems/last-day-where-you-can-still-cross/


class Solution {
public:
    bool canCross(vector<vector<int>>& cells, int n, int m, int day) {
        
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < day; i++) {
            matrix[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> qp;

        for (int col = 0; col < m; col++) {
            if (matrix[0][col] == 0) {   
                vis[0][col] = 1;
                qp.push({0, col});
            }
        }

        int dx[4] = {1, -1, 0, 0};     
        int dy[4] = {0, 0, -1, 1};     

        while (!qp.empty()) {
            auto [row, col] = qp.front();
            qp.pop();

            if (row == n - 1) return true;

            for (int i = 0; i < 4; i++) {   
                int nr = row + dx[i];
                int nc = col + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !vis[nr][nc] && matrix[nr][nc] == 0) {

                    vis[nr][nc] = 1;
                    qp.push({nr, nc});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int start = 1, end = cells.size();
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (canCross(cells, row, col, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

// Aspect	Complexity
// Time	O((R×C) log(R×C))
// Space	O(R×C)
