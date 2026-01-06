// LC 1161. Maximum Level Sum of a Binary Tree
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description
// 6 Jan , 26
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

 // Approach I :: BFS (Level Order Traversal)
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int maxVal = INT_MIN , maxLevel = 1;

        while(!q.empty()){
            int levelSize = q.size();
            int sum = 0;
            for(int i = 0;i<levelSize;i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum>maxVal){
                maxVal = sum;
                maxLevel = level;
            }
            level++;
        }

        return maxLevel;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


// Approach II :: DFS

class Solution {
public:
    vector<int> levelSum;
    void dfs(TreeNode* node,int level){
        if(!node) return;

        if(level == levelSum.size()){
            levelSum.push_back(0); // it is an excellent trick to initialize an index for which level
                                  // whenever we encounter a new level just push a 0
        }

        levelSum[level]+=node->val;

        dfs(node->left,level+1);
        dfs(node->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,0);
        int maxVal = INT_MIN , maxLevel = 1;
        for(int i = 0;i<levelSum.size();i++){
            if(levelSum[i]>maxVal){
                maxVal = levelSum[i];
                maxLevel = i + 1;
            }
        }
        return maxLevel;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(H) // H = Height of Tree


| Scenario             | Better Choice |
| -------------------- | ------------- |
| Level-based problems | **BFS**       |
| Shortest path        | **BFS**       |
| Backtracking         | **DFS**       |
| Path-related logic   | **DFS**       |
| Very deep tree       | **BFS**       |
| Very wide tree       | **DFS**       |
