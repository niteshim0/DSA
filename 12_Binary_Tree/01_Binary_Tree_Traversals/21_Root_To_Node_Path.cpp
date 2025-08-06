bool getPath(TreeNode* root,vector<int>& ans,int B)
{
    if(root==NULL) return false;
    ans.push_back(root->val);
    if(root->val==B)
    {
        return true;
    }
    if(getPath(root->left,ans,B)||getPath(root->right,ans,B))
    {
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(!A) return ans;
    getPath(A,ans,B);
    return ans;
}

// Time Complexity : O(N)
// Space Complexity : O(H)