class Solution {
public:
    void backtrack(int row, int col, string path, vector<vector<int>>& m, 
                   vector<vector<bool>>& visited, vector<string>& ans, int n) {
        // Base cases: out of bounds, blocked cell, or already visited
        if (row < 0 || col < 0 || row >= n || col >= n || 
            m[row][col] == 0 || visited[row][col]) {
            return;
        }

        // Destination reached
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[row][col] = true;

        // Move in lexicographical order: D, L, R, U
        backtrack(row + 1, col, path + 'D', m, visited, ans, n);
        backtrack(row, col - 1, path + 'L', m, visited, ans, n);
        backtrack(row, col + 1, path + 'R', m, visited, ans, n);
        backtrack(row - 1, col, path + 'U', m, visited, ans, n);

        visited[row][col] = false; // Backtrack
    }

    vector<string> ratInMaze(vector<vector<int>>& m) {
        int n = m.size();
        vector<string> ans;

        // If start or end is blocked
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return ans;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        backtrack(0, 0, "", m, visited, ans, n);

        return ans;
    }
};

## 🧠 Time and Space Complexity

### ✅ Time Complexity: `O(4^(n^2))`
- In the worst case, from each cell, the rat can move in 4 directions (D, L, R, U).
- There are `n x n` cells, and the rat may explore each path recursively.
- Thus, the number of recursive calls in the worst case is exponential: `O(4^(n^2))`.

> Note: The actual number is usually less due to constraints like walls (`0` values) and visited cells.

### ✅ Space Complexity:
- **O(n^2)** → For the `visited` matrix used to track visited cells.
- **O(n^2)** → Maximum depth of the recursion stack (in the worst case, the rat may visit each cell once per path).
- **O(k × L)** → To store all valid paths:
  - `k` = number of valid paths.
  - `L` = average length of each path (up to `2n-2` characters in worst case).

> Overall space complexity: **O(n^2 + k × L)**
