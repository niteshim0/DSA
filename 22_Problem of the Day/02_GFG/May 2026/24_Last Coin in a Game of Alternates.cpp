// 23. Last Coin in a Game of Alternates
// https://www.geeksforgeeks.org/problems/last-coin-in-a-game-of-alternates/1

// Concepts :: Two Pointers
// Key Idea :: Move your pointers from two extreme ends , until they collide on same index,that index is the remaining coin index.

class Solution {
  public:
    int coin(vector<int>& arr) {
        
        int n = arr.size();
        int i = 0 , j = n-1;
        
        while(i < j){
            
            if(arr[i]>arr[j]){
                i++;
            }else{
                j--;
            }
        }
        
        return arr[i];
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)