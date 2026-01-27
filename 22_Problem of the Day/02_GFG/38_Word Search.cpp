class Solution {
  public:
    bool dfs(int row,int col,vector<vector<char>> &mat, string &word,int idx,vector<vector<int>>& vis){
        if(idx == word.size()) return true;
        
        vis[row][col] = 1;
        
        int n = mat.size();
        int m = mat[0].size();
        int dr[] = {-1 , 0 , 1 , 0};
        int dc[] = {0 , -1 , 0 , 1};
        
        for(int i = 0; i<4 ; i++){
            int newr = row + dr[i];
            int newc = col + dc[i];
            if(newr >= 0 && newr < n && newc >= 0 && newc < m && 
            !vis[newr][newc] && mat[newr][newc] == word[idx]){
                if(dfs(newr , newc , mat , word , idx+1 , vis)) return true;     
            }  
        }
        
        vis[row][col] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();
        int idx = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == word[0]){
                    if(dfs(i,j,mat,word,idx+1,vis)) return true;
                }
            }
        }
        
        return false;
    }
};

// Time Complexity : O(N*M * 4^L)
// Space Complexity : (N + M + 4^L)