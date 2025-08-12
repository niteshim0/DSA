class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long levelMinIndex = q.front().second;
            unsigned long long firstIdx = 0, lastIdx = 0;

            for (int i = 0; i < levelSize; ++i) {
                auto [node, idx] = q.front();
                q.pop();
                idx -= levelMinIndex;
                if (i == 0) firstIdx = idx;
                if (i == levelSize - 1) lastIdx = idx;
                if (node->left) q.push({node->left, idx * 2 + 1});
                if (node->right) q.push({node->right, idx * 2 + 2});
            }

            int levelWidth = static_cast<int>(lastIdx - firstIdx + 1);
            maxWidth = max(maxWidth, levelWidth);
        }

        return maxWidth;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)