// LC 3314. Construnct the Minimum Bitwise Array I
// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/
// Concept :: Bit Manipulation  + Decimal to Binary Conversion

// Approach I : Brute Force
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            for (int j = 1; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    nums[i] = j;
                    break;
                }
            }
            if (nums[i] == tmp) {
                nums[i] = -1;
            }
        }
        return nums;
    }
};
// Time Complexity : O(M*N)
// Space Complexity : O(1)



// Approach II : Bitwise operation
/*
Intuition :: 
For each x in nums, we want to find the smallest ans such that
ans∣(ans+1)=x.
Observing ans+1, it is evident that this operation flips the first 0 bit from the least significant bit toward the most significant bit to 1, and sets all lower bits that were previously 1 to 0. As a result, ans∣(ans+1) effectively changes the first 0 bit in ans, scanning from the least significant bit upward, to 1.
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) {
            int res = -1;
            int d = 1;
            while ((x & d) != 0) {
                res = x - d;
                d <<= 1;
            }
            x = res;
        }
        return nums;
    }
};

// Time complexity: O(nlogm).
// Space complexity: O(1).