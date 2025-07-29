// Recursive Approach
class Solution {
public:
    vector<int> ans;
    void inOrder(TreeNode* node){
        if(node == NULL) return ;
        inOrder(node->left);
        ans.push_back(node->val);
        inOrder(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity: O(N)

// Iterative Approach