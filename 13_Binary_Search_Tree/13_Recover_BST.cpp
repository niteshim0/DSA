// Approach I
class Solution {
public:
    void inorderII(TreeNode* root,vector<int> ans,int& idx){
        if(root == NULL) return;
        inorderII(root->left,ans,idx);
        root->val = ans[idx++];
        inorderII(root->right,ans,idx);
    }
    void inorderI(TreeNode* root,vector<int>& ans){
        if(root == NULL) return ;
        inorderI(root->left,ans);
        ans.push_back(root->val);
        inorderI(root->right,ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorderI(root,ans);
        sort(ans.begin(),ans.end());
        int idx = 0;
        inorderII(root,ans,idx);
    }
};
/// Time Complexity : O(2N + NlogN)
//  Space Complexity : O(N)

// Approach II
class Solution {
private:
    TreeNode* first ;
    TreeNode* middle ;
    TreeNode* last;
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);
        if(prev!=NULL && (root->val < prev->val)){
            if(first == NULL){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};

/// Time Complexity : O(N)
//  Space Complexity : O(1)