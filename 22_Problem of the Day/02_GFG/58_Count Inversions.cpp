// Count Inversions
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Concepts :: Divide and Conquer + Merge Sort + Subarray Size Calculation


// Why this works (quick intuition)

// When arr[i] > arr[j] during merge:
// The left half is already sorted
// So all elements from i to mid are greater than arr[j]
// That gives (mid - i + 1) inversions in one shot

/*
Interview Explaination
I’m using a merge-sort-based inversion count. To optimize, I pre-allocate a temporary array once instead of creating a new vector in each merge. This avoids repeated memory allocation and copying, reducing the constant factors in O(n log n) time, which prevents TLE for large arrays.
*/

class Solution {
public:
    int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
      
        int cnt = 0;
        int i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                cnt += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];


        for (int t = left; t <= right; t++) {
            arr[t] = temp[t];
        }

        return cnt;
    }

    int mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int cnt = 0;

        cnt += mergeSort(arr, temp, left, mid);
        cnt += mergeSort(arr, temp, mid + 1, right);
        cnt += merge(arr, temp, left, mid, right);

        return cnt;
    }

    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);
        return mergeSort(arr, temp, 0, n - 1);
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)