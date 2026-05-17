// LC 1306. Jump Game III
// https://leetcode.com/problems/jump-game-iii/description/

// Concepts :: DFS / BFS / Recursion

// Key Idea :: Model the array as graph and apply BFS or DFS to find the target index.

// Approach I : Explicit Modelling as Adjacency List + BFS

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        vector<vector<int>> adjList(n);

        for(int i = 0; i < n; i++){

            int first = i + arr[i];
            int second = i - arr[i];

            if(first < n)
                adjList[i].push_back(first);

            if(second >= 0)
                adjList[i].push_back(second);
        }

        queue<int> q;
        vector<bool> visited(n,false);

        q.push(start);
        visited[start] = true;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            if(arr[node] == 0)
                return true;

            for(int adjNode : adjList[node]){

                if(!visited[adjNode]){
                    visited[adjNode] = true;
                    q.push(adjNode);
                }
            }
        }

        return false;
    }
};

// Time Complexity : O(N + Edges)
// Space Complexity : O(N)


// Approach II :: Implicit Modelling of Graph + BFS

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        queue<int> q;
        vector<bool> vis(n,false);

        q.push(start);
        vis[start]=true;

        while(!q.empty()){

            int i=q.front();
            q.pop();

            if(arr[i]==0)
                return true;

            int next1=i+arr[i];
            int next2=i-arr[i];

            if(next1<n && !vis[next1]){
                vis[next1]=true;
                q.push(next1);
            }

            if(next2>=0 && !vis[next2]){
                vis[next2]=true;
                q.push(next2);
            }
        }

        return false;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)


// Approach III : DFS

class Solution {
public:

    bool dfs(vector<int>& arr, int i, vector<bool>& vis){

        int n = arr.size();

        if(i < 0 || i >= n || vis[i])
            return false;

        if(arr[i] == 0)
            return true;

        vis[i] = true;

        return dfs(arr, i + arr[i], vis) ||
               dfs(arr, i - arr[i], vis);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<bool> vis(arr.size(), false);

        return dfs(arr, start, vis);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)