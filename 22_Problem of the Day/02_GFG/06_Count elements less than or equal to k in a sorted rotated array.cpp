

// Approach I :: Finding Pivot
class Solution {
public:
    int pivotFinder(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid < end && nums[mid] > nums[mid + 1])
                return mid;
            if (mid > start && nums[mid - 1] > nums[mid])
                return mid - 1;

            if (nums[start] > nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }

    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int pivot = pivotFinder(arr);

        if (pivot == -1) {
            return upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        }

        int leftCount = upper_bound(arr.begin(), arr.begin() + pivot + 1, x) - arr.begin();
        int rightCount =
            upper_bound(arr.begin() + pivot + 1, arr.end(), x) - (arr.begin() + pivot + 1);

        return leftCount + rightCount;
    }
};
// Time Complexity : O(logn)
// Space Complexity : O(1)

// Approach II :: Without finding pivot

class Solution {
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int start = 0, end = n - 1;
        int cnt = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[start] <= arr[mid]) {
                if (arr[start] <= x && x >= arr[mid]) {
                    cnt += (mid - start + 1);
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (arr[mid] <= x && x <= arr[end]) {
                    cnt += (end - mid + 1);
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return cnt;
    }
};

// Time Complexity : O(logn)
// Space Complexity : O(1)
