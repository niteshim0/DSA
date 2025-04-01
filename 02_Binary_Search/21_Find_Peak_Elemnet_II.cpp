class Solution {
  public:
      int findMaxRow(vector<vector<int>>& mat,int mid){
          int n = mat.size();
          int maxi = -1;
          int idx = -1;
          for(int row = 0;row<n;row++){
             if(mat[row][mid]>maxi){
                 maxi = mat[row][mid];
                 idx = row;
             }
          }
          return idx;
      }
      vector<int> findPeakGrid(vector<vector<int>>& mat) {
          int n = mat.size();
          int m = mat[0].size();
          int start = 0;
          int end = m-1;
          while(start<=end){
              int mid = start + (end-start)/2;
              int maxRow = findMaxRow(mat,mid);
              int left = (mid-1)>=0 ? mat[maxRow][mid-1] : -1;
              int right = (mid+1)<m ? mat[maxRow][mid+1] : -1;
              if(mat[maxRow][mid]>left && mat[maxRow][mid]>right){
                  return {maxRow,mid};
              }else if(mat[maxRow][mid]<left){
                  end = mid-1;
              }else{
                  start = mid+1;
              }
          }
          return {-1,-1};
      }
  };
// Time Complexity : O(nlogm)
// Space Complexity : O(1)