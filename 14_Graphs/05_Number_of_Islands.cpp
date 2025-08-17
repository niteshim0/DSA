// BFS Approach
class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        queue<pair<int,int>> qp;
        qp.push({row,col});
        vis[row][col] = 1;
        int n = grid.size() , m = grid[0].size();

        while(!qp.empty()){
            int r = qp.front().first;
            int c = qp.front().second;
            qp.pop();
            if(r-1>=0 && !vis[r-1][c] && grid[r-1][c] == '1'){ // up
                qp.push({r-1,c}); 
                vis[r-1][c] = 1;
            }
            if(c-1>=0 && !vis[r][c-1] && grid[r][c-1] == '1'){ // left
                qp.push({r,c-1});
                vis[r][c-1] = 1;
            }
            if(r+1<n && !vis[r+1][c] && grid[r+1][c] == '1'){ // down
                qp.push({r+1,c});
                vis[r+1][c] = 1;
            }
            if(c+1<m&& !vis[r][c+1] && grid[r][c+1] == '1'){ //right
                qp.push({r,c+1});
                vis[r][c+1] = 1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};
// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

// DFS Approach
class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[row][col] = 1;
        int n = grid.size() , m = grid[0].size();
            if(row-1>=0 && !vis[row-1][col] && grid[row-1][col] == '1'){ // up
                dfs(row-1,col,grid,vis);
            }
            if(col-1>=0 && !vis[row][col-1] && grid[row][col-1] == '1'){ // left
                dfs(row,col-1,grid,vis);
            }
            if(row+1<n && !vis[row+1][col] && grid[row+1][col] == '1'){ // down
                dfs(row+1,col,grid,vis);
            }
            if(col+1<m&& !vis[row][col+1] && grid[row][col+1] == '1'){ //right
                dfs(row,col+1,grid,vis);
            }
        }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};
// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

// DFS Iterative Approach
class Solution {
public:
    void dfsIterative(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size(), m = grid[0].size();
        stack<pair<int,int>> st;
        st.push({row, col});
        vis[row][col] = 1;

        while(!st.empty()) {
            auto [r, c] = st.top();
            st.pop();

            // Up
            if(r-1 >= 0 && !vis[r-1][c] && grid[r-1][c] == '1') {
                st.push({r-1, c});
                vis[r-1][c] = 1;
            }
            // Left
            if(c-1 >= 0 && !vis[r][c-1] && grid[r][c-1] == '1') {
                st.push({r, c-1});
                vis[r][c-1] = 1;
            }
            // Down
            if(r+1 < n && !vis[r+1][c] && grid[r+1][c] == '1') {
                st.push({r+1, c});
                vis[r+1][c] = 1;
            }
            // Right
            if(c+1 < m && !vis[r][c+1] && grid[r][c+1] == '1') {
                st.push({r, c+1});
                vis[r][c+1] = 1;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfsIterative(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M) // safer for larger inputs , no any fear of error of recursion stack overflow error