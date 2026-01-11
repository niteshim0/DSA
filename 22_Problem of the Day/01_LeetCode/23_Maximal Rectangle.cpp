// https://leetcode.com/problems/maximal-rectangle/description/
// LC 85. Maximal Rectangle

class Solution {
  public:
      int largestHistogram(vector<int>& heights){
          stack<int> st;
          int max_area = 0;
          int n = heights.size();
          for(int i = 0; i <= n; i++){
              while(!st.empty() && (i == n || heights[st.top()] > heights[i])){
                  int height = heights[st.top()];
                  st.pop();
                  int width = st.empty() ? i : i - st.top() - 1;
                  int area = height * width;
                  max_area = max(max_area, area);
              }
              if(i < n){
                  st.push(i);
              }
          }
          return max_area;
      }
  
      int maximalRectangle(vector<vector<char>>& matrix) {
          if(matrix.empty()) return 0;
          
          int n = matrix.size();
          int m = matrix[0].size();
          vector<int> heights(m, 0);  
          int max_area = 0;
  
          for(int row = 0; row < n; row++){
              for(int col = 0; col < m; col++){
                  if(matrix[row][col] == '1'){
                      heights[col] += 1;
                  } else {
                      heights[col] = 0;
                  }
              }
              max_area = max(max_area, largestHistogram(heights));
          }
          return max_area;
      }
  };
  // Time Complexity : O(N*M + N*2M)
  // Space Complexity : O(M + M)
  