class Solution {
  public:
      vector<int> prevSmallerElement(vector<int>& arr){
          int n = arr.size();
          vector<int> pse(n,-1);
          stack<int> st;
          for(int i = 0;i<n;i++){
              while(!st.empty() && arr[st.top()]>=arr[i]){
                  st.pop();
              }
              if(!st.empty()){
                  pse[i] = st.top();
              }
              st.push(i);
          }
          return pse;
      }
      vector<int> nextSmallerElement(vector<int>& arr){
          int n = arr.size();
          vector<int> nse(n,n);
          stack<int> st;
          for(int i = n-1;i>=0;i--){
              while(!st.empty() && arr[st.top()]>=arr[i]){
                  st.pop();
              }
              if(!st.empty()){
                  nse[i] = st.top();
              }
              st.push(i);
          }
          return nse;
      }
      int largestRectangleArea(vector<int>& heights) {
          vector<int> pse = prevSmallerElement(heights);
          vector<int> nge = nextSmallerElement(heights);
          int n  = heights.size();
          int maxi = 0;
          for(int i = 0;i<n;i++){
              int width = nge[i] - pse[i] - 1;
              int area  = width*heights[i];
              maxi = max(maxi,area);
          }
          return maxi;
      }
  };
  // Time Complexity : O(2N + 2N + N)
  // Space Complexity : O(N + N)

  class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int> st;
            int n = heights.size();
            int maxi = 0;
            for(int i = 0;i<n;i++){
                while(!st.empty() && heights[st.top()]>heights[i]){
                    int element = st.top();st.pop();
                    int nse = i;
                    int pse = st.empty() ? -1 : st.top();
                    int width = nse-pse-1;
                    int area = heights[element]*width;
                    maxi = max(maxi,area);
                }
                st.push(i);
            }
            while(!st.empty()){
                int element = st.top();st.pop();
                int nse = n;
                int pse = st.empty() ? -1 : st.top();
                int width = nse-pse-1;
                int area = heights[element]*width;
                maxi = max(maxi,area);
            }
            return maxi;
        }
    };
    // Time Complexity : O(N+N)
    // Space Complexity : O(N)