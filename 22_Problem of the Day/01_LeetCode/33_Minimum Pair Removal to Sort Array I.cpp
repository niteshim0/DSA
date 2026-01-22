// 3507. Minimum Pair Removal to Sort Array I
// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/
// Concept :: Sometimes Brute Force is Enough


class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(nums.size()>1){
            bool isAscending = true;
            int minSum = std::numeric_limits<int>::max();
            int targetIdx = -1;

            for(int i = 0;i<nums.size()-1;i++){
                int sum = nums[i] + nums[i+1];

                if(nums[i]>nums[i+1]){
                    isAscending = false;
                }
                if(sum<minSum){
                    minSum = sum;
                    targetIdx = i;
                }
            }
            if(isAscending) break;
            cnt++;
            nums[targetIdx] = minSum;
            nums.erase(nums.begin() + targetIdx+1);
        }

        return cnt;
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(1)