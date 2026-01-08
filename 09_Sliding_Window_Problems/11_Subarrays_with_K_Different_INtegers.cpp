class Solution {
public:
    long long subarrAtMostKDistinct(vector<int> &nums,int k){
        int n = nums.size();
        map<int,int> mp;
        int i = 0;
        int j = 0;
        int cnt = 0;
        int res = 0;
        while(j<n){
           mp[nums[j]]++;
           if(mp[nums[j]]==1) cnt++;
           if(cnt>k){
               while(cnt>k){
                   mp[nums[i]]--;
                   if(mp[nums[i]]==0){
                       cnt--;
                   }
                   i++;
               }
           }
           res+=(j-i+1);
           j++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrAtMostKDistinct(nums,k)-subarrAtMostKDistinct(nums,k-1);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)