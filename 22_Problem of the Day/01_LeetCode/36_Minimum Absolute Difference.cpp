// LC 1200 . Mininimum Absolute Difference
// https://leetcode.com/problems/minimum-absolute-difference/
// Happy Republic Day
// Concept :: Sorting


// Approach :: Sort the array , find the difference b/w two consecutive elements which turn out to be minimum one.
// traverse the array again , if any two consecutive element difference is equal to minium difference array , add them to ans

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int minDiff = INT_MAX;
        for(int i = 1;i<n;i++){
            int diff = abs(arr[i] - arr[i-1]);
            minDiff = min(minDiff,diff);
        }
        vector<vector<int>> ans;
        for(int i = 1;i<n;i++){
            int diff = abs(arr[i] - arr[i-1]);
            if(diff == minDiff){
                vector<int> need = {arr[i-1],arr[i]};
                ans.push_back(need);
            }
        }
        return ans;
    }
};

// Time Complexity : O(NlogN + N + N) ~ O(NlogN)
// Space Complexity : O(logN) // for sorting