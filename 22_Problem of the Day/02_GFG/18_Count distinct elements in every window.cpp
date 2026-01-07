// Count distinct elements in every window
// https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
// Concept :: Sliding Window(Fixed Window Size) + Unordered Map Concepts
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int n = arr.size();
        int i = 0 , j = 0;
        vector<int> ans;
        
        while(j<n){
            
            mp[arr[j]]++;
            
            if(j-i+1 == k){
                ans.push_back(mp.size());
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(k)