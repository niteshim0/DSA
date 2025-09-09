class Solution {
public:
    void generatePermute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, vector<int>& freq) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1] && freq[i-1] == 0) continue;
            if(freq[i] == 0) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                generatePermute(ds, nums, ans, freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        generatePermute(ds, nums, ans, freq);
        return ans;
    }
};
// Time Complexity  :  O(N!*N)
// Space Complexity : O(N)