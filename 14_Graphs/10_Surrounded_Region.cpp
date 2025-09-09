// BFS Approach
// if O is somehow attached to the boundary then , it will never be surrounded,
// this is the logic used here
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> qp;

        // Step 1: mark boundary 'O's and BFS
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O') {
                    qp.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        while(!qp.empty()) {
            auto [row,col] = qp.front();
            qp.pop();
            for(int k = 0; k < 4; k++) {
                int nr = row + delrow[k];
                int nc = col + delcol[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O') {
                    qp.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        // Step 2: flip unvisited 'O's into 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// Time Complexity: O(N × M) (each cell visited at most once)
// 👉 Space Complexity: O(N × M) for the visited matrix + BFS queue

// Without vis array
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int,int>> qp;

        // Step 1: mark boundary 'O's with BFS
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O') {
                    qp.push({i, j});
                    board[i][j] = '#'; // mark as visited
                }
            }
        }

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        while(!qp.empty()) {
            auto [row, col] = qp.front();
            qp.pop();
            for(int k = 0; k < 4; k++) {
                int nr = row + delrow[k];
                int nc = col + delcol[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O') {
                    qp.push({nr, nc});
                    board[nr][nc] = '#'; // mark as visited
                }
            }
        }

        // Step 2: flip all remaining 'O' -> 'X', and '#' -> 'O'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

// DFS Approach
class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& board,int delrow[],int delcol[]){
        board[row][col] = '#';
        int n = board.size() , m = board[0].size();
        for(int i = 0;i<4;i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc] == 'O'){
                dfs(nr,nc,board,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int,int>> qp;
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        // Step 1: mark boundary 'O's with BFS
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O') {
                    dfs(i,j,board,delrow,delcol);
                }
            }
        }

        // Step 2: flip all remaining 'O' -> 'X', and '#' -> 'O'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
// Time Complexity : O(N*M)
// Space Complexity : O(N*M)
