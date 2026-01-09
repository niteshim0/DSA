// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes
// LC 865. Smallest Subtree with all the Deepest Nodes
// Concept :: Lowest Common Ancestor(Binary Tree) + Tree Traversals


// Approach I :: find two nodes at extreme position at last level and take their LCA
class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* left = LCA(root->left,p,q);
        TreeNode* right = LCA(root->right,p,q);
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        if(root == NULL || (root->left == NULL && root->right == NULL)) 
            return root;

        TreeNode* lastLevelLeftMost = NULL;
        TreeNode* lastLevelRightMost = NULL;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int levelSize = q.size();

            for(int i = 0;i<levelSize;i++){

                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                if(i == 0) lastLevelLeftMost = node;
                if(i == levelSize - 1) lastLevelRightMost = node;
            }
        }

        return LCA(root,lastLevelLeftMost,lastLevelRightMost);

    }
};

// Time Complexity : O(N)
// Space Complexity : O(W) // W - width of the binary tree

// Approach II:: 
/*At every node, ask:
“Where are the deepest nodes in my left and right subtrees, and are they at the same depth?”
Single Traversal*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {NULL, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.second > right.second)
            return {left.first, left.second + 1};
        if (right.second > left.second)
            return {right.first, right.second + 1};

        return {root, left.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(H)

