// LC 1878. Get Biggest Three Rhombus Sums in a Grid
// Concepts :: Matrix Traversals

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<int, greater<int>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                st.insert(grid[i][j]); 

                for(int k = 1; ; k++) {

                    if(i + 2*k >= n || j-k < 0 || j+k >= m) break;

                    int sum = 0;
                    int x = i, y = j;

                    // top -> right
                    for(int t=0;t<k;t++)
                        sum += grid[x+t][y+t];

                    // right -> bottom
                    for(int t=0;t<k;t++)
                        sum += grid[x+k+t][y+k-t];

                    // bottom -> left
                    for(int t=0;t<k;t++)
                        sum += grid[x+2*k-t][y-t];

                    // left -> top
                    for(int t=0;t<k;t++)
                        sum += grid[x+k-t][y-k+t];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto x: st){
            ans.push_back(x);
            if(ans.size()==3) break;
        }

        return ans;
    }
};