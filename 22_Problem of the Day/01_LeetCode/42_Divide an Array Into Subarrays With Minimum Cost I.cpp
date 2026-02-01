// LC 3010. Divide an Array Into Subarrays With Minimum Cost I
// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description
// Concept :: How to find the first and second extremes(min,max) in a single loop

// Approach ::
// i) Since we need to have array contiguous , we always need to take the first element , now the question remains , where we part two lines.
// ii) Most viable one be , right before the most minimal one.
// iii) in b/w these two , find the second minimal element , it will make always the right choice.

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