// Each node is processed with its parent.
// If we encounter a visited neighbor that is not the parent, it means a cycle exists.
// If BFS finishes without finding such a case → no cycle.
// BFS Approach
class Solution {
  public:
    bool detectCycleBFS(int src,vector<int>& vis,vector<int> adj[]){
        queue<pair<int,int>> qp;
        qp.push({src,-1});
        vis[src] = 1;
        while(!qp.empty()){
            auto [node,parent] = qp.front();
            qp.pop();
            for(int adjNode : adj[node]){
                if(!vis[adjNode]){
                    qp.push({adjNode,node});
                    vis[adjNode] = 1;
                }else{
                    if(parent!=adjNode) return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V,0);
        vector<int> adj[V];
        for(auto &vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(detectCycleBFS(i,vis,adj)) return true;
            }
        }
        return false;
    }
};
// Time Complexity : O(N + 2E)
// Space Complexity : O(N)


// DFS Approach
// only works for undirected graph
class Solution {
  public:
    bool detectCycleDFS(int node,int parent,vector<int>& vis,vector<int> adj[]){
        vis[node] = 1;
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                if(detectCycleDFS(adjNode,node,vis,adj)) return true;
            }else{
                if(parent!=adjNode) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V,0);
        vector<int> adj[V];
        for(auto &vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(detectCycleDFS(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }
};

// 🔹 Time Complexity
// Building adjacency list → O(V + E)
// DFS traversal → O(V + E)
// Total = O(V + E)

// 🔹 Space Complexity
// Adjacency list → O(V + E)
// Visited array → O(V)
// Recursion stack (DFS) → O(V)
// Total = O(V + E)
