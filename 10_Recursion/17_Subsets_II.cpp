class Solution {
public:
    void generateSubsets(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);
        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates
            if (i > idx && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);       
            generateSubsets(i + 1, nums, ds, ans); 
            ds.pop_back();  
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> ds;
        generateSubsets(0, nums, ds, ans);
        return ans;
    }
};
// Time Complexity : O(2^N *  N)
// Space Complexity :O(2^N * k)