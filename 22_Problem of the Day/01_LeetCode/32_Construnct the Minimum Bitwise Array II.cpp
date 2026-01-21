// LC 3315.Construnct the Minimum Bitwise Array II
// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/
// Concept :: Bit Manipulation
// Approach
/*
// what does ans | ans + 1  results in => 
ans + 1 =>it makes the first lsb to msb 0 to 1 and all other trailing bits to 0.
so when ans | ans + 1 happens => results in before 0 (lst to msb) -> all 1 , after 0 remains unchanged.
so for going towards minimum we will try to get rid of consecutive 1s from lsb to msb side , if 1 encountered, update ans and move on if not,
you can't do better than that , stop.
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int x  : nums){
            int res = -1;
            int d = 1;
            while((x&d)!=0){
                res = x-d;
                d<<=1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
// Time Complexity : O(NLogM)
// Space Complexity : O(1) // Auxiliary : O(N)