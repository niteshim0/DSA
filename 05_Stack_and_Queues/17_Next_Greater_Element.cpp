// Brute Force Approach
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n,-1);
        for(int i = 0; i<n;i++){
            for(int j = i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    nge[i] = arr[j];
                    break;
                }
            }
        }
        return nge;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N)

// Optimal Approach;
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n,-1);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            st.empty() ? nge[i] = -1 : nge[i] = st.top();
            st.push(arr[i]);
        }
        return nge;
    }
};
// Time Complexity : O(N + N)
// Space Complexity : O(N + N)