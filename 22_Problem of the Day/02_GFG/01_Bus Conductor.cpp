// https://www.geeksforgeeks.org/problems/bus-conductor--170647/1

class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        
        int ans = 0;
        int n = chairs.size();
        for(int i = 0;i<n;i++){
            int need = abs(chairs[i] - passengers[i]);
            ans+=need;
        }
        
        return ans;
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)