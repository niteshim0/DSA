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


// Iterative Approach
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(root == NULL) return preOrder;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top() ; st.pop();
            preOrder.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }
        return preOrder;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)