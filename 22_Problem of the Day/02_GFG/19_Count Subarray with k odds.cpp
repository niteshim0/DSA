// Count Subarray with k odds
// https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1
// Concept :: Sliding Window(Variable Window Size)

class Solution {
  public:
    int subarrayWithAtMostKOdds(vector<int>& arr,int k){
        int n = arr.size();
        int cntOdd = 0;
        int i = 0 , j = 0;
        int res = 0;
        
        while(j<n){
            if(arr[j]&1) cntOdd++;
            while(cntOdd>k){
                if(arr[i]&1) cntOdd--;
                i++;
            }
            res+=(j-i+1);
            j++;
        }
        
        return res;
    }
    int countSubarrays(vector<int>& arr, int k) {
       return subarrayWithAtMostKOdds(arr,k) - subarrayWithAtMostKOdds(arr,k-1);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
