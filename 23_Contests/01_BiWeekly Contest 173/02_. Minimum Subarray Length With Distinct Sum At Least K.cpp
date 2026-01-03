// https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k/description/
//3795. Minimum Subarray Length With Distinct Sum At Least K

// My Solution
// 2 strikes : I didn't read problem carefully , so it is asking something else I was doing something similar but different
// AC
// Concept :: Sliding Window with Variable Window Size

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 , j = 0;
        long long sum = 0;
        unordered_map<int,int> mp; // inserting and removing takes O(1) time on avg, on worst case O(n) // very rare case
        int ans = 1e8;

        while(j<n){
            if(mp.find(nums[j]) == mp.end()){
                sum+=nums[j];
                mp[nums[j]] = 1;
            }else{
                mp[nums[j]]++;
            }
            while(sum>=k){
                ans = min(ans,j-i+1);
                if(mp[nums[i]]==1){
                    mp.erase(nums[i]);
                    sum-=nums[i];
                }else{
                    mp[nums[i]]--;
                }
                i++;
            }
            j++;
        }

        return ans == 1e8 ? -1 : ans;
        
    }
};

// Time Complexity : O(N)
// Space Complexity :O(N)


// Optimized Solution during upsolving
// Same