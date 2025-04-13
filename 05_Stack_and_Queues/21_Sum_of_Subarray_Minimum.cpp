class Solution {
  public:
      int sumSubarrayMins(vector<int>& arr) {
          int n = arr.size();
          int sum = 0;
          int MOD = 1e9 + 7;
          for(int i = 0;i<n;i++){
              int mini = arr[i];
              for(int j = i;j<n;j++){
                  mini = min(mini,arr[j]);
                  sum = (sum+mini)%MOD;
              }
          }
          return sum;
      }
  };
  // Time Complexity: O(N*N)
  // Space Complexity : O(1)

  // Optimal Approach : We will count the contribution of each individual element in the answer

  class Solution {
    public:
        vector<int> nextSmallerElement(vector<int> &arr){
            int n = arr.size();
            vector<int> nse(n, n);
            stack<int> st;
            for(int i = n - 1; i >= 0; i--){
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    nse[i] = st.top();
                }
                st.push(i);
            }
            return nse;
        }
    
        vector<int> prevSmallerElement(vector<int>& arr){
            int n = arr.size();
            vector<int> pse(n, -1);
            stack<int> st;
            for(int i = 0; i < n; i++){
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    pse[i] = st.top();
                }
                st.push(i);
            }
            return pse;
        }
    
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            vector<int> pse = prevSmallerElement(arr);
            vector<int> nse = nextSmallerElement(arr);
            int total = 0;
            int MOD = 1e9 + 7;
    
            for(int i = 0; i < n; i++){
                int left = i - pse[i];
                int right = nse[i] - i;
                total = (total + 1LL * left * right * arr[i] % MOD) % MOD;
            }
    
            return total;
        }
    };

// Time Complexity : O(2N + 2N + N)
// Space Complexity : O(N + N)
    