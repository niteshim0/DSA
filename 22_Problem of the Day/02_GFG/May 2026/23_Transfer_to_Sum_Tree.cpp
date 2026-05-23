// Transfer to Sum Tree
// https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1

// Concepts :: Binary Tree + Depth First Search

// Key Idea :: Simply change the parent node with the value of its child , as well as store its old value , which we will later return to its parent .

class Solution {
public:
    int dfs(Node* root){

        if(root == NULL) return 0;

        int oldVal = root->data;

        int left = dfs(root->left);
        int right = dfs(root->right);

        root->data = left + right;

        return oldVal + root->data;
    }

    void toSumTree(Node* root) {
        dfs(root);
    }
};

// Time Complexity : O(N)
// Space Complexity (Recursion Stack Space)