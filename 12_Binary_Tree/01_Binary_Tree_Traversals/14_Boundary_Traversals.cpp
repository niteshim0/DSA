class Solution {
  public:
    vector<int> ans;

    bool isLeaf(Node* root) {
        return root->left == NULL && root->right == NULL;
    }

    void addLeftBoundary(Node* node) {
        while(node) {
            if(!isLeaf(node)) ans.push_back(node->data);
            if(node->left) node = node->left;
            else node = node->right;
        }
    }

    void addLeaves(Node* node) {
        if(node == NULL) return;
        if(isLeaf(node)) {
            ans.push_back(node->data);
            return;
        }
        addLeaves(node->left);
        addLeaves(node->right);
    }

    void addRightBoundary(Node* node) {
        stack<int> st;
        while(node) {
            if(!isLeaf(node)) st.push(node->data);
            if(node->right) node = node->right;
            else node = node->left;
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }

    vector<int> boundaryTraversal(Node *root) {
        if(root == NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root->left);
        addLeaves(root);
        addRightBoundary(root->right);
        return ans;
    }
};
// Time Complexity : O(H) + O(H) + O(N) = O(N)
// Space Complexity : O(N)