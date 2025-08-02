class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            Node* node = q.front().first;
            int line = q.front().second;
            q.pop();
            if(mp.find(line) == mp.end()){
                mp[line] = node->data;
            }
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};
// Time Complexity : O(N)
// Space Complexity : O(2*N)