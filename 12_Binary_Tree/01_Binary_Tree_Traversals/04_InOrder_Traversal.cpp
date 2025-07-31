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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node!=NULL){
               st.push(node);
               node = node->left;
            }else{
                if(st.empty()) break;
                node = st.top() ; st.pop();
                inOrder.push_back(node->val);
                node = node->right;
            }
        }
        return inOrder;
    }
};
// Time Complexity : O(N)
// Space Complexity: O(N)