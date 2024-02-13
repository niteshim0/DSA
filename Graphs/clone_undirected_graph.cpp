class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> mp;
        queue<Node*> qp;
        qp.push(node);
        mp[node] = new Node(node->val);
        while(!qp.empty()){
            Node* need = qp.front();
            qp.pop();
            for(auto &adjNode : need->neighbors){
                if(mp.find(adjNode) == mp.end()){
                    mp[adjNode] = new Node(adjNode->val);
                    qp.push(adjNode);
                }
                mp[adjNode]->neighbors.push_back(mp[need]);
            }
            
        }
        return mp[node];
    }
};