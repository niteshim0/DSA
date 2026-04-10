// LC 3741 Minimum Distance Between Three Equal Elements II
// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/

// Concepts :: Hashing + Traversal


// Approach :: For every distinct element , keep its two previous index in hashmap , if all three are present , calcualte the minimum distance.

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return -1;

        unordered_map<int, pair<int,int>> mp;

        int mini = INT_MAX;

        for(int i = 0; i < n; i++) {
            int x = nums[i];

            if(mp.find(x) == mp.end()) {
                mp[x] = {i, -1};
            } else {
                auto &p = mp[x];

                if(p.second != -1) {
                    mini = min(mini, 2 * (i - p.second));
                }

                p.second = p.first;
                p.first = i;
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)