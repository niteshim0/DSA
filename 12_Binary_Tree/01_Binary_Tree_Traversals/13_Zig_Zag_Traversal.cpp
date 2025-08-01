class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool leftToRight = true;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node = root;
        while(!q.empty()){
            int sz = q.size();
            vector<int> level(sz,0);
            for(int i = 0;i<sz;i++){
               node = q.front();q.pop();
               int idx  = leftToRight ? i : sz-i-1;
               level[idx] = node->val;
               if(node->left) q.push(node->left);
               if(node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(N)