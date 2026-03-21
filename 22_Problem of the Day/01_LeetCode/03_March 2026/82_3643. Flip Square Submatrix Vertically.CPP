// LC 3643. Flip Square Submatrix Vertically
// https://leetcode.com/problems/flip-square-submatrix-vertically/description/?envType=daily-question&envId=2026-03-21

// Concepts :: Two Pointers + Simulation + Matrix

// Approach :: Apply two pointers both between the end of the rows , and swap the columns of those extreme rows.

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int start = x;
        int end   = x+k-1;
        while(start<end){
            for(int i = 0;i<k;i++){
                int temp = grid[start][i+y];
                grid[start][i+y] = grid[end][i+y];
                grid[end][i+y] = temp;
            }
            start++;
            end--;
        }
        return grid;
    }
};

// Time Complexity : O(K*K)
// Space Complexity : O(1)