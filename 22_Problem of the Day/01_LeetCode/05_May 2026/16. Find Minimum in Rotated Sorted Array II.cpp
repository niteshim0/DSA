// LC 154. Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii


// Concepts ::  Binary Search + Duplicates Handling

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int start = 0 , end = n - 1;

        while(start < end){

            int mid = start + (end-start)/2;

            if(nums[mid] > nums[end]){
                start = mid + 1;
            }else if(nums[mid] < nums[end]){
                end = mid;
            }else{
                end--;
            }
        }

        return nums[start];
    }
};

// Time Complexity : Avg Case : O(logN)
// Space Complexity : O(1)