class Solution {
  public:
      bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int n = matrix.size();
          int m = matrix[0].size();
          int start = 0;
          int end = n*m-1;
          while(start<=end){
              int mid = (end+start)/2;
              int row = mid/m;
              int col = mid%m;
              if(matrix[row][col] == target) return true;
              if(matrix[row][col]>target){
                  end = mid-1;
              }else{
                  start = mid+1;
              }
          }
          return false;
      }
  };

// Flattening the 2d array into 1d array
// Time Complexity : O(log(n*m))
// Space Complexity : O(1)