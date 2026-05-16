// Not a Subset Sum
// https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1


// Concepts :: Greedy + Sorting

class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        
        sort(arr.begin(),arr.end());
        
        int reachable = 1;
        
        for(int& x : arr){
            
            if(reachable >= x){
                reachable+=x;
            }else{
                break;
            }
        }
        
        return reachable;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)