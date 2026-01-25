// Q1. Minimum Prefix Removal to Make Array Strictly Increasing
// https://leetcode.com/contest/weekly-contest-486/problems/minimum-prefix-removal-to-make-array-strictly-increasing/description/

// Concept :: What does strictly increasing means

// Approach :: Traverse array from back , if the condition of strictly increasing array gets violated , come out of the loop
// the idx which violates the condition , remove the array from [0,violatingIdx] = violatingIdx + 1

// Solved During Contest :: Yes

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int reqIdx = -1;
        int n = nums.size();
        for(int i = n-1;i>0;i--){
            if(nums[i]<=nums[i-1]){
                reqIdx = i-1;
                break;
            }
        }
        return reqIdx + 1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)