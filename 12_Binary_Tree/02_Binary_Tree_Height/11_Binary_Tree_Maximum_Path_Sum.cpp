class Solution {
public:
    int maxSum = INT_MIN;
    int maxPathDown(TreeNode* root){
        if(root == NULL) return 0;

        int leftSum = max(0,maxPathDown(root->left));
        int rightSum = max(0,maxPathDown(root->right));

        maxSum = max(maxSum,root->val + leftSum + rightSum);

        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        maxPathDown(root);
        return maxSum;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)