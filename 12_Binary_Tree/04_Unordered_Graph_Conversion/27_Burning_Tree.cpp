class Solution {
  public:
    Node* markParents(Node* root,unordered_map<Node*,Node*>& parent,int target){
        queue<Node*> q;
        q.push(root);
        Node* res = NULL;
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0;i<levelSize;i++){
                Node* node = q.front();
                if(node->data == target){
                    res = node;
                }
                q.pop();
                if(node->left){
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        return res;
    }
    int minTime(Node* root, int target) {
        unordered_map<Node*,Node*> parent;
        Node* res = markParents(root,parent,target);
        queue<Node*> q;
        unordered_map<Node*,bool> visited;
        int timer = 0;
        q.push(res);
        visited[res] = true;
        while(!q.empty()){
            int levelSize = q.size();
            int burnerFlag = 0;
            for(int i = 0;i<levelSize;i++){
                Node* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    burnerFlag = 1;
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    burnerFlag = 1;
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    burnerFlag = 1;
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
            if(burnerFlag) timer++;
        }
        
        return timer;
    }
};
// Time Complexity : O(2N)
// Space Complexity : O(2N)