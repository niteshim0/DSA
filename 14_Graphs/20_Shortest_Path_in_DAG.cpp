// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// DFS Version
class Solution {
  public:
    void dfs(int node, vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            int adjNode = it.first;
            if(!vis[adjNode]) {
                dfs(adjNode, adj, vis, st);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list (with weights)
        vector<pair<int,int>> adj[V];
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        
        // Step 2: Topological sort
        stack<int> st;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        
        // Step 3: Relax edges in topo order
        vector<int> dist(V, 1e9);
        dist[0] = 0;  // source node = 0
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(dist[node] != 1e9) { // ensure node is reachable
                for(auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        // Step 4: Convert unreachable distances to -1
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};
// Complexity
// Topological Sort (DFS): O(V + E)
// Relaxation (DAG edges): O(V + E)
// Overall:
// Time Complexity = O(V + E)
// Space Complexity = O(V + E) (adjacency list + recursion + stack)

// BFS Version
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list with weights
        vector<pair<int,int>> adj[V];
        vector<int> indegree(V, 0);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            indegree[v]++;
        }
        
        // Step 2: Kahn’s Algorithm (BFS Topological Sort)
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topoOrder;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            
            for(auto it : adj[node]) {
                int v = it.first;
                if(--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Step 3: Relax edges in topo order
        vector<int> dist(V, 1e9);
        dist[0] = 0;  // Source = 0
        for(int node : topoOrder) {
            if(dist[node] != 1e9) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        // Step 4: Mark unreachable as -1
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};
// Complexity
// Building adjacency list: O(E)
// Topological Sort (Kahn’s): O(V + E)
// Relaxation: O(V + E)
// Overall:
// Time = O(V + E)
// Space = O(V + E)