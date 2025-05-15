class Solution {
public:
    // Helper function to check if it's safe to color the vertex
    bool isSafe(int node, int color, vector<int> &colors, vector<vector<int>> &adj) {
        for (int neighbor : adj[node]) {
            if (colors[neighbor] == color)
                return false;
        }
        return true;
    }

    // Backtracking function
    bool solve(int node, int m, vector<int> &colors, vector<vector<int>> &adj, int V) {
        if (node == V) return true; // All nodes colored

        for (int col = 1; col <= m; col++) {
            if (isSafe(node, col, colors, adj)) {
                colors[node] = col;
                if (solve(node + 1, m, colors, adj, V))
                    return true;
                colors[node] = 0; // Backtrack
            }
        }
        return false;
    }

    bool graphColoring(int V, vector<vector<int>> &edges, int m) {
        // Convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(V, 0); // 0 means no color assigned
        return solve(0, m, colors, adj, V);
    }
};
// Time Complexity : O(m^V)
// Space Complexity : O(V+E)