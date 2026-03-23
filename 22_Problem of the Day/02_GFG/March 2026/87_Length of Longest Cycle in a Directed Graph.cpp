// Length of Longest Cycle in a Graph
// https://www.geeksforgeeks.org/problems/length-of-longest-cycle-in-a-graph/1

// Concepts :: Adjacency List + Depth First Search + Graph\


/*
💡 The Trick

When you detect a cycle:

else if(pathVis[adjNode])

👉 That means:

You came back to a node already in your path
So cycle exists between:
adjNode → current node
*/

class Solution {
public:
    
    int maxi = -1;
    
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& timeVisited, int timer) {
        
        vis[node] = 1;
        pathVis[node] = 1;
        timeVisited[node] = timer;
        
        for (int adjNode : adj[node]) {
            
            if (!vis[adjNode]) {
                dfs(adjNode, adj, vis, pathVis, timeVisited, timer + 1);
            }
            else if (pathVis[adjNode]) {
                // cycle found
                maxi = max(maxi, timer - timeVisited[adjNode] + 1);
            }
        }
        
        pathVis[node] = 0;
    }
    
    int longestCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> vis(V, 0), pathVis(V, 0), timeVisited(V, -1);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, pathVis, timeVisited, 0);
            }
        }
        
        return maxi;
    }
};


// ⏱ Complexity
// Time: O(V + E)
// Space: O(V)