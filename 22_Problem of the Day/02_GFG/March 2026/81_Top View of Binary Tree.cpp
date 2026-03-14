// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Top View of Binary Tree

// Concepts :: Coordinate Geometry in Binary Tree + Level Order Traversal

// Approach :: We will traverse the tree levelwise , and for each node , i will give a number (line) , if on the same number(line) , multiple nodes are present , then i will take only that which first occured on that line while traversal.

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        
        vector<int> topViewElements;
        queue<pair<Node*,int>> q;
        map<int,int> mp; // ordered because (Return the nodes from the leftmost node to the rightmost node.)
        q.push({root,0});
        
        while(!q.empty()){
            auto [node,line] = q.front();
            q.pop();
            if(mp.find(line) == mp.end()){
                mp[line] = node->data;
            }
            
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        
        for(auto it : mp){
            topViewElements.push_back(it.second);
        }
        
        return topViewElements;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)