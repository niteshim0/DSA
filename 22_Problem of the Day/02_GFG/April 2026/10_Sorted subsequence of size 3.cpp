// Sorted subsequence of size 3
// https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1

// class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> smaller(n, -1), greater(n, -1);
        
        // track smaller on left
        int min_idx = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] <= arr[min_idx]){
                min_idx = i;
            } else {
                smaller[i] = min_idx;
            }
        }
        
        // track greater on right
        int max_idx = n-1;
        for(int i = n-2; i >= 0; i--){
            if(arr[i] >= arr[max_idx]){
                max_idx = i;
            } else {
                greater[i] = max_idx;
            }
        }
        
        // find valid triplet
        for(int i = 0; i < n; i++){
            if(smaller[i] != -1 && greater[i] != -1){
                return {arr[smaller[i]], arr[i], arr[greater[i]]};
            }
        }
        
        return {};
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)