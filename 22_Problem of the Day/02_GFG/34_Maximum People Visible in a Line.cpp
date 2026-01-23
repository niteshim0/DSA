// Maximum People Visible in a Line
// https://www.geeksforgeeks.org/problems/maximum-people-visible-in-a-line/1
// Concept :: Next Greater ELement + Prev Greater ELement + Working of Stakc

// Approach :: for every element , find the next greater idx and prev greater idx , and in the process , find how many a particular element can see

class Solution {
  public:
    vector<int> leftSpan(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> span(n, 1);

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(!st.empty()){
                span[i] = i - st.top();
            }else{
                span[i] = i + 1;
            }
            st.push(i);
        }
        return span;
    }

    vector<int> rightSpan(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> span(n, 1);

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(!st.empty()){
                span[i] = st.top() - i;
            }else{
                span[i] = n - i ;
            }
            st.push(i);
        }
        return span;
    }

    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        int maxi = 0;

        vector<int> left  = leftSpan(arr);
        vector<int> right = rightSpan(arr);

        for(int i = 0; i < n; i++){
            maxi = max(maxi,(left[i] + right[i]-1));
        }
        return maxi;
    }
};

// Time Complexity : O(N)
// Space Complexity: O(N)