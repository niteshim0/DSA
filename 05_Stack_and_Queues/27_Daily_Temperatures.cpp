class Solution {
  public:
      vector<int> dailyTemperatures(vector<int>& arr) {
          int n = arr.size();
          stack<int> st;
          vector<int> nge(n,0);
          for(int i = n-1;i>=0;i--){
              while(!st.empty() && arr[st.top()]<=arr[i]){
                  st.pop();
              }
              if(!st.empty()){
                  nge[i] = st.top()-i;
              }
              st.push(i);
          }
          return nge;
      }
  };
  // Time Complexity : O(N + N)
  // Space Complexity : O(N)