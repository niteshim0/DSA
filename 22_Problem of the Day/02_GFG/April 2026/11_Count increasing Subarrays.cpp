// Count increasing Subarrays
// https://www.geeksforgeeks.org/problems/count-increasing-subarrays5301/1


// Concept :: Sum of N Natural Numbers


// Approach :: Loop through the array , and if its strictly increasing subarray , keep increasing the count but if this rule breaks , add the subarray cnt in ans , and restart the same process.

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        
        int prev = -1;
        
        int cnt = 0;
        int ans = 0;
        
        for(int x : arr){
            if(x > prev){
                cnt++;
            } else {
                ans += (cnt * (cnt - 1)) / 2;  
                cnt = 1;
            }
            prev = x;
        }
        
        if(cnt >= 2){
            ans += (cnt * (cnt - 1)) / 2;  
        }
        
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)