class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;
        while(node!=NULL && node->val!=val){
            if(val>node->val){
                node = node->right;
            }else{
                node = node->left;
            }
        }
        return node;
    }
};
// Time Complexity : O(log2(N))
// Space Complexity : O(1)