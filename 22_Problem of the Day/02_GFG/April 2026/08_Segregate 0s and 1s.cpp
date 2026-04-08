// Segregate 0s and 1s
// https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

// Approach ::
/*
// Use two pointers -> move all the zeros to the left side, ultimately 1s will move to the left side.
*/

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        
        int zeroIdx = 0 , idx = 0;
        int n = arr.size();
        
        while(idx < n){
            if(arr[idx] == 0){
                swap(arr[idx],arr[zeroIdx]);
                zeroIdx++;
            }
            idx++;
        }
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)