// LC 3650. Minimum Cost Path with Edge Reversals
// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description
// Concept :: Adjacency List + Vector of Pairs  + Graph Theory + Dijkstra Algorithm
/*
Dijkstra's algorithm is a fundamental algorithm in graph theory used to find the shortest paths from a single source node to all other nodes in a weighted graph with non-negative edge weights.  It was conceived by Dutch computer scientist Edsger W. Dijkstra in 1956 and published in 1959. 
*/

// Approach :: For each node , keep the given graph intact as well as reversal version by increasing edgeweights.
// now apply dijkstra on this generated graph.
// if we are finding the end , well and good return the ans.

class Solution {
public:
    vector<long long> dijkstra(int V, vector<vector<pair<int,long long>>> &adj, int S) {
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(V, LLONG_MAX);
        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto &it : adj[node]) {
                int v = it.first;
                long long wt = it.second;

                if (dis + wt < dist[v]) {
                    dist[v] = dis + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,long long>>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            long long w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2LL * w});
        }

        vector<long long> dist = dijkstra(n, adj, 0);
        return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
    }
};
// Time Complexity: O((V + E) log V)
// Space: O(V + E)
