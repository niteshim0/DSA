// Course Schedule I
// https://www.geeksforgeeks.org/problems/course-schedule-i/1

// Concepts :: Topological Sorting + Indegree Calculation + Adjacency List
// + Kahn's Algorithm ( BFS for topoSort)

// Approach :: If cycle exist , never able to complete the course in any order , or if we can't find any valid topoSort order -> no any order of course schedule as well

// Technique 1 :: Kahn's Algo ( BFS for topological Sorting)

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // build graph
        for (auto &e : prerequisites) {
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;

        // push all 0 indegree nodes
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int cnt = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            cnt++;

            for (int nei : adj[node]) {
                if (--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return cnt == n;
    }
};

// Technique 2 :: DFS Cycle Detection

class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int nei : adj[node]) {
            
            if (!vis[nei]) {
                if (dfs(nei, adj, vis, pathVis)) return true;
            }
            else if (pathVis[nei]) {
                return true; // cycle found
            }
        }

        pathVis[node] = 0; // backtrack
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(n);

        for (auto &e : prerequisites) {
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0), pathVis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) {
                    return false; // cycle exists
                }
            }
        }

        return true;
    }
}
// | Approach   | Time       | Space      | Extra                |
// | ---------- | ---------- | ---------- | -------------------- |
// | BFS (Kahn) | `O(V + E)` | `O(V + E)` | Uses queue           |
// | DFS        | `O(V + E)` | `O(V + E)` | Uses recursion stack |

