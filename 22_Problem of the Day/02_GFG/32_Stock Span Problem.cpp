// Stock Span Problem
// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// Concept :: NGE + NSE + Stack Concept

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,1);
        
        for(int i = 0;i<n;i++){
            
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i] = i - st.top();
            }else{
                ans[i] = i + 1;
            }
            
            st.push(i);
        }
        
        return ans;
    }
    
};

// Time Complexity : O(N + N) ~ O(N)
// Space Complexity : O(N + N) ~ O(N)