// LC 1976. Number of Ways to Arrive at Destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

// Concepts :: Dijkstar Algorithm + Priority Queue (Minheap Concept) (Syntax in C++(for me)) + 

// CRUX :: Key Idea
// Find the shortest path from node 0 to node n-1, and count how many distinct paths achieve that shortest distance. Any path longer than the shortest doesn't count.

// Intuition
/*
Imagine you're in a city with roads. You want to reach the destination in minimum time. There might be multiple routes that all take the same minimum time — count all of them.
Two things to track simultaneously:

dist[v] → shortest distance found so far to reach v (sometimes there is time given instead of distance , or weight)
ways[v] → number of paths that achieve dist[v]

When you find a shorter path → you found a better route, reset the count.
When you find an equal path → another valid route exists, add to the count.
*/

// Approach 1 — Dijkstra + Path Count (Optimal)
// Idea: Run Dijkstra. Maintain a ways[] array alongside dist[]. Update ways when a shorter or equal path is found.


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Build adjacency list
        vector<vector<pair<long long, long long>>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        // Dijkstra
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long,long long>, 
                       vector<pair<long long,long long>>, 
                       greater<>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {distance, node}
        
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            
            if (d > dist[u]) continue; // stale entry
            
            for (auto [v, w] : adj[u]) {
                // Found a shorter path to v
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                // Found another path of equal length
                else if (dist[u] + w == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[n-1];
    }
};

- **TC:** O(E log V)
- **SC:** O(V + E)

// Approach II : Dijkstra + DP on Shortest Path DAG

/*
**Idea:** First run plain Dijkstra to get `dist[]` for all nodes. Then build a **DAG** (Directed Acyclic Graph) using only edges that lie on shortest paths. Finally, do a **topological sort + DP** on this DAG to count paths.

An edge `(u → v, w)` is on a shortest path DAG if:
```
dist[u] + w == dist[v]
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;

        vector<vector<pair<long long,long long>>> adj(n);
        for (auto& r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // Step 1: Dijkstra to get shortest distances
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,long long>,
                       vector<pair<long long,long long>>,
                       greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Step 2: Build DAG from shortest path edges
        vector<vector<int>> dag(n);
        vector<int> indegree(n, 0);
        for (auto& r : roads) {
            int u = r[0], v = r[1]; long long w = r[2];
            if (dist[u] + w == dist[v]) {
                dag[u].push_back(v);
                indegree[v]++;
            } else if (dist[v] + w == dist[u]) {
                dag[v].push_back(u);
                indegree[u]++;
            }
        }

        // Step 3: Topo sort (BFS/Kahn's) + DP
        vector<long long> ways(n, 0);
        ways[0] = 1;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : dag[u]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
                if (--indegree[v] == 0) q.push(v);
            }
        }

        return ways[n - 1];
    }
};

// TC: O(E log V) for Dijkstra + O(V + E) for topo sort = O(E log V)
// SC: O(V + E)
