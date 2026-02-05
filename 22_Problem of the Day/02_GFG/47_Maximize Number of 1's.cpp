// Maximize Number of 1's
// https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int i = 0 , j = 0 , n = arr.size();
        int maxi = 0 , cntZero = 0;
        
        while(j<n){
            if(arr[j] == 0) cntZero++;
            while(cntZero>k){
               if(arr[i] == 0) cntZero--;
               i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        
        return maxi;
        
    }
};


// Time Complexity : O(N)
// Space Complexity : O(1)
