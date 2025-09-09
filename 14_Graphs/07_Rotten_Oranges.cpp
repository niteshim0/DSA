// extra visted array is not needed as once the orange gets rotten , we are not visiting it anymore according to the question condition.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        
        int fresh = 0;
        queue<pair<pair<int,int>,int>> qp;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    qp.push({{i, j}, 0});
                }
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        int timer = 0, rotten = 0;
        
        while(!qp.empty()){
            auto [p, time] = qp.front();
            qp.pop();
            int row = p.first, col = p.second;
            timer = max(timer, time);
            
            for(int i = 0; i < 4; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;   
                    qp.push({{nr, nc}, time + 1});
                    rotten++;
                }
            }
        }
        
        return (rotten == fresh) ? timer : -1;
    }
};
// Time Complexity : O(N*M)
// Space Complexity : O(N*M)