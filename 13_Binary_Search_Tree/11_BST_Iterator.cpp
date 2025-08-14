class BSTIterator {
private:
    stack<TreeNode*> st;
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tp = st.top();st.pop();
        pushAll(tp->right);
        return tp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
// Time Complexity : O(H)
// Space Complexity : O(1)