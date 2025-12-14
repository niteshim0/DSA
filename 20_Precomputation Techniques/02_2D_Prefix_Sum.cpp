// https://www.geeksforgeeks.org/problems/2d-submatrix-sum-queries/1
// Way I :: handling boundary conditions explicitly
class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> prefSum(n, vector<int>(m, 0));
        

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                prefSum[i][j] = mat[i][j]
                    + (i > 0 ? prefSum[i-1][j] : 0)
                    + (j > 0 ? prefSum[i][j-1] : 0)
                    - (i > 0 && j > 0 ? prefSum[i-1][j-1] : 0);
            }
        }

        vector<int> ans;
    
        for(auto &q : queries){
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            
            int need = prefSum[r2][c2]
                - (r1 > 0 ? prefSum[r1-1][c2] : 0)
                - (c1 > 0 ? prefSum[r2][c1-1] : 0)
                + (r1 > 0 && c1 > 0 ? prefSum[r1-1][c1-1] : 0);
            
            ans.push_back(need);
        }
        return ans;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N*N)

// Way II : Shifting rows and cols by +1 for handling boundary condition (better way)
class Solution {
public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();

        // Extra row and column (+1 shifting)
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        // Build prefix sum matrix
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i-1][j-1]
                            + pref[i-1][j]
                            + pref[i][j-1]
                            - pref[i-1][j-1];
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int r1 = q[0] + 1, c1 = q[1] + 1;
            int r2 = q[2] + 1, c2 = q[3] + 1;

            int sum = pref[r2][c2]
                    - pref[r1-1][c2]
                    - pref[r2][c1-1]
                    + pref[r1-1][c1-1];

            ans.push_back(sum);
        }

        return ans;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N*N)