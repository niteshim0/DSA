class Solution {
  public:
      vector<int> nextGreaterElements(vector<int>& nums) {
          int n = nums.size();
          vector<int> nge(n,-1);
          for(int i = 0;i<n;i++){
              for(int j = i+1;j<=(i+n-1);j++){
                  int idx = (j)%n;
                  if(nums[idx]>nums[i]){
                      nge[i] = nums[idx];
                      break;
                  }
              }
          }
          return nge;
      }
  };
// Time Complexity : O(N*N)
// Space Complexity : O(N)

class Solution {
  public:
      vector<int> nextGreaterElements(vector<int>& nums) {
          int n = nums.size();
          stack<int> st;
          vector<int> nge(n,-1);
          for(int i = 2*n-1;i>=0;i--){
             while(!st.empty() && st.top()<=nums[i%n]){
              st.pop();
             }
             if(i<n){
              nge[i] = st.empty() ? -1 :  st.top();
             }
             st.push(nums[i%n]);
          }
          return nge;
      }
  };
// Time Complexity : o(2N + 2N)
// Space Complexity : O(N)