// Kth smallest element in a Matrix
https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1


class Solution {
    public:
    
    int countLessEqual(vector<vector<int>>& mat, int mid) {
        int n = mat.size(), m = mat[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int low = mat[0][0], high = mat[n-1][m-1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = countLessEqual(mat, mid);

            if (cnt < k)
                low = mid + 1;
            else
                high = mid  ;
        }
        return low;
    }
};

// Time Compleixity : O(logM*(N))
// Space Complexity : O(1)