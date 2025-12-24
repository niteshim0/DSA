// LC 2054. Two Best Non-Overlapping Events
// https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2025-12-23

// Approach I : Top Down DP

class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nextIdx;
    int n;

    int solve(int i, int cnt, vector<vector<int>>& events) {
        if (i == n || cnt == 2) return 0;
        if (dp[i][cnt] != -1) return dp[i][cnt];

        // option 1: skip
        int notPick = solve(i + 1, cnt, events);

        // option 2: pick
        int pick = events[i][2] + solve(nextIdx[i], cnt + 1, events);

        return dp[i][cnt] = max(pick, notPick);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        n = events.size();

        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1, ans = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (events[mid][0] > events[i][1]) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            nextIdx[i] = ans;
        }

        dp.assign(n, vector<int>(3, -1));
        return solve(0, 0, events);
    }
};

// Time Complexity : O(NLogN) // sorting + binary Search + Dp
// Space Complexity : O(N) + O(N*3)


// Approach II :: Priority Queue(Min Heap Solution)

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        int maxVal = 0 , maxSum = 0;

        for(auto& event : events){

            while(pq.size() && pq.top().first < event[0]){
                maxVal = max(maxVal,pq.top().second);
                pq.pop();
            }

            maxSum = max(maxSum,maxVal + event[2]);
            pq.push({event[1],event[2]});
        }

        return maxSum;
    }
};


// Time Complexity : O(NLogN) 
// Space Complexity : O(N)

// Approach III :: Greedy  + Prefix Max