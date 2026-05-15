// LC 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description

// Concepts :: Binary Search on Condition + Pivot


// We have to find the breaking point , where both the half becomes sorted


class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int start = 0 , end = n - 1; 

        while(start < end){
            int mid = start + (end-start)/2;

            if(nums[mid] > nums[end]){
                start = mid + 1;
            }else{
                end = mid ;
            }
        }

        return nums[start];
    }
};

// Time Complexity : O(logN)
// Space Complexity : O(1)


/*
Related pattern family to solve next
LeetCode 33
LeetCode 81
LeetCode 154
LeetCode 35
LeetCode 852
LeetCode 162
LeetCode 875
LeetCode 1011
*/