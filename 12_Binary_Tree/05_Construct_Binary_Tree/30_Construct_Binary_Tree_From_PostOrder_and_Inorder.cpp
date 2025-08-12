class Solution {
public:
    TreeNode* treeBuilder(vector<int>& postorder,vector<int>& inorder,int postStart,int postEnd,int inStart,int inEnd,unordered_map<int,int>& mp){
        if(inStart>inEnd || postStart>postEnd) return NULL;

        TreeNode* node = new TreeNode(postorder[postEnd]);
        int inRoot = mp[postorder[postEnd]];
        int numsLeft = inRoot - inStart;
        
        node->left = treeBuilder(postorder,inorder,postStart,postStart+numsLeft-1,inStart,inRoot-1,mp);
        node->right = treeBuilder(postorder,inorder,postStart+numsLeft,postEnd-1,inRoot+1,inEnd,mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return treeBuilder(postorder,inorder,0,n-1,0,n-1,mp);
    }
};

// Time Complexity :: O(N)
// Space Complexity :: O(N)