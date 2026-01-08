class Solution {
public:
    int subarraysWithAtMostKDistinct(vector<int>& nums,int k){
        int n = nums.size() , res = 0;
        int i = 0,j = 0;
        unordered_map<int,int> mp;
        int cntDistinct = 0;

        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]] == 1) cntDistinct++;

            while(cntDistinct>k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                    cntDistinct--;
                }
                i++;
            }
            res+=(j-i+1);
            j++;
        }

        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums,k) - subarraysWithAtMostKDistinct(nums,k-1);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)