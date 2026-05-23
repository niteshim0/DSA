// LC 1752.  Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

// Concepts :: Sorting / Enumeration

// Key Idea: Counting descent pairs in a circular array to verify sorted rotation property.

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i+1)%n]) {
                cnt++;
            }
        }

        return cnt <= 1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)