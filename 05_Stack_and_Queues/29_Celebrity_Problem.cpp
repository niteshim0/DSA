lass Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        vector<int> knowMe(n,0);
        vector<int> iKnow(n,0);
        for(int row = 0;row<n;row++){
            for(int col = 0;col<n;col++){
                if(mat[row][col]==1){
                    iKnow[row]+=1;
                    knowMe[col]+=1;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(knowMe[i]==n && iKnow[i]==1){
                return i;
            }
        }
        return -1;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(2N)

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n - 1;

        // Find the potential celebrity
        while(top < down){
            if(mat[top][down] == 1){
                top++;
            } else {
                down--;
            }
        }

        // Verify the potential celebrity
        for(int i = 0; i < n; i++){
            if(i != top){
                if(mat[i][top] == 0 || mat[top][i] == 1){
                    return -1;
                }
            }
        }

        return top;
    }
};
// Time Complexity : O(N + N)
// Space Complexity :  O(1)