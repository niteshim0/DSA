// Kth Missing Positive Number in a Sorted Array
// https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1



class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        int start = 0 , end = n-1;
        
        
        while(start<=end){
            int mid = start + (end-start)/2;
            int missing = arr[mid] - (mid+1);
            
            if(missing<k){
                start  = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        
        return start + k;
    }
};

// Time Complexity : O(logN)
// Space Complexity : O(1)