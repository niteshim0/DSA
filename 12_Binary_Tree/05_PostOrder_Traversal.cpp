// Recursive Approach
class Solution {
public:
    vector<int> ans;
    void postOrder(TreeNode* node){
        if(node == NULL) return;
        postOrder(node->left);
        postOrder(node->right);
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)
