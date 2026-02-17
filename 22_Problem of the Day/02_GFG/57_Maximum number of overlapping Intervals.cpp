// Maximum number of overlapping Intervals
// https://www.geeksforgeeks.org/problems/intersecting-intervals/1
// Concepts :: Sweep Line + Two Pointers + Sorting + Priority Queue + Interval Questions



// Approach

// Separate start times and end times
// Sort both
// Move pointers and count active intervals
// Every start adds a meeting
// Every end removes a meeting
// start[i] < end[j] ensures strict overlap
// Duplicates automatically counted


// Technique 1 :: Use Sweep Line + Sorting + Two Pointers
class Solution {
public:
    int overlapInt(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> start(n), end(n);

        for (int i = 0; i < n; i++) {
            start[i] = arr[i][0];
            end[i] = arr[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0;
        int curr = 0, maxi = 0;

        while (i < n && j < n) {
            if (start[i] <= end[j]) {  
                curr++;
                maxi = max(maxi, curr);
                i++;
            } else {
                curr--;
                j++;
            }
        }

        return maxi;
    }
};
// Time Complexity : O(NlogN)
// Space Complexity : O(N)

// Technique 2 :: Use Priority Queue
// Sort intervals by start
// Use a min-heap to track earliest ending meeting

int overlapInt(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    int maxi = 0;

    for (auto &it : arr) {
        while (!pq.empty() && pq.top() <= it[0])
            pq.pop();

        pq.push(it[1]);
        maxi = max(maxi, (int)pq.size());
    }
    return maxi;
}
// Time Complexity : O(NlogN)
// Space Complexity : O(N)


// Technique 3 :: Difference Array + Prefix Sum 
// Key Idea is that "how many meetings are active at time t(t is discrete value)"
// calculate the "maximum subarray sum on diffArray"(Kadane's Algorithm) -> all the meetings are active at certain time t 
// worst solution :: time ranges >=1e6, use sweep line(almost solves 90% ques) -> in interval question
// best soluttion ::  time range is small && startTime and endTime are discrete 

class Solution {
public:
    int overlapInt(vector<vector<int>> &arr) {

        int maxTime = 0;
        for (auto &vec : arr) {
            maxTime = max(maxTime, vec[1]);
        }

        vector<int> diffArray(maxTime + 2, 0);

        for (auto &interval : arr) {
            int startTime = interval[0];
            int endTime   = interval[1];

            diffArray[startTime]++;      // meeting starts
            diffArray[endTime + 1]--;    // meeting ends AFTER endTime
        }

        int active = 0, ans = 0;
        for (int x : diffArray) {
            active += x;
            ans = max(ans, active);
        }

        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)
                                                                        

