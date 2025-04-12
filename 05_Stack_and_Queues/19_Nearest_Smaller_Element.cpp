// Brute Force Approach
class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        int n = arr.size();
        vector<int> nse(n,-1);
        for(int i = 1; i<n;i++){
            for(int j = i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                    nse[i] = arr[j];
                    break;
                }
            }
        }
        return nse;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N)

// Optimal Approach
class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        int n = arr.size();
        vector<int> nse(n,-1);
        stack<int> st;
        for(int i = 0; i<n;i++){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(arr[i]);
        }
        return nse;
    }
};
// Time Complexity : O(N+N)
// Space Complexity : O(N)