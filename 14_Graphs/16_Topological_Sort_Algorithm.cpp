// https://www.geeksforgeeks.org/problems/topological-sort/1

// Linear Ordering of Vertices such that if there is an edge between u and v , u appears before v in the ordering.

class Solution {
  public:
    void dfs(int node,vector<int> adj[],vector<int>& vis,stack<int>& st){
        vis[node] = 1;
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for(vector<int>& edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        stack<int> st;
        vector<int> vis(V,0);
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};


// Complexity:
// Time: O(V + E) → we visit each vertex and edge exactly once.
// Space:
// Adjacency list → O(V + E)
// Visited array → O(V)
// Recursion stack → O(V)
// Stack for result → O(V)
// Overall → O(V + E)