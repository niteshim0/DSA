// 3880. Minimum Absolute Difference Between Two Values
// https://leetcode.com/problems/minimum-absolute-difference-between-two-values/description/

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {

        vector<int> one;
        vector<int> two;
        int n = nums.size();
        int mini = INT_MAX;

        for(int i = 0;i<n;i++){
            if(nums[i] == 1) one.push_back(i);
            if(nums[i] == 2) two.push_back(i);
        }

        if(one.empty() || two.empty()) return -1;

        for(int j = 0 ; j<one.size();j++){

            for(int k = 0;k<two.size();k++){

                mini = min(mini,abs(one[j]-two[k]));
            }
        }

        return mini;
    }
};