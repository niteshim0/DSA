// Toeplitz matrix
// A Toeplitz matrix (also known as a diagonal-constant matrix) is a matrix in which every descending diagonal from left to right contains the same element.

// https://www.geeksforgeeks.org/problems/toeplitz-matrix/1


// 💡 Idea:

// Every element should match its top-left neighbor:

// mat[i][j] == mat[i-1][j-1]


class Solution {
public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(mat[i][j] != mat[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};

// Time Complexity : O(M * N)
// Space Complexity : O(1)