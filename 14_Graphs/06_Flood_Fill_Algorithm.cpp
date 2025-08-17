// BFS Approach
// extra vis is not needed since once image[r][c] gets recolored ,it can't be visited as according to the ques condition
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;

        int n = image.size(), m = image[0].size();
        queue<pair<int,int>> qp;
        qp.push({sr,sc});
        image[sr][sc] = color;

        while(!qp.empty()){
            auto [row, col] = qp.front(); qp.pop();

            int drow[4] = {-1, 1, 0, 0};
            int dcol[4] = {0, 0, -1, 1};

            for(int i=0; i<4; i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == originalColor){
                    image[nr][nc] = color;
                    qp.push({nr,nc});
                }
            }
        }
        return image;
    }
};
// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

// DFS Approach
class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,int color,int originalColor){
        image[row][col] = color;
        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};
        int n = image.size() , m = image[0].size();
        for(int i=0; i<4; i++){
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == originalColor){
                dfs(nr,nc,image,color,originalColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;
        dfs(sr,sc,image,color,originalColor);
        
        return image;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

// DFS Iterative Approach
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;

        int n = image.size(), m = image[0].size();
        stack<pair<int,int>> st;
        st.push({sr, sc});

        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!st.empty()) {
            auto [row, col] = st.top();
            st.pop();
            image[row][col] = color;

            for(auto [dr, dc] : dirs) {
                int nr = row + dr, nc = col + dc;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == originalColor) {
                    st.push({nr, nc});
                }
            }
        }
        return image;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)
