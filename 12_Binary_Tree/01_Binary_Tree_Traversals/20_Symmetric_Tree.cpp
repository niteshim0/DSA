class Solution {
public:
    bool isSymmetricHelper(TreeNode* left,TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }
        if(left->val != right->val) return false;

        return isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return (root == NULL) || isSymmetricHelper(root->left,root->right);
    }
};
// Time Complexity : O(N/2)
// Space Complexity : O(H)