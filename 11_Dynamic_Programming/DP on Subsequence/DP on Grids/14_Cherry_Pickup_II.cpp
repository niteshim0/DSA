// 1. Recursive Solution

class Solution {
public:
    // Recursive Solution
    int solve(int row, int col1, int col2, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return -1e8;

        if (row == n - 1) {
            if (col1 == col2) {
                return grid[row][col1];
            } else {
                return grid[row][col1] + grid[row][col2];
            }
        }

        int maxCherries = -1e8;
        for (int move1 = -1; move1 <= 1; move1++) {
            for (int move2 = -1; move2 <= 1; move2++) {
                int nextCol1 = col1 + move1;
                int nextCol2 = col2 + move2;

                int cherries = (col1 == col2) ? grid[row][col1]
                                              : grid[row][col1] + grid[row][col2];

                cherries += solve(row + 1, nextCol1, nextCol2, grid);

                maxCherries = max(maxCherries, cherries);
            }
        }

        return maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solve(0, 0, m - 1, grid);
    }
};

// Time Complexity: O(9^n)
// Space Complexity: O(n)  // recursion depth is at most n

// 2.Memoization Solution

class Solution {
public:
    int solve(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return -1e8;

        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

        if (row == n - 1) {
            if (col1 == col2) {
                return grid[row][col1];
            } else {
                return grid[row][col1] + grid[row][col2];
            }
        }

        int maxCherries = -1e8;
        for (int move1 = -1; move1 <= 1; move1++) {
            for (int move2 = -1; move2 <= 1; move2++) {
                int nextCol1 = col1 + move1;
                int nextCol2 = col2 + move2;

                int cherries = (col1 == col2) ? grid[row][col1]
                                              : grid[row][col1] + grid[row][col2];

                cherries += solve(row + 1, nextCol1, nextCol2, grid, dp);

                maxCherries = max(maxCherries, cherries);
            }
        }

        return dp[row][col1][col2] = maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m - 1, grid, dp);
    }
};

// Time Complexity: O(N * M * M * 9) ≈ O(N * M^2)
// Space Complexity: O(N * M * M) for dp + O(N) recursion stack


// 3. Tabulation Solution

class Solution {
public:
    // Tabulation Solution
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int col1 = 0; col1 < m; col1++) {
            for (int col2 = 0; col2 < m; col2++) {
                if (col1 == col2)
                    dp[n - 1][col1][col2] = grid[n - 1][col1];
                else
                    dp[n - 1][col1][col2] = grid[n - 1][col1] + grid[n - 1][col2];
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col1 = 0; col1 < m; col1++) {
                for (int col2 = 0; col2 < m; col2++) {
                    int maxCherries = -1e8;
                    for (int move1 = -1; move1 <= 1; move1++) {
                        for (int move2 = -1; move2 <= 1; move2++) {
                            int nextCol1 = col1 + move1;
                            int nextCol2 = col2 + move2;

                            if (nextCol1 >= 0 && nextCol1 < m && nextCol2 >= 0 && nextCol2 < m) {
                                int cherries = (col1 == col2)
                                    ? grid[row][col1]
                                    : grid[row][col1] + grid[row][col2];

                                cherries += dp[row + 1][nextCol1][nextCol2];

                                maxCherries = max(maxCherries, cherries);
                            }
                        }
                    }
                    dp[row][col1][col2] = maxCherries;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};

// Time Complexity: O(N * M * M * 9) ≈ O(N * M^2)
// Space Complexity: O(N * M * M)


// 4. Space Optmised Tabulation Solution
class Solution {
public:
    // Space Optimised Tabulation Solution
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prev(m, vector<int>(m, 0));

        for (int col1 = 0; col1 < m; col1++) {
            for (int col2 = 0; col2 < m; col2++) {
                if (col1 == col2)
                    prev[col1][col2] = grid[n - 1][col1];
                else
                    prev[col1][col2] = grid[n - 1][col1] + grid[n - 1][col2];
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            vector<vector<int>> curr(m,vector<int>(m,0));
            for (int col1 = 0; col1 < m; col1++) {
                for (int col2 = 0; col2 < m; col2++) {
                    int maxCherries = -1e8;
                    for (int move1 = -1; move1 <= 1; move1++) {
                        for (int move2 = -1; move2 <= 1; move2++) {
                            int nextCol1 = col1 + move1;
                            int nextCol2 = col2 + move2;

                            if (nextCol1 >= 0 && nextCol1 < m && nextCol2 >= 0 && nextCol2 < m) {
                                int cherries = (col1 == col2)
                                    ? grid[row][col1]
                                    : grid[row][col1] + grid[row][col2];

                                cherries += prev[nextCol1][nextCol2];

                                maxCherries = max(maxCherries, cherries);
                            }
                        }
                    }
                    curr[col1][col2] = maxCherries;
                }
            }
            prev = curr;
        }

        return prev[0][m - 1];
    }
};

// Time Complexity: O(N * M * M * 9) ≈ O(N * M^2)
// Space Complexity: O (M * M)
