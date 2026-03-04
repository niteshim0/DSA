// LC 1582. Special Positions in a Binary Matrix
// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/

// Concepts :: Precomputation + Just Simple Count

// Approach :: For every row and col , count the no of 1's, check if mat[i][j] == 1 alongwith rowCount[i] = 1 && colCount[i] == 1 , then that is the special positions in a matrix.

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<int> rowSum(n,0);
        vector<int> colSum(m,0);

        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                rowSum[row]+=mat[row][col];
                colSum[col]+=mat[row][col];
            }
        }

        int cnt = 0;

        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(mat[row][col] == 1 && rowSum[row] == 1 && colSum[col] == 1){
                     cnt++;
                }
            }
        }
        return cnt;
    }
};

// Time Complexity : O(M*N)
// Space Complexity : O(M+N)