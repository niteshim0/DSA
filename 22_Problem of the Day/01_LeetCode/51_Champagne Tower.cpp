// 799. Champagne Tower
// https://leetcode.com/problems/champagne-tower/
// Concept :: Dynamic Programming + Simulation


// Interview Explaination

/*
Key Insights :: 
Each glass can hold at most 1 unit of champagne.
Any extra overflows equally to the two glasses below it.

--> Solution 
I simulate this using Dynamic Programming.
dp[row][glass] stores how much champagne reaches glass (row, glass)
I start with all champagne poured into dp[0][0]
For each glass:
If dp[row][glass] > 1, the excess (dp[row][glass] − 1) is split equally to:
dp[row+1][glass]
dp[row+1][glass+1]
Each glass is capped at 1
*/

// Technique 1 :: Memoization(Top Down Approach)

class Solution {
    double memo[101][101];

public:
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i = 0; i < 101; i++) 
            for(int j = 0; j < 101; j++) 
                memo[i][j] = -1.0;
        
        double res = solve(query_row, query_glass, poured);
        return min(1.0, max(0.0, res));
    }

    double solve(int r, int g, int poured) {
        if (r == 0 && g == 0) return (double)poured;
        if (g < 0 || g > r) return 0.0;
        if (memo[r][g] != -1.0) return memo[r][g];

        double leftParent = (solve(r - 1, g - 1, poured) - 1.0) / 2.0;
        double rightParent = (solve(r - 1, g, poured) - 1.0) / 2.0;

        double total = max(0.0, leftParent) + max(0.0, rightParent);
        return memo[r][g] = total;
    }
};

// Time Complexity : (query_row)*(query_row+1) / 2
// Space Complexity : O(query_row^2) +O(query_row)//recursion stack space

// Technique 2 :: Tablulation Approach (Bottom Up)
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0.0));
        dp[0][0] = poured;

        for (int row = 0; row <= query_row; row++) {
            for (int glass = 0; glass <= row; glass++) {
                if (dp[row][glass] > 1.0) {
                    double extra = dp[row][glass] - 1.0;
                    dp[row][glass] = 1.0;
                    dp[row + 1][glass]     += extra / 2.0;
                    dp[row + 1][glass + 1] += extra / 2.0;
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};

// Time Complexity : (query_row)*(query_row+1) / 2
// Space Complexity : P(query_row^2)

// Technique 3 :: Space Optimized
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
      
        vector<double> dp(101, 0.0);
        dp[0] = (double)poured;

        for (int row = 0; row < query_row; row++) {
            for (int glass = row; glass >= 0; glass--) {
                double extra = (dp[glass] - 1.0) / 2.0;
                
                if (extra > 0) {
                    dp[glass + 1] += extra;
                    dp[glass] = extra; 
                } else {
                    dp[glass] = 0.0;
                }
            }
        }
        return min(1.0, dp[query_glass]);
    }
};

// Time Complexity : (query_row)*(query_row+1) / 2
// Space Complexity : O(101)


