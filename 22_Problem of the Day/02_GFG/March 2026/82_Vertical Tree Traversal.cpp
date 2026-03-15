// Vertical Tree Traversals (Different from Vertical Level order traversal , where we need to use multiset)
// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

// Concepts :: Hashing + Coordinate Geometry + Level Order Tree Traversals + Nested Data Structures

// Approach I ::

class Solution {
public:
    vector<vector<int>> verticalOrder(Node *root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;

        map<int, vector<int>> mp;
        queue<pair<Node*,int>> q;

        q.push({root,0});

        while(!q.empty()){
            auto [node,x] = q.front();
            q.pop();

            mp[x].push_back(node->data);

            if(node->left)
                q.push({node->left,x-1});

            if(node->right)
                q.push({node->right,x+1});
        }

        for(auto &it : mp)
            ans.push_back(it.second);

        return ans;
    }
};
// Time Commplexity : O(NlogN)
// Space Comlexity : O(N)