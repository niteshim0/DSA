// Longest subarray with Atmost two distinct integers
// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
// Concepts :: Sliding Window + Hashing


// Approach :: Sliding Window Concept
// Just use sliding window logic

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        
        unordered_map<int,int> mp;
        int n = arr.size();
        int i = 0 , j = 0;
        
        int maxi = 0 ,distinct = 0;
        
        while(j<n){
            mp[arr[j]]++;
            if(mp[arr[j]] == 1) distinct++;
            
            while(i<j && distinct>2){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                    distinct--;
                }
                i++;
            }
            
            maxi = max(maxi,j-i+1);
            j++;
        }
        
        return maxi;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)