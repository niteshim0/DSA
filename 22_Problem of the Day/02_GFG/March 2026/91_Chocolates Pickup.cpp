// Chocolates Pickup
// https://www.geeksforgeeks.org/problems/chocolates-pickup/1

// Concepts :: 3D Dynamic Programming

// Key Idea
/*
Two robots move simultaneously → track both positions together
So state becomes: (row, col1, col2)

Each robot has 3 moves → total 9 transitions
Avoid double count when col1 == col2
*/

// 2. Intuition
// At every row, both robots pick chocolates
// Then try all 9 combinations of next moves
// Choose the maximum possible future sum


// Approach I : Try all Combinations (Recursion) (Brute Force)

class Solution {
public:
    int f(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid) {
        
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e8;
        
        if(i == n-1) {
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        
        int maxi = 0;
        
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                
                int val;
                if(j1 == j2)
                    val = grid[i][j1];
                else
                    val = grid[i][j1] + grid[i][j2];
                
                val += f(i+1, j1+dj1, j2+dj2, n, m, grid);
                maxi = max(maxi, val);
            }
        }
        
        return maxi;
    }

    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        return f(0, 0, m-1, n, m, grid);
    }
};

// Time Complexity :O(9^n) ❌ (TLE)
// Space: O(n) recursion stack

// Approach II :: Memoization

class Solution {
public:
    int f(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e8;
        
        if(i == n-1) {
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = 0;
        
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                
                int val;
                if(j1 == j2)
                    val = grid[i][j1];
                else
                    val = grid[i][j1] + grid[i][j2];
                
                val += f(i+1, j1+dj1, j2+dj2, n, m, grid, dp);
                maxi = max(maxi, val);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }

    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m-1, n, m, grid, dp);
    }
};

// Complexity:
// Time: O(n * m² * 9) ≈ O(n * m²)
// Space: O(n * m²) + recursion stack


// Approach III :: Tabulation

class Solution {
public:
    int maxChocolate(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        
        // Base case
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2)
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    
                    int maxi = 0;
                    
                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            
                            if(nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                
                                int val;
                                if(j1 == j2)
                                    val = grid[i][j1];
                                else
                                    val = grid[i][j1] + grid[i][j2];
                                
                                val += dp[i+1][nj1][nj2];
                                maxi = max(maxi, val);
                            }
                        }
                    }
                    
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};

// Complexity:
// Time: O(n * m²)
// Space: O(n * m²)


// Approach IV :: Space Optimized

class Solution {
public:
    int maxChocolate(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> front(m, vector<int>(m, 0)), cur(m, vector<int>(m, 0));
        
        // Base case
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2)
                    front[j1][j2] = grid[n-1][j1];
                else
                    front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    
                    int maxi = 0;
                    
                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            
                            if(nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                
                                int val;
                                if(j1 == j2)
                                    val = grid[i][j1];
                                else
                                    val = grid[i][j1] + grid[i][j2];
                                
                                val += front[nj1][nj2];
                                maxi = max(maxi, val);
                            }
                        }
                    }
                    
                    cur[j1][j2] = maxi;
                }
            }
            front = cur;
        }
        
        return front[0][m-1];
    }
};

// Complexity:
// Time: O(n * m²)
// Space: O(m²) ✅