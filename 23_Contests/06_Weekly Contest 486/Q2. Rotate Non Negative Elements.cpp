// Q2. Rotate Non Negative Elements
// https://leetcode.com/contest/weekly-contest-486/problems/rotate-non-negative-elements/description/

// Concept :: Circular Shifting of Array + Array Reversal

// Approach :: Take an array , push all the non-negative elements to it.
// rotate it in left by k positions in circular manner
// now put these elements back in the original array as according to the position of non-negative elements

// Solved During Contest :: Yes
// One strike(because I didn't do k%m -> gives runtime error if k>m)


class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> positive;
        for(int &num : nums){
            if(num>=0) positive.push_back(num);
        }
        int m = positive.size();
        if(m == 0) return nums;
        k = k % m ;
        reverse(positive.begin(),positive.begin() + k);
        reverse(positive.begin()+k,positive.end());
        reverse(positive.begin(),positive.end());

        int idx = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]>=0){
                nums[i] = positive[idx++];
            }
        }
        return nums;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)