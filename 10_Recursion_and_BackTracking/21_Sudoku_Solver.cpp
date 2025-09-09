class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch 
            || board[i][col] == ch
            || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) 
            return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, row, col, ch)) {
                            board[row][col] = ch; // ✅ Place the number

                            if (solve(board)) return true; // ✅ Recurse

                            board[row][col] = '.'; // ❌ Backtrack
                        }
                    }
                    return false; // ❌ If no valid number can be placed
                }
            }
        }
        return true; // ✅ Board is fully filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
// Time Complexity : O(9^N) // N - No of empty cells
// Space Complexity : O(N) // for recursion 
// in practice : O(81) = O(1) // constant time