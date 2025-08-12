// Approach I
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left  = NULL;
        prev = root;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// Approach 2
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            if(!st.empty()) node->right = st.top();
            node->left = NULL;
        }
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// Morris Traversal
lass Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr) {
            if (curr->left) {
                // Find the rightmost node in the left subtree
                TreeNode* prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }
                
                // Connect the right subtree to the rightmost node of left subtree
                prev->right = curr->right;
                
                // Move the left subtree to the right
                curr->right = curr->left;
                curr->left = NULL;
            }
            // Move to the next right node
            curr = curr->right;
        }
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)