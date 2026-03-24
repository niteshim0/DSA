// LC 2906. Construct Product Matrix
// https://leetcode.com/problems/construct-product-matrix/description/

// Concepts :: Flattening of 2D Matrix into 1D Array + Prefix Product + Suffix Product + MOD Knowledge

// KEY IDEA :: Flatten the 2d matrix into 1d array -> calcualte suffix in first traversal and prefix in 2nd , and for grid[i][j] -> multiply them both i.e. , grid[i][j] = prefix[i][j] * suffix[i][j] . we will reach our answer

class Solution {
public:

    const int MOD = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size();

        vector<vector<int>> productMatrix(n,vector<int>(m,1));

        long long suffix  = 1;

        for(int row = n-1; row>=0; row--){

            for(int col = m-1; col>=0; col--){

                productMatrix[row][col] = suffix;

                suffix = (suffix * grid[row][col]) % MOD;
            }
        }

        long long prefix = 1;

        for(int row = 0; row<n; row++){

            for(int col = 0;col<m; col++){

                productMatrix[row][col] = (productMatrix[row][col] * prefix) % MOD;

                prefix = (prefix * grid[row][col]) % MOD;

            }
        }

        return productMatrix;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(1) // excluding the matrix required for ans