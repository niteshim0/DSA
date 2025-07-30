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

// Iterative Approach (Using Two Stacks)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if(root == NULL) return postOrder;
        TreeNode* node = root;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            node = st1.top();st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        while(!st2.empty()){
            postOrder.push_back(st2.top()->val);
            st2.pop();
        }
        return postOrder;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N*2)

// Iterative Approach (Using one Stacks)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if(root == NULL) return postOrder;
        TreeNode* node = root;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            node = st1.top();st1.pop();
            postOrder.push_back(node->val);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        reverse(postOrder.begin(),postOrder.end());
        return postOrder;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)
