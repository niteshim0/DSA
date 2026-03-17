//User function Template for C++

class Solution {
  public:
  Node* makeParent(Node* root, unordered_map<Node* , Node*> &parentTrack, int target)
    {
        queue<Node* >q;
        q.push(root);
        Node* res;
        while(!q.empty())
        {
            Node* current=q.front();
            if(current->data==target) res=current;
            q.pop();
            if(current->left)
            {
                parentTrack[current->left]=current;
                q.push(current->left);
            }
            if(current->right)
            {
                parentTrack[current->right]=current;
                q.push(current->right);
            }
        }
        return res;
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> parent_track;
        Node* tar=makeParent(root,parent_track,target);
        unordered_map<Node*,bool> burnt;
        burnt[tar]=true;
        queue<Node*> q;
        q.push(tar);
        int time=0;
        while(!q.empty())
        {
            int size=q.size();
            int burnerflag=0;
            for(int i=0;i<size;i++){//BFS traversal
            Node* current=q.front();q.pop();
            if(current->left&&!burnt[current->left])
            {
                burnerflag=1;
                q.push(current->left);
                burnt[current->left]=true;
            }
            if(current->right&&!burnt[current->right])
            {
                burnerflag=1;
                q.push(current->right);
                burnt[current->right]=true;
            }
            if(parent_track[current]&&!burnt[parent_track[current]])
            {
                burnerflag=1;
                q.push(parent_track[current]);
                burnt[parent_track[current]]=true;
            }
            }
            if(burnerflag) time++;
        }
        return time;
        
        // Your code goes here
    }
   
};
