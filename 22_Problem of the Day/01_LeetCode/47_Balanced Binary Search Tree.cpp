// LC 1382. Balance a Binary Search Tree
// https://leetcode.com/problems/balance-a-binary-search-tree/description/

// Concept :: Tree Traversal + Recursion

// Approach ::
// if data will be in sorted order , and that gets put in a tree , that will always be a balanced BST.

// Technique 1
// 1 ) Do inorder traversal so that you can store values in sorted manner.
// 2 ) Make a BST from that sorted values.

class Solution {
public:
    vector<int> nums;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* heightBalanced(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = heightBalanced(left, mid - 1);
        root->right = heightBalanced(mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        nums.clear();
        inorder(root);
        return heightBalanced(0, nums.size() - 1);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

// Technique 2 :: Storing pointers , rather than values

class Solution {
public:
    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int m = l + (r - l) / 2;

        TreeNode* root = nodes[m];
        root->left = build(l, m - 1);
        root->right = build(m + 1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        inorder(root);
        return build(0, nodes.size() - 1);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)

//  Technique 3 :: DSW Algorithm (Day–Stout–Warren)
/*
Idea (in-place balancing)

1. Convert BST → right-skewed vine
2. Perform controlled left rotations
3. Tree becomes height-balanced

Key properties

1. ✔ No arrays
2. ✔ No recursion
3. ✔ No new nodes
4. ✔ In-place

BST
 ↓
Right-skewed vine
 ↓
Repeated rotations
 ↓
Balanced BST

*/


