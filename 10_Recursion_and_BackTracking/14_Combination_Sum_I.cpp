class Solution {
public:
    void findCombinations(int idx,vector<int>&candidates,int target,vector<int>& ds,vector<vector<int>>& ans){
        if(target<0) return;
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        // pick 
        if(candidates[idx]<=target){
        ds.push_back(candidates[idx]);
        findCombinations(idx,candidates,target-candidates[idx],ds,ans);
        ds.pop_back();
        }
        findCombinations(idx+1,candidates,target,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0,candidates,target,ds,ans);
        return ans;
    }
};
// Time Complexity : O(2^t*k)
// Space Complexity : O(2^t*x)