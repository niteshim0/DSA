// LC 3488 . Closest Equal Element Queries
// https://leetcode.com/problems/closest-equal-element-queries

// Concepts :: Two Pointers + Math + Circular Array + Binary Search


// Approach I :: Grouping + Binary Search
/*
Instead of scanning the whole array:
“jump directly to my position inside my value-group”
Then:
“closest same value must be just before or after me in that group”

Since idx are pushed in such a way that they will always be in sorted order in a value-group.
*/

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> best(n, -1);

        for(auto &it : mp){

            vector<int>& pos = it.second;
            int k = pos.size();

            if(k == 1) continue;

            for(int i = 0 ; i < k ; i++){

                int cur = pos[i];
                int prev = pos[(i - 1 + k) % k];
                int next = pos[(i + 1) % k];  

                int d1 = abs(cur - prev);
                int d2 = abs(cur - next);

                d1 = min(d1, n - d1);
                d2 = min(d2, n - d2);

                best[cur] = min(d1, d2);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for(int q : queries){
            ans.push_back(best[q]);
        }

        return ans;
    }
};

// ⚡ Complexity
// Build map: O(n)
// Each query: O(log k)
// Total: O(n + q log n)
// Space: O(n)


// Approach II : Grouping + Two Pointers + Precomputation

/*
🧠 Key Idea

For each value group:
treat indices as a circular linked list
only check previous and next neighbors
precompute answer for every index

Then queries become O(1)

💡 Intuition

Once indices are grouped:
You don’t need search anymore — the structure already tells you nearest neighbors.
Because in a sorted circular list: nearest same element is always adjacent.
*/


class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> best(n, -1);

        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int k = pos.size();

            if (k == 1) continue;

            for (int i = 0; i < k; i++) {
                int cur = pos[i];

                int prev = pos[(i - 1 + k) % k];
                int next = pos[(i + 1) % k];

                int d1 = abs(cur - prev);
                int d2 = abs(cur - next);

                d1 = min(d1, n - d1);
                d2 = min(d2, n - d2);

                best[cur] = min(d1, d2);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (int q : queries) {
            ans.push_back(best[q]);
        }

        return ans;
    }
};

// ⚡ Complexity
// Preprocessing: O(n)
// Queries: O(1) each
// Total: O(n + q)
// Space: O(n)










/*
🔥 Pattern Recognition

This problem belongs to:

🟦 Pattern 1: “Grouped Index Nearest Neighbor”

Used when:
- repeated values exist.
- need closest same element.


🟩 Pattern 2: “Circular Linked List on Indices”

Used when:
- wrap-around distance is involved.
- adjacency matters.

🟨 Pattern 3: “Query Optimization”

Two levels:
- O(log n): binary search per query
- O(1): precompute answers



🚀 How to recognize this in future

If you see:
🔍 Keywords:
- closest equal element.
- circular distance.
- repeated values.
- many queries.


💡 Think immediately:
“group indices + check neighbors only”
*/

/*
🔥 Focus Problems (must do in order)

🟢 Core Pattern (start here)
https://leetcode.com/problems/shortest-word-distance-ii/
https://leetcode.com/problems/shortest-word-distance/
https://leetcode.com/problems/shortest-word-distance-iii/

🟡 Closest to your problem (VERY IMPORTANT)
https://leetcode.com/problems/number-of-good-pairs/
https://leetcode.com/problems/minimum-absolute-sum-difference/
https://leetcode.com/problems/find-k-closest-elements/

🟠 Advanced extension of same idea
https://leetcode.com/problems/sum-of-distances-in-tree/
https://leetcode.com/problems/closest-leaf-in-a-binary-tree/
https://leetcode.com/problems/shortest-distance-to-a-character/

🔴 Contest / Hard pattern evolution
https://leetcode.com/problems/jump-game-v/
https://leetcode.com/problems/jump-game-vi/
https://leetcode.com/problems/online-election/
*/