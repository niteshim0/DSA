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

// Approach II :: Binary Search on Columns
class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size() , m = mat[0].size();
        int mini = -1e9;
        int start = 0 , end = m-1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            int maxRow = 0;
            
            for(int i = 0;i<n;i++){
                if(mat[i][mid]>mat[maxRow][mid]){
                    maxRow = i;
                }
            }
            
            int left = (mid>0) ? mat[maxRow][mid-1] : mini;
            int right = (mid+1<m) ? mat[maxRow][mid+1] : mini;
            
            if(mat[maxRow][mid]>=left && mat[maxRow][mid]>=right){
                return {maxRow,mid};
            }else if(mat[maxRow][mid] < right){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        
        return {};
    }
};


// Time Complexity : O(NlogM)
// Space Complexity : O(1)