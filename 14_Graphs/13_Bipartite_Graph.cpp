//https://leetcode.com/problems/is-graph-bipartite/description/
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
// if graph is acyclic or contains even length cycle -> always bipartite.
// if graph contains odd length cycle -> never bipartite (we need to check this only)
// Any moment two adjacent node have same color -> return false

// BFS Approach
class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int adj : graph[cur]) {
                if (color[adj] == -1) {
                    color[adj] = !color[cur];
                    q.push(adj);
                } else if (color[adj] == color[cur]) {
                    return false; // conflict found
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfs(i, graph, color)) 
                    return false;
            }
        }
        return true;
    }
};
// Time Complexity : O(V + E)
// Space Complexity : O(V)


// DFS Approach
class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = col;

        for (int adj : graph[node]) {
            if (color[adj] == -1) {
                if (!dfs(adj, !col, graph, color)) return false;
            } else if (color[adj] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, graph, color)) return false;
            }
        }
        return true;
    }
};
// Time Complexity : O(V + E)
// Space Complexity : O(V)

