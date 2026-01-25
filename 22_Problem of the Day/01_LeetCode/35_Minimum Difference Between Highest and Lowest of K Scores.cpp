//LC 1984. Minimum Difference Between Highest and Lowest of K Scores
// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Concept :: Sorting  + Sliding Window

// Approach :: For any k number such that their sum b/w (highes-lowest) is minimized , they must be in sorted order.

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0;i+k-1<n;i++){
           int lowest = nums[i];
           int highest = nums[i+k-1];
           mini = min(mini,highest-lowest);
        }
        return mini;
    }
};

// Time Complexity : O(NlogN) + O(N) ~ O(NlogN)
// Space Complexity : O(logN) 
// // In C++ std::sort() function provided by STL is a hybrid of Quick Sort, Heap Sort, and Insertion Sort and has a worst-case space complexity of O(logN).