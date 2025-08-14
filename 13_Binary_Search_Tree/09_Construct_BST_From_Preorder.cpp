// Approach I
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);
    }
};
// Time Complexity : O(NlogN + N)
// Space Complexity : O(2N)

// Approach II
class Solution {
public:
    TreeNode* treeBuilder(int& idx,int bound,vector<int>& preorder){
        if(idx == preorder.size() || preorder[idx]>bound) return NULL;
       
        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = treeBuilder(idx,root->val,preorder);
        root->right = treeBuilder(idx,bound,preorder);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return treeBuilder(idx,INT_MAX,preorder);
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)