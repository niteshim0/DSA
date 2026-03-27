// LC 2946. Matrix Similarity After Cyclic Shifts
// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/?envType=daily-question&envId=2026-03-27


// Concepts :: Simulation + Matrix Traversal + Left Shift + Right Shift + Cyclic Shift


// Approach :: Simulation :: Do what ques is saying

class Solution {
public:
    void cyclicRightShift(vector<vector<int>>& mat,int row){

        int m = mat[0].size();

        int temp = mat[row][m-1];

        for(int col = m-1; col >=1; col--){
            
            mat[row][col] = mat[row][col-1];
        }

        mat[row][0] = temp;

    }
    void cyclicLeftShift(vector<vector<int>>& mat,int row){

        int m = mat[0].size();

        int temp = mat[row][0];

        for(int col = 0; col < m - 1; col++){
            
            mat[row][col] = mat[row][col+1];
        }

        mat[row][m-1] = temp;

    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        vector<vector<int>> original = mat;

        int n = mat.size();
    
        for(int i = 0;i<k;i++){
             
            for(int row = 0; row < n ; row++){

                if(row&1){
                    cyclicRightShift(mat,row);
                }else{
                    cyclicLeftShift(mat,row);
                }

            }
        }

        return ( original == mat);
        
    }
};
// Time Complexity : O(M*N)
// Space Complexity : O(M*N)

// Approach II :: Traversal
/*
Determining whether a row cyclically shifted to the right by k positions is identical to the original is equivalent to checking whether it remains the same when shifted to the left by k positions. In essence, both checks verify whether mat[i][j]=mat[i][(j+k)modn], where n is the number of columns.

Therefore, we do not need to distinguish between even and odd rows. While traversing each row, if we encounter any element that does not satisfy this condition, we can immediately return false.
*/


class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int n = mat.size() , m = mat[0].size();
        k = k%m;
             
            for(int row = 0; row < n ; row++){

                for(int col = 0; col < m; col++){

                    if(mat[row][col] != mat[row][(col+k)%m]){

                        return false;
                    }
                }

            }

        return true;
        
    }
};
// TC : O(M*N)
// SC : O(1)