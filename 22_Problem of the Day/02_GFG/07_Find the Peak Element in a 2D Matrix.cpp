// Find the Peak Element in a 2D Matrix
// https://www.geeksforgeeks.org/problems/find-the-peak-element-in-a-2d-matrix/1


// Approach I :: Finding the Global Peak and treat that as ans

class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size() , m = mat[0].size();
        int maxi = INT_MIN;
        int row = -1 , col = -1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]>maxi){
                    maxi = mat[i][j];
                    row = i , col = j;
                }
            }
        }
        return {row,col};
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(1)