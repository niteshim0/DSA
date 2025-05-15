// https://www.geeksforgeeks.org/problems/subset-sums2234/0
class Solution {
  public:
    void subsetSums(int idx,int sum,vector<int>& arr,vector<int>& ans){
        if(idx == arr.size()){
            ans.push_back(sum);
            return;
        }
        subsetSums(idx+1,sum+arr[idx],arr,ans);
        subsetSums(idx+1,sum,arr,ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        subsetSums(0,0,arr,ans);
        return ans;
    }
};
// Time Complexity : O(2^N)
// Space Complexity : O(2^N)