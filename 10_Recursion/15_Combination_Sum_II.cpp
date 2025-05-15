class Solution {
public:
    void findCombinations(int idx, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // If current candidate is greater than target, no need to proceed further
            if (candidates[i] > target)
                break;

            ds.push_back(candidates[i]);
            findCombinations(i + 1, candidates, target - candidates[i], ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ds, ans);
        return ans;
    }
};
// Time Complexity : O(2^n *k)
// Space Complexity : O(k*x)