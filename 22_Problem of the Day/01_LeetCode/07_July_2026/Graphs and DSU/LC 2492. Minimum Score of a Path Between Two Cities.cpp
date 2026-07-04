// 4th July 2026

// Solution 1 :: Connected Components + BFS

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        int minScore = INT_MAX;
        
        int m = roads.size();
        vector<vector<pair<int,int>>> adjList(n+1);

        for(auto& road : roads){

            int u = road[0];
            int v = road[1];
            int dist = road[2];

            adjList[u].push_back({v,dist});
            adjList[v].push_back({u,dist});
        }


        queue<int> q;
        vector<bool> visited(n+1,false);
        q.push(1);
        visited[1] = 1;


        while(!q.empty()){
             
            int node = q.front();
                       q.pop();
            
            for(auto& [adjNode,dist] : adjList[node]){

                minScore = min(minScore,dist);

                if(!visited[adjNode]){
                    q.push(adjNode);
                    visited[adjNode] = true;
                }
            }
        }

        return minScore;
    }
};

// Time Complexity : O(E + V)
// Space Complexity : O(E + V)

// Solution 2 : Connected Components + DSU

class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {

            parent.resize(n + 1, 0);
            size.resize(n + 1, 0);

            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int node) {

            if (parent[node] == node) {
                return node;
            }

            return parent[node] = find(parent[node]);
        }

        void unite(int u, int v) {

            u = find(u);
            v = find(v);

            if (size[u] < size[v]) {
                swap(u, v);
            }

            parent[v] = u;
            size[u] += size[v];
        }
    };
    int minScore(int n, vector<vector<int>>& roads) {

        DSU dsu(n);

        for (auto& road : roads) {

            dsu.unite(road[0], road[1]);
        }

        int parent = dsu.find(1);
        int minScore = INT_MAX;

        for (auto& road : roads) {

            if (dsu.find(road[0]) == parent) {

                minScore = min(minScore, road[2]);
            }
        }

        return minScore;
    }
};

// Time Complexity : O(E · α(N)) // Union + O(E · α(N)) // Scan ~ O(E) // inverse Ackermann Function
// Space Complexity : O(N)