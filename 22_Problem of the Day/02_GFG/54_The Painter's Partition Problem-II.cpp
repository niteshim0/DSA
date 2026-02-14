// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// The Painter's Partition Problem-II

/* Core Concepts Used

--> Binary Search on Answer(ans searching in a range of possible answers)

--> Greedy Allocation
Assign boards sequentially to the current painter.
When time exceeds limit → assign a new painter.

-->Monotonic Predicate
isPainterEnough(mid) → true / false
if once true all other next to it also be true.
*/


/*
:: Intuition

1. We must paint all boards using k painters
2. Each painter paints only continuous boards
3. Painters can work in parallel

"Total time = maximum time taken by any single painter"
We want to minimize this maximum time

--> This clearly hints at “minimize the maximum” → Binary Search on Answer

*/

/*
:: Key Insights

1. A board cannot be split
So minimum possible time = max(board length)

2. At most one painter paints a board
Maximum possible time = sum of all boards

3. If painters can finish in X time,
they can also finish in any time ≥ X
➜ Monotonic behavior
This monotonic nature allows binary search.
*/


/*
:: Interview Explaination ::
This is a partition problem where we need to minimize the maximum workload.Since the answer lies between the largest board and the sum of all boards,I apply binary search on this range.For each mid value, I greedily check if k painters can paint all boards by assigning continuous boards and starting a new painter whenever the time exceeds mid.If it’s possible, I try to minimize further; otherwise, I increase the time.
*/

class Solution {
public:
    bool isPainterEnough(vector<int>& arr, int k, int mid) {
        int painter = 1;
        int timeReq = 0;

        for (int board : arr) {
            timeReq += board;

            if (timeReq > mid) {
                painter++;
                timeReq = board;
            }

            if (painter > k)
                return false;
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {
        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);

        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isPainterEnough(arr, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

// Time Complexity : O(Nlog(Sum))
// Space Complexity : O(1)