// LC 1351 .Count Negative Numbers in a Sorted Matrix
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/?envType=daily-question&envId=2025-12-28


// Approach I : Binary Search on Each Row
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid[0].size();

        for (auto& row : grid) {
            int idx = lower_bound(row.begin(), row.end(), -1, greater<int>()) - row.begin();
            cnt += (n - idx);
        }

        return cnt;
    }
};
// Time Complexity : O(NlogM)
// Space Complexity : O(1)

// Approach II : Two Pointers
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int row = 0, col = n - 1;
    int count = 0;

    while (row < m && col >= 0) {
        if (grid[row][col] < 0) {
            count += (m - row);
            col--;
        } else {
            row++;
        }
    }
    return count;
}
};
// Time Complexity : O(M+N)
// Space Complexity : O(1)