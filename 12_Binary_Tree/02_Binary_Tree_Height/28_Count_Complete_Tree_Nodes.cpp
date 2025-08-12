// Approach I
class Solution {
public:
    int cnt = 0;
    void inorder(TreeNode* root){
        if(root == NULL) return ;
        inorder(root->left);
        cnt++;
        inorder(root->right);
    }
    int countNodes(TreeNode* root) {
        inorder(root);
        return cnt;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// Approach II
class Solution {
public:
    int heightFinder(TreeNode* root, bool left) {
        int height = 0;
        while (root) {
            height++;
            root = left ? root->left : root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = heightFinder(root->left, true);
        int rightHeight = heightFinder(root->right, false);

        if (leftHeight == rightHeight) {
            return (1 << (leftHeight + 1)) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Time Complexity :O(log^2N)
// Space Complexity : O(H)