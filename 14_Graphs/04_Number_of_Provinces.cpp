// BFS Approach
class Solution {
public:
    void bfs(int node, vector<int>& vis, vector<vector<int>>& isConnected) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int node = q.front();q.pop();
            for(int i = 0;i<isConnected.size();i++){
                if(isConnected[node][i] == 1 && !vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(i, vis, isConnected);
            }
        }
        return cnt;
    }
};
// Time Complexity : O(N*N)
// Space Complexity : O(N*N)

// DFS Approach
class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected) {
        vis[node] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !vis[j]) {
                dfs(j, vis, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, isConnected);
            }
        }
        return cnt;
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(N*N)

// Since graph is already represented in terms of ajacency matrix , so such time complexity , if represented in terms of adjacency list , much better complexity we will have

// BFS with ajacency list
class Solution {
public:
    void bfs(int start, vector<int>& vis, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
    }

    int countComponents(vector<vector<int>>& adj, int n) {
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(i, vis, adj);
            }
        }
        return cnt;
    }
};
// Time Complexity : O(N + E)
// Space Complexity : O(N+E)//bfs approach + O(N) // queue + O(N) // visited array

// DFS With Ajacency List
class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, vis, adj);
            }
        }
    }

    int countComponents(vector<vector<int>>& adj, int n) {
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};

// Time Complexity : O(N + E)
// Space Complexity : O(N+E)//bfs approach + O(N) // auxiliary recursion stack space + O(N) // visited array