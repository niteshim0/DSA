// Find the closest pair from two arrays
// https://www.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1

// Concepts :: Two Pointers + Absolute Sum Differnce 


// Approach :: There are two sorted arrays , we will move one from back and other from start , and we will move pointer depending upon which combination is giving us something towards right answer.
class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        
        int n = arr1.size()  , m = arr2.size();
        
        int i = 0 , j = m-1;
        
        int minDiff = INT_MAX;
        
        int a = -1 , b = -1;
        
        while(i<n && j>=0){
            
            int sum = arr1[i] + arr2[j];
            int diff = abs(x-sum);
            
            if(diff<minDiff){
                a = arr1[i];
                b = arr2[j];
                minDiff = diff;
            }
            
            sum < x ? i++ : j--;
        }
        
        return {a,b};
        
    }
};

// Time Complexity : O(M+N)
// Space Complexity : O(1)