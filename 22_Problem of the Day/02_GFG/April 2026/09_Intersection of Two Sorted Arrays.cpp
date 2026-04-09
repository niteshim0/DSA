// Intersection of Two Sorted Arrays
// https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-arrays-with-duplicate-elements/1

// Concept :: Two Pointers  + Skipping Duplicates

// Approach :: Since both the arrays are sorted , its wise to use two pointers to check whether the both array contains same element , add it to ans , as well as skip whole duplicate strip through pointers.


class Solution {
public:
    vector<int> intersection(vector<int>& arr, vector<int>& brr) {
        
        int n = arr.size(), m = brr.size();
        vector<int> ans;

        int i = 0, j = 0;

        while (i < n && j < m) {

            if (arr[i] == brr[j]) {
                ans.push_back(arr[i]);

                int val = arr[i];
                while (i < n && arr[i] == val) i++;
                while (j < m && brr[j] == val) j++;
            }
            else if (arr[i] < brr[j]) {
                int val = arr[i];
                while (i < n && arr[i] == val) i++;
            }
            else {
                int val = brr[j];
                while (j < m && brr[j] == val) j++;
            }
        }

        return ans;
    }
};

// Time Complexity : O(N + M)
// Space Complexity : O(1)