// Approach 1
class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board) {
        int duprow = row, dupcol = col;
        // upper left diagonal
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--; col--;
        }
        row = duprow; col = dupcol;
        // left row
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = duprow; col = dupcol;
        int n = board.size();
        // lower left diagonal
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++; col--;
        }
        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans) {
        if(col == board.size()){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < board.size(); row++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                solve(col + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, board, ans);
        return ans;
    }
};
// Time Complexity : O(N!*N)
// Space Complexity : O(N*N)

// Approach-II

class Solution {
public:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal) {
        int n = board.size();
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};
// Time Complexity : O(N!)
// Space Complexity : O(N*N)