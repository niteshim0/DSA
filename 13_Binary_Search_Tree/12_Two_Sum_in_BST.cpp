// Approach I
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& ans){
        if(root == nullptr) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int i = 0,j = ans.size()-1;
        while(i<j){
            int sum = ans[i] + ans[j];
            if(sum == k) return true;
            if(sum<k) i++;
            else j--;
        }
        return false;
    }
};

// Time Complexity : O(2N)
// Space Complexity : O(N)

// Approach II
class BSTIterator {
private:
    stack<TreeNode*> st;
    bool isNext = true;
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(isNext) node = node->left;
            else node = node->right;
        }
    }
public:
    BSTIterator(TreeNode* root,bool isNext) {
        this->isNext = isNext;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tp = st.top();st.pop();
        if(isNext) pushAll(tp->right);
        else pushAll(tp->left);
        return tp->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return true;
        BSTIterator ascending(root,true);
        BSTIterator descending(root,false);
        int i = ascending.next() , j = descending.next();

        while(i<j){
            int sum = i + j;
            if(sum == k) return true;
            if(sum<k) i = ascending.next();
            else j = descending.next();
        }
        return false;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)