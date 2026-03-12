// LC 3600. Maximize Spanning Tree Stability with Upgrades
// https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/description/

// Concepts 
/*
Graph Theory : Spanning Tree + Cycle detection + Connectivity
Data Structure : Union Find / Disjoint Set Union (DSU)
Algorithms : Greedy + Binary Search on Answer
*/

// Observations
/*
-> Observation 1
If stability = X
Every edge in the tree must satisfy : strength ≥ X

-> Observation 2
Optional edges can be upgraded:
s → 2s
So an optional edge can satisfy X if:
s ≥ X          (no upgrade)
or
2s ≥ X         (upgrade)

-> Observation 3
Mandatory edges : must = 1
must be included cannot be upgraded
must satisfy : s ≥ X
Otherwise impossible.

-> Observation 4

If mandatory edges form a cycle
Then spanning tree is impossible.

Example:
3 nodes
3 mandatory edges

Cycle already exists.
*/

// Key Idea

/*
Instead of directly constructing the tree:

We guess the stability.
Is it possible to build a spanning tree
where every edge strength ≥ X ?
This becomes a YES / NO problem.

When we have a YES/NO property like this we use : Binary Search on Answer
*/

// 6. Feasibility Check (Core Logic)

// For a candidate stability X:

// We try to build a spanning tree.

// Steps:

// Step 1 — Use mandatory edges

// For each edge:

// if must == 1

// Check:

// if s < X → impossible

// Add to DSU.

// If union fails → cycle → return false.

// Step 2 — Use optional edges without upgrade

// Edges satisfying:

// s ≥ X

// Add them normally.

// Step 3 — Use optional edges with upgrade

// Edges satisfying:

// s < X ≤ 2s

// These require an upgrade.

// But we can use only k upgrades.

// Step 4 — Check spanning tree

// We must have:

// edges_used = n - 1
// 7. Why We Process Edges in Two Passes

// If we use upgrade edges too early, we waste upgrades.

// Example:

// upgrade edge
// later we find strong edge

// Better strategy:

// 1. mandatory edges
// 2. strong edges
// 3. upgrade edges

// This minimizes upgrades.

// Approach
/*
Binary Search stability X

For each X
    Try to build spanning tree

    Use mandatory edges
    Use strong optional edges
    Use upgrade edges

    If spanning tree formed
        X is possible
    else
        X is impossible
*/

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return false;

        if(rank[a]<rank[b])
            swap(a,b);

        parent[b]=a;

        if(rank[a]==rank[b])
            rank[a]++;

        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, int mid){

        DSU dsu(n);
        int upgrades=0;
        int used=0;

        // mandatory edges
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must){
                if(s<mid) return false;

                if(!dsu.unite(u,v))
                    return false;

                used++;
            }
        }

        // optional edges without upgrade
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must) continue;

            if(s>=mid && dsu.unite(u,v))
                used++;
        }

        // optional edges with upgrade
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must) continue;

            if(s<mid && 2*s>=mid){
                if(dsu.find(u)!=dsu.find(v)){

                    upgrades++;

                    if(upgrades>k)
                        return false;

                    dsu.unite(u,v);
                    used++;
                }
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo=1, hi=200000;
        int ans=-1;

        while(lo<=hi){

            int mid=(lo+hi)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }

        return ans;
    }
};
// Time Complexity = O(m log S) where S = max strength
// Space Complexity : O(n)