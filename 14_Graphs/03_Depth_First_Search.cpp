class Solution {
  public:
    void dfs(int node,int vis[],vector<vector<int>>& adj,vector<int>& dfss){
        dfss.push_back(node);
        vis[node] = 1;
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode,vis,adj,dfss);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        int vis[n+1] = {0};
        vector<int> dfss;
        dfs(0,vis,adj,dfss);
        return dfss;
    }
};
// Time Complexity : O(N) + O(2E)
// Space Complexity : O(3N)