// Recursive Approach

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth,rightDepth);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(height) // if skewed O(N)

// Iterative Approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
       if(root == NULL) return 0;
       queue<TreeNode*> q;
       q.push(root);
       int depth = 0;
       while(!q.empty()){
           int levelSize = q.size();
           depth++;
           for(int i = 0;i<levelSize;i++){
               TreeNode* node = q.front();
               q.pop();
               if(node->left) q.push(node->left);
               if(node->right) q.push(node->right);
           }
       }
       return depth;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)

