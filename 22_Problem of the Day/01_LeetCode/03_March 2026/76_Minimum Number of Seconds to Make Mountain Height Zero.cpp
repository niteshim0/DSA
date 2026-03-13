// LC 3296. Minimum Number of Seconds to Make Mountain Height Zero
// https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description

// Concepts :: Binary Search on Answers + Quadratic Formula (How to solve quadration equation) + triangular sum(sum of 1 to n natural numbers)

// Observation
/*
for each worker time increases something like this : workerTime + workerTime*2 + workerTime*3 + .....................+ workerTime*(n-1)  + workerTime*n  , in this way time grows for each worker .

if we formulate them
workerTime * (1 + 2 + 3 + ..................+ n-1 + n)
workerTime*(n*(n+1)/2) // these should be the worst case , where a single worker has to cut the whole mountain 
*/

// Main Insight
/*
Instead of thinking:

❌ "How much time to cut height H"

Think:

✅ In X seconds how much height can each worker cut

This converts the problem to:

Find minimum seconds such that
total height cut ≥ mountainHeight

This is a classic Binary Search on Answer problem.
*/

// Binary Search Intuition
/*
If we check : seconds = 10

Workers cut some height.
If height ≥ mountainHeight → possible.
If not → need more time.

So the condition is monotonic.
time → possible?
1   → no
2   → no
3   → no
...
15  → yes
16  → yes
17  → yes

This monotonic behavior → Binary Search.
*/

⃣ //Binary Search Range
/*
Minimum time(start) : 1 second
Maximum time (worst case):
One worker cuts all height.
Safe bound :  1e18
*/

// ⃣ Feasibility Check

// For a given seconds, compute:height cut by each worker. Sum them.
// If sum ≥ mountainHeight → feasible.


// Finding Height Cut by Worker
/*
We solve t*(h*(h+1)/2) < = seconds
         h^2 + h  = (2*seconds)/t;
         h^2 + h - X  = 0 , where X = (2*seconds)/t;
         // Applying quadratic formula
         h = (-1 + sqrt(1 + 4X))/2
*/

// Approach I :: Loop per Worker
class Solution {
public:

    long long heightWorkerCanCut(long long seconds,
                                 int workerTime,
                                 int mountainHeight) {

        long long timeUsed = 0;
        long long height = 1;

        while(height <= mountainHeight &&
              timeUsed + 1LL * workerTime * height <= seconds) {

            timeUsed += 1LL * workerTime * height;
            height++;
        }

        return height - 1;
    }

    bool canReduceMountain(long long seconds,
                           vector<int>& workerTimes,
                           int mountainHeight) {

        long long totalHeight = 0;

        for(int workerTime : workerTimes) {

            totalHeight += heightWorkerCanCut(seconds,
                                               workerTime,
                                               mountainHeight);

            if(totalHeight >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight,
                                 vector<int>& workerTimes) {

        long long left = 1;
        long long right = 1e18;
        long long answer = -1;

        while(left <= right) {

            long long mid = left + (right - left) / 2;

            if(canReduceMountain(mid, workerTimes, mountainHeight)) {
                answer = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
// Time Complexity
/*
Binary search × workers × height loop
O(logT * W * h) where 
T = searchRange(1e18) log(1e18) ~ 60
W = number of workers
h = mountainHeight (lesser than this ) // effectively O(60*W*H)
*/
// Space Complexity : O(1)

// Approach II :: Using Quadratic Formula to find how much a worker can cut in a given seconds

class Solution {
public:

    long long heightWorkerCanCut(long long totalSeconds, int workerTime) {

        long long value = (2LL * totalSeconds) / workerTime;

        long long height = (sqrt(1 + 4 * value) - 1) / 2;

        return height;
    }

    bool canReduceMountain(long long seconds,
                           vector<int>& workerTimes,
                           int mountainHeight) {

        long long totalHeightReduced = 0;

        for(int workerTime : workerTimes) {

            totalHeightReduced += heightWorkerCanCut(seconds, workerTime);

            if(totalHeightReduced >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight,
                                 vector<int>& workerTimes) {

        long long left = 1;
        long long right = 1e18;
        long long answer = -1;

        while(left <= right) {

            long long midTime = left + (right - left) / 2;

            if(canReduceMountain(midTime, workerTimes, mountainHeight)) {
                answer = midTime;
                right = midTime - 1;
            }
            else {
                left = midTime + 1;
            }
        }

        return answer;
    }
};
// Time Complexity : O(W*logT)
// Space Complexity : O(1)