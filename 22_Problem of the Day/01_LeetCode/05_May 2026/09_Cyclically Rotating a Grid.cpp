// LC 1914 . Cyclically Rotating a Grid
// https://leetcode.com/problems/cyclically-rotating-a-grid

// Concepts :: Array + Simulation

// Simulate cyclic rotation by extracting each matrix layer into a linear array, rotating indices, and writing back.

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            int top = layer;
            int left = layer;

            int bottom = m - layer - 1;
            int right = n - layer - 1;

            vector<pair<int,int>> pos;

            for (int j = left; j <= right; j++) {
                pos.push_back({top, j});
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                pos.push_back({i, right});
            }

            for (int j = right; j >= left; j--) {
                pos.push_back({bottom, j});
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                pos.push_back({i, left});
            }

            vector<int> vals;

            for (auto &[r, c] : pos) {
                vals.push_back(grid[r][c]);
            }

            int sz = vals.size();

            int start = k % sz;

            for (int i = 0; i < sz; i++) {

                int idx = (i + start) % sz;

                auto &[r, c] = pos[i];

                grid[r][c] = vals[idx];
            }
        }

        return grid;
    }
};


// More simplfied but duplication of code

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        // only i have to deal with boundary
        // move inside only if there is something to move

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m,n) / 2;

        for(int layer = 0 ; layer < layers ; layer++){

            vector<int> vals;
            int top = layer;
            int left = layer;

            int bottom = m - layer - 1;
            int right  = n - layer  - 1;

            for(int j = left ; j<=right ; j++){

                vals.push_back(grid[top][j]);
            }

            for(int i = top+1 ; i<=bottom - 1 ; i++){
                vals.push_back(grid[i][right]);
            }

            for(int j = right ; j >=left ; j--){

                vals.push_back(grid[bottom][j]);
            }

            for(int i = bottom - 1 ; i >=top+1 ; i--){
                vals.push_back(grid[i][left]);
            }

            int sz = vals.size();

            int start = k % sz;

            int idx = start;

            for(int j = left ; j<=right ; j++){

                grid[top][j] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }

            for(int i = top+1 ; i<=bottom - 1 ; i++){

                grid[i][right] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }

            for(int j = right ; j >=left ; j--){

                grid[bottom][j] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }

            for(int i = bottom - 1 ; i>=top + 1 ; i--){

                grid[i][left] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }
        }


        return grid;
        
    }
};

// Time Complexity : O(M * N)
// Space Complexity : O(M * N)