// Pythagorean Triplet
// https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

// Concepts :: 3Sum Problem + Two Pointer Technique + Sorting

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());

        for(int i = n-1; i >= 2; i--) {
            
            if(i == n-1 || (i<(n-1) && nums[i]!=nums[i-1])){
                int left = 0, right = i-1;

                while(left < right) {
                    int sum = nums[left] + nums[right];
                    if(sum == nums[i]) return true;
                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(left<right && nums[right] == nums[right-1]) right--;
                    if(sum < nums[i]) left++;
                    else right--;
            }
            }
        }
        return false;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)