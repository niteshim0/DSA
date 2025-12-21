class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int cnt = 0;
        vector<bool> sorted(n, false); 

        for (int j = 0; j < m; j++) {
            bool needDelete = false;
            for (int i = 1; i < n; i++) {
                if (!sorted[i] && strs[i][j] < strs[i-1][j]) {
                    needDelete = true;
                    break;
                }
            }

            if (needDelete) {
                cnt++;
                continue;
            }

            for (int i = 1; i < n; i++) {
                if (!sorted[i] && strs[i][j] > strs[i-1][j]) {
                    sorted[i] = true;
                }
            }
        }

        return cnt;
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N)