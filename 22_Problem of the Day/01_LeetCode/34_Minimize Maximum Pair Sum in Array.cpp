// 1877. Minimize Maximum Pair Sum in Array
// leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/
// Concept :: Sorting + Two Pointers

// Approach :: Sort the array , take two pointers one at start , other at end , take their sum , find maximum among them.

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0 , j = n-1;
        int maxi = INT_MIN;
        while(i<j){
            int sum = nums[i] + nums[j];
            maxi = max(maxi,sum);
            i++;
            j--;
        }
        return maxi;
    }
};
// Time Complexity : O(NlogN)
// Space Complexity : O(logN) // for inbuilt sort function
// In C++ std::sort() function provided by STL is a hybrid of Quick Sort, Heap Sort, and Insertion Sort and has a worst-case space complexity of O(logN).