// Size of Binary Tree


class Solution {
  public:
    int getSize(Node* root) {
        
        queue<Node*> q;
        
        int ans = 0;
    
        q.push(root);
        
        while(q.size()){
            
            int levelSize = q.size();
            ans+=levelSize;
            
            for(int i = 0 ; i < levelSize ; i++){
                
                Node* node = q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
        return ans;
        
    }
};