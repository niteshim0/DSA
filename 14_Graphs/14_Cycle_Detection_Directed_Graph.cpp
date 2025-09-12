//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Idea :: on the same path node has to be visited again
// In a directed graph, a cycle means there’s a path from a node back to itself.
// The moment we encounter a node that’s still in the current DFS call stack, it means we’ve looped back → cycle found.

// DFS Approach

class Solution {
  public:
    bool dfsCycleCheck(int node,vector<int> adj[],vector<int>&vis,vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfsCycleCheck(adjNode,adj,vis,pathVis)){
                    return true;
                }
            }else if(pathVis[adjNode]){
                return  true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
       vector<int> adj[V+1];
       for(vector<int>& edge : edges){
           adj[edge[0]].push_back(edge[1]);
       }
       vector<int> vis(V,0)  , pathVis(V,0);
       
       for(int i = 0;i<V;i++){
           if(!vis[i]){
               if(dfsCycleCheck(i,adj,vis,pathVis)){
                   return true;
               }
           }
       }
       return false;
    }
};

// Complexity
// Time: O(V + E) → DFS visits all vertices and edges once.
// Space: O(V) for vis, pathVis, and recursion stack.

// BFS Approach or Topological Sorting(Kahn's Algo)
// if there is cycle one can't get any Topological Order

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
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
       
       int cnt = 0;
       while(!q.empty()){
           int node = q.front(); q.pop();
           cnt++;
           
           for(auto adjNode : adj[node]){
               indegree[adjNode]--;
               if(indegree[adjNode] == 0) q.push(adjNode);
           }
       }
       
       return cnt!=V;
    }
};