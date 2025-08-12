// If inorder is given along with either preorder or postorder, we can uniquely determine the tree because we know which nodes go to the left and right of the root.
// If inorder is missing, we don’t have a clear left-right split, leading to multiple possible trees.
class Solution {
public:
    TreeNode* treeBuilder(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd,unordered_map<int,int>& mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* node = new TreeNode(preorder[preStart]);
        int inRoot = mp[preorder[preStart]];
        int numsLeft = inRoot - inStart;
        node->left = treeBuilder(preorder,inorder,preStart+1,preStart+numsLeft,inStart,inRoot-1,mp);
        node->right = treeBuilder(preorder,inorder,preStart+numsLeft+1,preEnd,inRoot+1,inEnd,mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return treeBuilder(preorder,inorder,0,n-1,0,n-1,mp);
    }
};
// Time Complexity : O(N + N)
// Space Complexity : O(N+N)