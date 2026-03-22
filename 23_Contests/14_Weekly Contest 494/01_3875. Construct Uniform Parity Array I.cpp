// 3875. Construct Uniform Parity Array I
// https://leetcode.com/problems/construct-uniform-parity-array-i/description/

// Concepts :: Simple thinking

// Approach :: // one can always reach to the similar parity if n>=1
// two condition to reach there left elment as it is
// or subtract from some othe element such that i!=j
// if all odd or all even -> condition valid
// if odd , even mix -> subtract odd , odd to get to even , left even as it is , i.e. always we can reach even parity no matter what.
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        return true;
        
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)

