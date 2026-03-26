// LC 3548. Equal Sum Grid Partition II
// https://leetcode.com/problems/equal-sum-grid-partition-ii/description/?envType=daily-question&envId=2026-03-26


// Concepts :: Rotation Matrix + Hash Table + Enumeration of the Upper Matrix Sum

// Approach :: Rotation Matrix + Hash Table + Enumeration of the Upper Matrix Sum

/*
Intuition
This problem is an enhanced version of Equal Sum Grid Partition I, with additional constraints: at most one cell can be deleted, and the remaining part must remain connected after deletion.

When deletion is allowed, we need to consider both the choice of the split line and which side of the split to delete from. To simplify the reasoning, we assume that we only consider horizontal split lines and delete elements from the upper part of the grid.

By rotating the matrix three times by 90 
∘
  and applying the same logic each time, we can cover all four possible orientations of the split line and deletion direction.

Next, we determine the condition for a valid partition:

Let the sum of the upper part of the current grid be sum, and the total sum of the grid be total. Then the sum of the lower part is total−sum.

Suppose we remove an element x. To make both parts equal, we must have
sum−x=total−sum,
which simplifies to
x=2⋅sum−total.

Therefore, after processing each row, we only need to check whether there exists an element grid[i][j] such that grid[i][j]=2⋅sum−total.

We use a set to store elements that have appeared so far, allowing efficient lookup. We can pre-insert 0 into the set so that the "no deletion" case is handled naturally within the same logic.

Special cases:

First row handling:
While processing the first row, only the first and last elements can be removed. After computing the sum of the first row, we check whether grid[0][0], grid[0][n−1], or 0 satisfies the condition.

Single-column grid:
If the grid has only one column, the only removable elements are from the first or current row. After processing row i, we check whether grid[0][0], grid[i][0], or 0 satisfies the condition.

Single-row grid:
If the grid has only one row, horizontal splitting is not possible, so this case can be skipped.

In all other cases, any element in the upper part of the grid can be considered for deletion.

All scenarios are covered after performing three rotations.
*/

class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> temp(n, vector<int>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                temp[j][m - 1 - i] = grid[i][j];
            }
        }
        return temp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        long long totalSum = 0, sum = 0, diff = 0;

        for(auto &row : grid) {
            totalSum += accumulate(row.begin(), row.end(), 0LL);
        }

        unordered_set<long long> exist;

        for(int k = 0; k < 4; k++) {

            exist.clear();
            exist.insert(0);
            sum = 0;

            n = grid.size();
            m = grid[0].size();

            // case 1: single row → rotate
            if(n < 2) {
                grid = rotate(grid);
                continue;
            }

            // case 2: single column
            if(m == 1) {
                for(int row = 0; row < n - 1; row++) {
                    
                    sum += grid[row][0];
                    diff = 2LL * sum - totalSum;

                    if(diff == 0 || diff == grid[0][0] || diff == grid[row][0]) {
                        return true;
                    }
                }

                grid = rotate(grid);
                continue;
            }

            // general case
            for(int row = 0; row < n - 1; row++) {
                for(int col = 0; col < m; col++) {
                    exist.insert(grid[row][col]);
                    sum += grid[row][col];
                }

                diff = 2LL * sum - totalSum;

    
                if(row == 0) {
                    if(diff == 0 || diff == grid[0][0] || diff == grid[0][m - 1]) {
                        return true;
                    }
                    continue;
                }

                if(exist.contains(diff)) {
                    return true;
                }
            }

            grid = rotate(grid);
        }

        return false;
    }
};

// Time complexity: O(mn).
// Space complexity: O(mn).