class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector(m,0));
        queue<pair<pair<int,int>,int>> qp;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
               if(mat[i][j] == 0){
                qp.push({{i,j},0});
                vis[i][j] = 1;
               }
            }
        }

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        while(!qp.empty()){
            auto [p,steps] = qp.front();
            qp.pop();
            int row = p.first , col = p.second;
            dist[row][col] = steps;
            for(int i = 0;i<4;i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    qp.push({{nr,nc},steps+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return dist;
    }
};
// Time Complexity : O(N*M)
// Space Complexity : O(N*M)