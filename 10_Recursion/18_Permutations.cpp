// Approach I
class Solution {
public:
    void generatePermute(vector<int>& ds,vector<int>& nums,vector<vector<int>>& ans,vector<int>& freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(freq[i] == 0){
                ds.push_back(nums[i]);
                freq[i]  = 1;
                generatePermute(ds,nums,ans,freq);
                ds.pop_back();
                freq[i]  = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        vector<int> freq(n,0);
        generatePermute(ds,nums,ans,freq);
        return ans;
    }
};
// Time Complexity : O(N! * N)
// Space Complexity : O(N) + O(N)

// Approach - II
class Solution {
public:
    void swap(vector<int>& nums,int first, int second){
        int temp  = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }
    void generatePermute(int idx,vector<int>&nums,vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx;i<nums.size();i++){
            swap(nums,i,idx);
            generatePermute(idx+1,nums,ans);
            swap(nums,i,idx);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generatePermute(0,nums,ans);
        return ans;
    }
};// Time Complexity : O(N!*N)