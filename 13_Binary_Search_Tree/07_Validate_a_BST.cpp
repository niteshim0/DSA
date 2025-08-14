class Solution {
public:
    bool validBST(TreeNode* root, long long mini, long long maxi) {
        if (root == NULL) return true;
        return (root->val > mini && root->val < maxi) &&
               validBST(root->left, mini, root->val) &&
               validBST(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return validBST(root, LLONG_MIN, LLONG_MAX);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(h)