class Solution {
  public:
    int isSumProperty(Node *root) {
        if(root == NULL || ((root->left==NULL)&&(root->right==NULL))) return 1;
        int left = 0,right = 0;
        if(root->left) left = root->left->data;
        if(root->right) right = root->right->data;
        
        if(left + right == root->data && isSumProperty(root->left) && isSumProperty(root->right)){
            return 1;
        }
        return 0;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(H)