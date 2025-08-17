// DFS Approach
// similar to surrounded region
class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& board,int delrow[],int delcol[]){
        board[row][col] = 2;
        int n = board.size() , m = board[0].size();
        for(int i = 0;i<4;i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc] == 1){
                dfs(nr,nc,board,delrow,delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int,int>> qp;
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 1) {
                    dfs(i,j,board,delrow,delcol);
                }
            }
        }
        
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1){
                    cnt++;
                }else if(board[i][j] == 2){
                    board[i][j] = 1;
                }
            }
        }
        return cnt;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

// BFS Approach
class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int,int>> qp;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 1) {
                    qp.push({i, j});
                    board[i][j] = 2; 
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
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 1) {
                    qp.push({nr, nc});
                    board[nr][nc] = 2;
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1) cnt++;
                else if(board[i][j] == 2) board[i][j] = 1;
            }
        }

        return cnt;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)