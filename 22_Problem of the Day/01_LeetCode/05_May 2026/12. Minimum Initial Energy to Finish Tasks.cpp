// 1665. Minimum Initial Energy to Finish Tasks
// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/?envType=daily-question&envId=2026-05-12

// Concepts :: Greedy + Sorting + Difference Sorting 

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(), tasks.end(),
            [](vector<int>& a, vector<int>& b) {
                return (a[1] - a[0]) > (b[1] - b[0]);
            });

        int ans = 0;
        int curr = 0;

        for (auto& task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            ans = max(ans, curr + minimum);

            curr += actual;
        }

        return ans;
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)