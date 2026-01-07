// LC 1339. Maximum Product of Splitted Binary Tree
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
// Concept :: Binary Tree Traversals
// PostOrder Traversal == logic can be calculated on subtree before processing

class Solution {
public:
    long long maxProd = 0;
    long long totalSum = 0;
    const int MOD = 1e9 + 7;

    long long dfs(TreeNode* node) {
        if (!node) return 0;

        long long left = dfs(node->left);
        long long right = dfs(node->right);

        long long subSum = node->val + left + right;

        maxProd = max(maxProd, subSum * (totalSum - subSum));

        return subSum;
    }

    long long totalNodeSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + totalNodeSum(node->left) + totalNodeSum(node->right);
    }

    int maxProduct(TreeNode* root) {
        totalSum = totalNodeSum(root);
        dfs(root);
        return maxProd % MOD;
    }

    // Time Complexity : O(N)
    // Space Complexity : O(h)
};
