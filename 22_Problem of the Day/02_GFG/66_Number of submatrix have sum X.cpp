// Number of submatrix have sum X
// https://www.geeksforgeeks.org/problems/number-of-submatrix-have-sum-k/1

// Concepts :: 2D Prefix Sum + Square Matrix Knowledge

class Solution {
  public:
  
    // what i missed was -> we have been asked square submatrix.
    // so n, m is small
    // we can create the prefix
    // and for each cell we can just find all n square sum
    
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        
        int n = mat.size(), m = mat[0].size(), res = 0;
        
        vector<vector<int>>pre(n+1, vector<int>(m+1, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                pre[i+1][j+1] = mat[i][j];
                
                pre[i+1][j+1] += pre[i][j+1];
                pre[i+1][j+1] += pre[i+1][j];
                pre[i+1][j+1] -= pre[i][j];
            }
        }
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                for(int len = 1; len <= min(i, j); len++)
                {
                    int curr = pre[i][j];
                    
                    curr -= pre[i-len][j];
                    curr -= pre[i][j-len];
                    curr += pre[i-len][j-len];
                    
                    if(curr == x) res++;
                }
            }
        }
        
        return res;
    }
};

// Time Complexity : O(M*N*min(N,M))
// Space Complexity : O(M*N)