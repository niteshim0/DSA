// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<int> dist(V,1e8);
        
        
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto adjNode : adj[node]){
                if(dist[node]+1 < dist[adjNode]){
                    dist[adjNode] = 1 + dist[node];
                    q.push(adjNode);
                }
            }
        }
        
        for(int i = 0;i<V;i++){
            if(dist[i] == 1e8){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


// ✅ Time Complexity
// Building adjacency list: already provided as input.
// BFS traversal: O(V + E)
// Each edge is relaxed once.
// Post-processing loop: O(V).
// Total = O(V + E)
// ✅ Space Complexity
// dist array: O(V)
// queue: O(V)
// Implicit adjacency list storage: O(V + E)
// Total = O(V + E)