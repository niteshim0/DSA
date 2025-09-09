// https://leetcode.com/problems/find-eventual-safe-states/description/

// Idea :: Any one who is part of cycle or leads to a cycle -> not a safe node.

// DFS Approach
class Solution {
public:
    bool isSafe(int node,vector<int>& vis,vector<int>& pathVis,vector<vector<int>>& graph){
        vis[node] = 1;
        pathVis[node] = 1;

        for(int adjNode : graph[node]){
            if(!vis[adjNode]){
                if(isSafe(adjNode,vis,pathVis,graph)){
                    return true;
                }
            }else if(pathVis[adjNode]){
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0) , pathVis(n,0);
        vector<int> ans;

        for(int i = 0;i<n;i++){
            if(!vis[i]){
               isSafe(i,vis,pathVis,graph);
            }
        }

        for(int i = 0;i<n;i++){
            if(!pathVis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// Time Complexity : O(V+E)
// Space Complexity : O(V)


// BFS Approach or Topological Sorting(Kahn's Algo)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adjRev[V];   // reversed graph
        vector<int> indegree(V,0);

        // Build reversed graph and indegree count
        for(int i = 0; i < V; i++){
            for(auto adjNode : graph[i]){
                adjRev[adjNode].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front(); q.pop();
            safeNodes.push_back(node);

            for(auto adjNode : adjRev[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

