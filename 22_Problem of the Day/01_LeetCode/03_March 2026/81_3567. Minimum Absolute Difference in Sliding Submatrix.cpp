// LC 3567. Minimum Absolute Difference in Sliding Submatrix
// https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/

// Concepts :: Sorting + 2D Array Traversal + SubMatrix traversal inside it + distinct element difference

// Approach :: Just do what question said, brute force your way to the ques.

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int n = grid.size() ,  m = grid[0].size();

        vector<vector<int>> res(n-k+1,vector<int>(m-k+1));

        for(int row = 0;row+k<=(n);row++){

            for(int col = 0;col+k<=(m);col++){

                vector<int> kGrid;
                  
                for(int x = row; x< row+k; x++){

                    for(int y = col; y< col+k; y++){
                         
                        kGrid.push_back(grid[x][y]);

                    }
                }

                int mini = INT_MAX;

                sort(kGrid.begin(),kGrid.end());

                for(int t = 1;t<kGrid.size();t++){

                    if(kGrid[t] == kGrid[t-1]) continue;

                    mini = min(mini,kGrid[t] - kGrid[t-1]);

                }

                if(mini!=INT_MAX){
                    res[row][col] = mini;
                }
                
            }
        }

        return res;
    }
};

// Time Complexity : O(M*N*K*K*log(K))
// Space Complexity : O(K*K)