// LC 3653. XOR After Range Multiplication Queries I
// https://leetcode.com/problems/xor-after-range-multiplication-queries-i



// Approach I 
// Just do what ques said , it is easy to follow go brute 
// Traverse every query and apply changes in original nums of that query.
// At last , take xor of every element of now modified array and return the xor as ans


class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for(vector<int>& query : queries){

            for(int idx = query[0] ; idx<=query[1];idx+=query[2]){

                nums[idx] = (nums[idx] * 1ll * query[3]) % MOD;
            }
        }

        int xr = 0;
        for(int& x : nums){

            xr^=x;
        }

        return xr;
    }
};

// Time Complexity : O(N * Q)
// Space Complexity : O(1)


// Drawbacks :: If constraints will be high it is bound to fail , use segment tree or any such things.