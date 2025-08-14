class Solution {
public:
    int need, cnt = 0;

    TreeNode* inorder(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* left = inorder(root->left);
        if (left) return left;
        cnt++;
        if (cnt == need) return root;
        return inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        need = k;
        return inorder(root)->val;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(h)

// Morris Traversal

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1; 
        TreeNode* curr = root;
        int cnt = 0;
        while (curr) {
            if (!curr->left) {
                if (++cnt == k) return curr->val;
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) prev = prev->right;
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    if (++cnt == k) return curr->val;
                    curr = curr->right;
                }
            }
        }
        return -1; 
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)


