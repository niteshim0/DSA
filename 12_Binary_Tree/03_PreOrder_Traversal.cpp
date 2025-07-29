// Recursive Approach
class Solution {
public:
    vector<int> ans;
    void preOrder(TreeNode* node){
        if(node == NULL) return;
        ans.push_back(node->val);
        preOrder(node->left);
        preOrder(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)