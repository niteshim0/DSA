// Iterative Approach
class Solution {
public:
    TreeNode* findLeftLastRight(TreeNode* root) {
        while (root->right) {
            root = root->right;
        }
        return root;
    }

    TreeNode* removeNode(TreeNode* target) {
        if (!target->left) {
            TreeNode* rightChild = target->right;
            delete target;
            return rightChild;
        }
        if (!target->right) {
            TreeNode* leftChild = target->left;
            delete target;
            return leftChild;
        }

        TreeNode* rightChild = target->right;
        TreeNode* leftLastRight = findLeftLastRight(target->left);
        leftLastRight->right = rightChild;
        TreeNode* newRoot = target->left;
        delete target;
        return newRoot;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {
            return removeNode(root);
        }

        TreeNode* curr = root;
        while (curr) {
            if (key < curr->val) {
                if (curr->left && curr->left->val == key) {
                    curr->left = removeNode(curr->left);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right && curr->right->val == key) {
                    curr->right = removeNode(curr->right);
                    break;
                }
                curr = curr->right;
            }
        }
        return root;
    }
};
// Time Complexity : O(logN)
// Space Complexity : O(1)

// Recursive Approach
class Solution {
public:
    TreeNode* findLeftLastRight(TreeNode* root) {
        while (root->right) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Case 1: No left child
            if (!root->left) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            }
            // Case 2: No right child
            if (!root->right) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }
            // Case 3: Two children
            TreeNode* leftLastRight = findLeftLastRight(root->left);
            leftLastRight->right = root->right;
            TreeNode* newRoot = root->left;
            delete root;
            return newRoot;
        }
        return root;
    }
};

// Time Complexity : O(h)
// Space Complexity : O(h)