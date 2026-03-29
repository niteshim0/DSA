// 3882. Minimum XOR Path in a Grid
// https://leetcode.com/problems/minimum-xor-path-in-a-grid/
class Solution {
public:
    int m, n;
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // going for iteration
        vector<vector<unordered_set<int>>> dp(m,vector<unordered_set<int>>(n));
        dp[0][0].insert(grid[0][0]); 

        
        for(int row = 0 ; row < m ; row++){

            for(int col = 0 ; col < n ; col++){

                if(row == 0 && col == 0) continue;

                if(row > 0){

                    for(int x : dp[row-1][col]){

                        dp[row][col].insert(x^grid[row][col]);
                    }
                }

                if(col > 0){

                    for(int x : dp[row][col-1]){

                        dp[row][col].insert(x^grid[row][col]);
                    }
                }
            }
        }

        int mini = INT_MAX;

        for(int x : dp[m-1][n-1]){

            mini = min(mini,x);
        }

        return mini;
    }
};