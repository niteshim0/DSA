// Move All Zeroes to End
// https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

// Concept :: Swapping

// Approach :: Traverse the array from left to right , and if nonzero element found , swap it with an iterator in start , which increases.

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size() , j = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)