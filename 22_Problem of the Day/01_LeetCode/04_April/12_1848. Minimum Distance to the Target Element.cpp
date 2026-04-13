// LC 1848. Minimum Distance to the Target Element
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int n = nums.size();
        int mini = INT_MAX;

        for(int i = 0 ;i<n;i++){
            if(nums[i] == target){
                int need = abs(i-start);
                mini = min(mini,need);
            }
        }

        return mini;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)