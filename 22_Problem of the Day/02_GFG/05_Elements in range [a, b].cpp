class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        sort(arr.begin(), arr.end());
        vector<int> ans;

        for (auto &query : queries) {
            int l = query[0], r = query[1];

            auto left  = lower_bound(arr.begin(), arr.end(), l);
            auto right = upper_bound(arr.begin(), arr.end(), r);

            ans.push_back(right - left);
        }
        return ans;
    }
};

// Time Complexity : O((n+q)logn)
// Space Complexity : O(1)