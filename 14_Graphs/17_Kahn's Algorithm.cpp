//  https://www.geeksforgeeks.org/problems/topological-sort/1

// BFS Based Topo Sort
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for(vector<int>& edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> indegree(V,0);
        
       for(int i = 0;i<V;i++){
           for(auto adjNode : adj[i]){
               indegree[adjNode]++;
           }
       }
       
       queue<int> q;
       for(int i = 0;i<V;i++){
           if(indegree[i] == 0) q.push(i);
       }
       
       vector<int> topo;
       while(!q.empty()){
           int node = q.front(); q.pop();
           topo.push_back(node);
           
           for(auto adjNode : adj[node]){
               indegree[adjNode]--;
               if(indegree[adjNode] == 0) q.push(adjNode);
           }
       }
       
       return topo;
    }
};

// 🔹 Complexity
// Time Complexity: O(V + E)
// Building adjacency list: O(E)
// Calculating indegree: O(V + E)
// BFS traversal: O(V + E)
// Overall: O(V + E)

// Space Complexity: O(V + E)
// Adjacency list → O(V + E)
// Indegree array → O(V)
// Queue → O(V)
// Result vector → O(V)