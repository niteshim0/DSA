// Brute Force Approach
class Solution {
public:
    int treeHeight(TreeNode* root){
        if(root == NULL) return 0;

        int lh = treeHeight(root->left);
        int rh = treeHeight(root->right);

        return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        if(abs(leftHeight-rightHeight)>1) return false;

        bool leftBal = isBalanced(root->left);
        bool rightBal = isBalanced(root->right);

        return leftBal&&rightBal;
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(2N)

// Optimal Approach

class Solution {
public:
    int treeHeight(TreeNode* root){
        if(root == NULL) return 0;

        int lh = treeHeight(root->left);
        if(lh == -1) return -1;
        int rh = treeHeight(root->right);
        if(rh == -1) return -1;
        if(abs(lh-rh)>1) return -1;

        return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        return treeHeight(root)!=-1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)