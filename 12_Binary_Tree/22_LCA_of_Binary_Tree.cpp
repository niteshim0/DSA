// Approach - 1
class Solution {
public:
    bool getPath(TreeNode* node,TreeNode* x,vector<TreeNode*>& path){
        if(node == NULL) return false;
        path.push_back(node);
        if(node == x) return true;

        if(getPath(node->left,x,path) || getPath(node->right,x,path)){
            return true;
        }

        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> first,second;
        TreeNode* node = NULL;
        getPath(root,p,first);
        getPath(root,q,second);
        int res = min(first.size(),second.size());
        for(int i = 0;i<res;i++){
            if(first[i] == second[i]){
                node = first[i];
            }
        }
        return node;
    }
};
// Time Complexity : O(3N)
// Space Complexity : O(4H)

// Approach :: 2
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }
};
// Time Complexity : O(H)
// Space Complexity : O(H)