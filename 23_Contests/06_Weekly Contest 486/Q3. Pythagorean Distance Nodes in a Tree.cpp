// Q3. Pythagorean Distance Nodes in a Tree
// https://leetcode.com/contest/weekly-contest-486/problems/pythagorean-distance-nodes-in-a-tree/description/

// Concept :: Adjacency List + N-ary tree + DFS + Depth of Tree + LCA of n-ary tree + binary lifting + distance b/w any two nodes of graph

// Approach :: 
// i) I will make a graph or n-ary tree(by using adjList)
// ii) calculate depth of each node from the root(say 0)
// iii) know also the parent of each node.
// iv) calculate lca (binary lifting + till the parents differ)
// v) calculate distance(since lca is in both minus it 2 times)
// vi) check for speciality of each node and cnt

// Solved During Contest :: Yes
// strikes : 2
// because multiplication goes out of bounds of int
// there was typo somewhere

class Solution {
public:
    static const int need = 20;
    vector<vector<long long>> parent;
    vector<long long> depth;
    vector<vector<long long>> adjList;
    long long distance(int u , int v){
        long long w = lca(u,v);
        return depth[u] + depth[v] - 2*depth[w];
    }
    long long lca(long long u,long long v){
        if(depth[u]<depth[v]) swap(u,v);
        for(int i = need-1;i>=0;i--){
            if(parent[i][u]!=-1 && depth[parent[i][u]]>=depth[v]){
                u = parent[i][u];
            }
        }

        if(u == v) return v;

        for(int i = need-1;i>=0;i--){
            if(parent[i][u]!=parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }

        return parent[0][u];
    }
    void dfs(int node, int par){
        parent[0][node] = par;
        for(int adjNode : adjList[node]){
            if(adjNode == par) continue;
            depth[adjNode] = depth[node] + 1;
            dfs(adjNode,node);
        }
    }
    bool isSpecial(long long a,long long b,long long c,int maxi){
        if(a == maxi){
            return (b*b + c*c == a*a);
        }else if(b == maxi){
            return (a*a + c*c == b*b);
        }else if(c == maxi){
            return (a*a + b*b == c*c);
        }
        return false;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int m = edges.size();
        adjList.assign(n+1,{});
        parent.assign(need,vector<long long>(n+1,-1));
        depth.assign(n+1,0);
        for(int i = 0;i<m;i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1);

        for(int k = 1;k<need;k++){
            for(int i = 0;i<n;i++){
                if(parent[k-1][i]!=-1){
                    parent[k][i]  = parent[k-1][parent[k-1][i]];
                }else{
                    parent[k][i] = -1;
                }
            }
        }

        long long cnt = 0;

        for(int i = 0;i<n;i++){
            long long a = distance(i,x);
            long long b = distance(i,y);
            long long c = distance(i,z);
            long long maxi = max({a,b,c});
            if(isSpecial(a,b,c,maxi)){
                cnt++;
            }
        }

        return cnt;
    }
};


// Time Complexity: O(n log n)
// Space Complexity: O(n log n)