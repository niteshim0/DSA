// LC 3161. Block Placement Queries
// Concepts :: Ordered Set + Binary Search + Segment Tree + Coordinate Compression + Fenwick Tree


// Use segement tree to find the max gap b/w segments.

class Solution {
public:
    bool blockPlacing(int x, int sz, set<int>& obstacles) {
       
       int prev = 0 ;

       for(auto it = obstacles.begin() ; it!=obstacles.end() && *it<=x ; it++){

            int curr = *it;
            if((curr-prev)>=sz) return true;
            prev = curr;
       }

       if((x-prev)>=sz) return true;
       
        return false;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        set<int> obstacles;
        vector<bool> ans;

        for (vector<int>& query : queries) {

            if (query[0] == 1) {
                obstacles.insert(query[1]); // O(logN)
               
            } 
            else {

                bool isBlockPlacingPossible = blockPlacing(query[1], query[2], obstacles);
                ans.push_back(isBlockPlacingPossible);
                // O(N)
            }
        }

        return ans;

        // O(N*N)
    }
};

class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {

        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] =
            max(tree[2 * node],
                tree[2 * node + 1]);
    }

    int query(int node,
              int l,
              int r,
              int ql,
              int qr) {

        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = l + (r - l) / 2;

        return max(
            query(2 * node,
                  l,
                  mid,
                  ql,
                  qr),

            query(2 * node + 1,
                  mid + 1,
                  r,
                  ql,
                  qr)
        );
    }
};
class Solution {
public:

    vector<bool> getResults(vector<vector<int>>& queries) {

        vector<int> coords;

        for (auto &q : queries) {
            coords.push_back(q[1]);
        }

        sort(coords.begin(), coords.end());

        coords.erase(
            unique(coords.begin(), coords.end()),
            coords.end()
        );

        int m = coords.size();

        SegmentTree seg(m);

        set<int> obstacles;

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int x = q[1];

                auto nxt =
                    obstacles.lower_bound(x);

                int prevObstacle = 0;

                if (nxt != obstacles.begin()) {
                    prevObstacle = *prev(nxt);
                }

                int idxX =
                    lower_bound(
                        coords.begin(),
                        coords.end(),
                        x
                    ) - coords.begin();

                seg.update(
                    1,
                    0,
                    m - 1,
                    idxX,
                    x - prevObstacle
                );

                if (nxt != obstacles.end()) {

                    int nextObstacle = *nxt;

                    int idxNext =
                        lower_bound(
                            coords.begin(),
                            coords.end(),
                            nextObstacle
                        ) - coords.begin();

                    seg.update(
                        1,
                        0,
                        m - 1,
                        idxNext,
                        nextObstacle - x
                    );
                }

                obstacles.insert(x);
            }

            else {

                int x = q[1];
                int sz = q[2];

                auto it =
                    obstacles.upper_bound(x);

                int lastObstacle = 0;

                if (it != obstacles.begin()) {
                    --it;
                    lastObstacle = *it;
                }

                int idx = -1;

                if (lastObstacle != 0) {

                    idx =
                        lower_bound(
                            coords.begin(),
                            coords.end(),
                            lastObstacle
                        ) - coords.begin();
                }

                int bestGap = 0;

                if (idx >= 0) {

                    bestGap =
                        seg.query(
                            1,
                            0,
                            m - 1,
                            0,
                            idx
                        );
                }

                bestGap =
                    max(
                        bestGap,
                        x - lastObstacle
                    );

                ans.push_back(
                    bestGap >= sz
                );
            }
        }

        return ans;
    }
};

class FenwickTree {
public:
    vector<int> bit;

    FenwickTree(int n) {
        bit.resize(n + 1, 0);
    }

    void update(int idx, int val) {

        while (idx < bit.size()) {

            bit[idx] = max(bit[idx], val);

            idx += (idx & -idx);
        }
    }

    int query(int idx) {

        int ans = 0;

        while (idx > 0) {

            ans = max(ans, bit[idx]);

            idx -= (idx & -idx);
        }

        return ans;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int LIMIT =
            min(50000,
                (int)queries.size() * 3);

        FenwickTree bit(LIMIT + 2);

        set<int> obstacles;

        obstacles.insert(0);
        obstacles.insert(LIMIT);

        for (auto &q : queries) {

            if (q[0] == 1) {

                obstacles.insert(q[1]);
            }
        }

        for (auto it = obstacles.begin();
             next(it) != obstacles.end();
             ++it) {

            int left = *it;
            int right = *next(it);

            bit.update(
                right,
                right - left
            );
        }

        vector<bool> ans;

        for (int i = queries.size() - 1;
             i >= 0;
             i--) {

            auto &q = queries[i];

            if (q[0] == 1) {

                int x = q[1];

                auto it =
                    obstacles.find(x);

                int prevObs =
                    *prev(it);

                int nextObs =
                    *next(it);

                bit.update(
                    nextObs,
                    nextObs - prevObs
                );

                obstacles.erase(it);
            }

            else {

                int x = q[1];
                int sz = q[2];

                auto it =
                    obstacles.upper_bound(x);

                int prevObs =
                    *prev(it);

                int bestGap =
                    bit.query(prevObs);

                bool canPlace =
                    (
                        bestGap >= sz
                    )
                    ||
                    (
                        x - prevObs >= sz
                    );

                ans.push_back(canPlace);
            }
        }

        reverse(
            ans.begin(),
            ans.end()
        );

        return ans;
    }
};