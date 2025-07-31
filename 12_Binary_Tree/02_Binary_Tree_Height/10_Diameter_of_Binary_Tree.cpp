// Diameter of Binary Tree : Longest path b/w any two nodes of a binary tree
// Brute Force Approach

class Solution {
public:
    int maxi = 0;
    int treeHeight(TreeNode* node){
        if(node == NULL) return 0;

        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);

        return 1 + max(leftHeight,rightHeight);
    }
    void diameter(TreeNode* node){
        if(node == NULL) return ;

        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);

        maxi = max(maxi,leftHeight + rightHeight);

        diameter(node->left);
        diameter(node->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxi;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N*N)

// Optimal Approach

class Solution {
public:
    int diameter = 0;
    int treeHeight(TreeNode* node){
        if(node == NULL) return 0;

        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);
        diameter = max(diameter,leftHeight+rightHeight);

        return 1 + max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        treeHeight(root);
        return diameter;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)