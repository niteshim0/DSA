// Adjacency Matrix and Adjacency List Representations

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // -------------------------------
    // 1. Adjacency Matrix (Unweighted)
    // -------------------------------
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // directed
        adj[v][u] = 1; // undirected -> include this
    }
    // Space Complexity: O(N^2)

    // -------------------------------
    // 2. Adjacency List (Unweighted)
    // -------------------------------
    vector<int> adjList[n + 1]; // array of vectors

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // directed
        adjList[v].push_back(u); // undirected -> include this
    }
    // Time Complexity: O(2E) for undirected, O(E) for directed

    // -------------------------------
    // 3. Adjacency Matrix (Weighted)
    // -------------------------------
    vector<vector<int>> adjWt(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adjWt[u][v] = wt; // directed
        adjWt[v][u] = wt; // undirected -> include this
    }

    // -------------------------------
    // 4. Adjacency List (Weighted)
    // -------------------------------
    vector<pair<int, int>> adjWtList[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adjWtList[u].push_back({v, wt}); // directed
        adjWtList[v].push_back({u, wt}); // undirected -> include this
    }

    return 0;
}
