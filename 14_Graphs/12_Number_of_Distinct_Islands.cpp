// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
// Idea :: We need to capture the shape of the island by storing relative coordinates with respect to the starting cell (row0, col0).

// DFS Approach
class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& vec,int row0,int col0){
        vis[row][col] = 1;
        vec.push_back({row-row0,col-col0});
        int n = grid.size() , m = grid[0].size();
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        for(int i = 0;i<4;i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&  grid[nr][nc] == 1){
                dfs(nr,nc,grid,vis,vec,row0,col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(!vis[row][col] && grid[row][col]){
                    vector<pair<int,int>> vec;
                    dfs(row,col,grid,vis,vec,row,col);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

// Time Complexity : O(N*M*log(N*M) + N*M*4)
// Space Complexity : O(N*M)

// BFS Approach
class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, vector<pair<int,int>>& vec,
             int row0, int col0) {
        
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Store relative coordinates
            vec.push_back({r - row0, c - col0});

            // Explore neighbors
            for(int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   grid[nr][nc] == 1 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(!vis[row][col] && grid[row][col] == 1) {
                    vector<pair<int,int>> vec;
                    bfs(row, col, grid, vis, vec, row, col);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

// Time Complexity: O(N*M * logK)
// Each cell visited once → O(N*M).
// Insertion in set takes logK where K = number of distinct shapes.
// Space Complexity: O(N*M) for visited + queue.