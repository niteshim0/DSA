class Solution {
  public:
    // Function to return list containing elements of right view of binary tree.
    void rightViewSolver(Node* node,int level,vector<int>& ans){
        if(node == NULL) return;
        if(level == ans.size()){
            ans.push_back(node->data);
        }
        rightViewSolver(node->right,level+1,ans);
        rightViewSolver(node->left,level+1,ans);
    }
    vector<int> rightView(Node *root) {
        vector<int> ans;
        rightViewSolver(root,0,ans);
        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(H)