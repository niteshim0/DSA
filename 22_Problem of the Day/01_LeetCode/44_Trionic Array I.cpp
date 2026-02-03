// 3637. Trionic Array I
// https://leetcode.com/problems/trionic-array-i/description
// Concept :: Monotonic Array

// Approach :: We will check for monotonicity , in this pattern increasing -> decreasing -> increasing.

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size() , i = 1;
        while(i<n && nums[i-1]<nums[i]){
            i++;
        }
        int p = i-1;
        while(i<n && nums[i-1]>nums[i]){
            i++;
        }
        int q = i - 1;
        while(i<n && nums[i-1]<nums[i]){
            i++;
        }
        int flag = i-1;

        return (p!=0 && q!=p && flag == n-1 && flag!=q);
    }
};

// Time Complexity : O(N)
// Space Complexity:  O(1)