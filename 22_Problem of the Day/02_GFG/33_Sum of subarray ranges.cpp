// Sum of subarray ranges
// https://www.geeksforgeeks.org/problems/sum-of-subarray-ranges/1
// Concept :: NGE  + NSE + PGE + PSE


// Approach :: find out for each particular element can be part of how many subarray as maximum ones , same how may for it can be minimum.
// Brute Force Approach
class Solution {
  public:
      long long subArrayRanges(vector<int>& nums) {
          int n = nums.size();
          long  long total = 0;
          for(int i = 0;i<n;i++){
              int mini = nums[i];
              int maxi = nums[i];
              for(int j = i;j<n;j++){
                  mini = min(mini,nums[j]);
                  maxi = max(maxi,nums[j]);
                  total+=(maxi-mini);
              }
          }
          return total;
      }
  };
// Time Complexity : O(N*N)
// Space Complexity : O(1)


class Solution {
  public:
      vector<int> nextGreaterElement(vector<int> &arr){
          int n = arr.size();
          vector<int> nge(n, n);
          stack<int> st;
          for(int i = n - 1; i >= 0; i--){
              while(!st.empty() && arr[st.top()] <= arr[i]){
                  st.pop();
              }
              if(!st.empty()){
                  nge[i] = st.top();
              }
              st.push(i);
          }
          return nge;
      }
  
      vector<int> prevGreaterElement(vector<int>& arr){
          int n = arr.size();
          vector<int> pge(n, -1);
          stack<int> st;
          for(int i = 0; i < n; i++){
              while(!st.empty() && arr[st.top()] < arr[i]){
                  st.pop();
              }
              if(!st.empty()){
                  pge[i] = st.top();
              }
              st.push(i);
          }
          return pge;
      }
  
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
  
      long long sumSubarrayMaxs(vector<int>& arr) {
          int n = arr.size();
          vector<int> pge = prevGreaterElement(arr);
          vector<int> nge = nextGreaterElement(arr);
          long long total = 0;
  
          for(int i = 0; i < n; i++){
              int left = i - pge[i];
              int right = nge[i] - i;
              total += 1LL * left * right * arr[i];
          }
  
          return total;
      }
  
      long long sumSubarrayMins(vector<int>& arr) {
          int n = arr.size();
          vector<int> pse = prevSmallerElement(arr);
          vector<int> nse = nextSmallerElement(arr);
          long long total = 0;
  
          for(int i = 0; i < n; i++){
              int left = i - pse[i];
              int right = nse[i] - i;
              total += 1LL * left * right * arr[i];
          }
  
          return total;
      }
  
      long long subArrayRanges(vector<int>& nums) {
          return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
      }
  };
// Time Complexity : O(2N + 2N + N + 2N + 2N)~O(N)
// Space Complexity : O(N+N)  ~ O(N)