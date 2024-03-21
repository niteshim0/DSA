/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int levelNum = q.size();
            vector<int> subans(levelNum);
            for(int i = 0;i<levelNum;i++)
            {   TreeNode* node = q.front();
                if(q.front()->left!=NULL) q.push(q.front()->left);
                if(q.front()->right!=NULL) q.push(q.front()->right);
                int index = leftToRight ? i : levelNum - i - 1;
                subans[index] = node->val;
                q.pop();
            }
            leftToRight = !leftToRight;
            ans.push_back(subans);
        }
        return ans;
    }
};