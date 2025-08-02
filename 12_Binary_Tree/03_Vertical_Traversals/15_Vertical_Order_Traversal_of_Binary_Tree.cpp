class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<pair<TreeNode*, pair<int, int>>> qp;
        qp.push({root, {0, 0}});

        while (!qp.empty()) {
            auto pair = qp.front(); qp.pop();
            TreeNode* node = pair.first;
            int x = pair.second.first, y = pair.second.second;

            nodes[x][y].insert(node->val);

            if (node->left) qp.push({node->left, {x - 1, y + 1}});
            if (node->right) qp.push({node->right, {x + 1, y + 1}});
        }

        for (auto& mp : nodes) {
            vector<int> col;
            for (auto& x : mp.second) {
                col.insert(col.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

// Time Complexity : O(NLogN)
// Space Complexity : O(N)