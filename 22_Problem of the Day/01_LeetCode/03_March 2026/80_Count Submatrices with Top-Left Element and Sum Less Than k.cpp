// 3070. Count Submatrices with Top-Left Element and Sum Less Than k
// https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/

// Concepts :: 2D Prefix Sum + Matrix Traversal

// Approach :: Calculate the 2d prefixSum over matrix , and treat every (i,j) as bottom right corner , and if its sum is less than or equal to k , increase the cnt , otherwise don't travel on that row any further.

// Technique 1 :: With Space

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        vector<int> cols(m,0);
        int cnt = 0;
        for(int row = 0;row<n;row++){
            int subMatrixSum  = 0;
            for(int col = 0;col<m;col++){
                cols[col]+=grid[row][col];
                subMatrixSum+=cols[col];
                if(subMatrixSum<=k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};

// Time Complexity : O(M*N)
// Space Complexity : O(M)