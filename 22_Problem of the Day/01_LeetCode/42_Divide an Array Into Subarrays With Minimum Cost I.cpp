// LC 3010. Divide an Array Into Subarrays With Minimum Cost I
// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int firstSmall = 51 , secondSmall = 51;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i]<firstSmall){
                secondSmall = firstSmall;
                firstSmall = nums[i];
            }else if(nums[i]<secondSmall){
                secondSmall = nums[i];
            }
        }

        return nums[0] + firstSmall  + secondSmall;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)