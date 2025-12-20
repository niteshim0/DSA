// Search insert position of K in a sorted array
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int start = 0 , end = n-1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid] == k) return mid;
            else if(arr[mid]>k){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return start;
    }
};

// Time Complexity : O(logN)
// Space Complexity : O(1)