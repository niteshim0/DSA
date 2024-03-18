/*
Note that the key is to find an integer in the array [1,2,…,n][1, 2, \dots, n][1,2,…,n] instead of finding an integer in the input array.

We can use the binary search algorithm, each round we guess one number, then scan the input array, narrow the search range, and finally get the answer.

According to the Pigeonhole Principle, n+1n + 1n+1 integers, placed in an array of length nnn, at least 111 integer will be repeated.

So guess a number first(the number midmidmid in the valid range [left,right][left, right][left,right]), count the elements of the array which is less than or equal to midmidmid in the array.

If cntcntcnt is strictly greater than midmidmid. According to the Pigeonhole Principle, repeated elements are in the interval [left,mid][left, mid][left,mid];
Otherwise, the repeated element is in the interval [mid+1,right][mid + 1, right][mid+1,right].*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 1;
        int right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }

            if (cnt <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};