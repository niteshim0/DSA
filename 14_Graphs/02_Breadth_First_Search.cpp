class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        int vis[n+1] = {0};
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        vector<int> bfss;
        while(!q.empty()){
            int node = q.front();q.pop();
            bfss.push_back(node);
            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    q.push(adjNode);
                    vis[adjNode] = 1;
                }
            }
        }
        return bfss;
    }
};
// Time Complexity : O(3*N)
// Space Complexity: O(N) + O(2E)