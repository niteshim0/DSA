class Solution {
  public:
    // Function to return list containing elements of left view of binary tree.
    void leftViewSolver(Node* node,int level,vector<int>& ans){
        if(node == NULL) return;
        if(level == ans.size()){
            ans.push_back(node->data);
        }
        leftViewSolver(node->left,level+1,ans);
        leftViewSolver(node->right,level+1,ans);
    }
    vector<int> leftView(Node *root) {
        vector<int> ans;
        leftViewSolver(root,0,ans);
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(H)