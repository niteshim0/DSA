# 2492. Minimum Score of a Path Between Two Cities
[LC 2492.Minimum Score of a Path Between Two Cities](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/)
## First-Principles Thinking + Problem Categorization

## 1. Read the Problem Carefully

We are given:

-   An undirected weighted graph.
-   We need a path from **city 1** to **city n**.

The score of a path is **not** the sum of edge weights.

Instead,

``` text
score(path) = minimum edge weight on that path
```

Example:

``` text
1 --8-- 2 --5-- 3 --10-- 4

score = min(8,5,10) = 5
```

Our goal is to **minimize this score**.

------------------------------------------------------------------------

## 2. Identify the Optimization Objective

Ask:

> What affects the score?

Only the **smallest edge** encountered on the path.

The total distance, number of edges, and path length do not matter.

This immediately tells us:

-   ❌ Not a shortest path problem.
-   ❌ Dijkstra is not the natural solution.

------------------------------------------------------------------------

## 3. Read Every Constraint

The crucial sentence is:

> A path is allowed to contain the same road multiple times.

This changes the entire problem.

Normally, graph path problems assume a simple path.

Here we may revisit:

-   cities
-   roads

Example:

``` text
1 → 2 → 3 → 2 → 1
```

This is perfectly valid.

------------------------------------------------------------------------

## 4. Consequence of Revisiting

Suppose:

``` text
1 --9-- 2 --8-- 3 --7-- 4

            |
            1
            |
            5
```

Need a path from 1 to 4.

We can travel

``` text
1 → 2 → 5 → 2 → 3 → 4
```

The score becomes

``` text
min(9,1,1,8,7)=1
```

Although city 5 is unnecessary for reaching 4, we purposely visit it
because it contains a smaller edge.

------------------------------------------------------------------------

## 5. General Observation

Since revisiting is allowed:

-   we can go anywhere inside the connected component,
-   include any edge,
-   return,
-   continue toward the destination.

Therefore,

> Every edge inside the connected component containing city 1 can appear
> in a valid path from 1 to n.

------------------------------------------------------------------------

## 6. Final Insight

The answer is simply:

``` text
Minimum edge weight in the connected component containing city 1.
```

------------------------------------------------------------------------

## 7. Algorithm

1.  Build the adjacency list.
2.  Run BFS (or DFS) from city 1.
3.  Traverse the entire connected component.
4.  While visiting every edge:

``` cpp
answer = min(answer, edgeWeight);
```

5.  Return the answer.

------------------------------------------------------------------------

## 8. Why Not Stop at City n?

Suppose:

``` text
1 --10-- 2 --10-- 5

          |
          1
          |
          8
```

We can travel

``` text
1 → 2 → 8 → 2 → 5
```

The answer becomes 1.

Therefore we must explore the **entire connected component**, not just
until reaching city n.

------------------------------------------------------------------------

# Problem Categorization

## What This Problem Looks Like

At first glance:

-   Weighted Graph
-   Path Problem

Many people think:

-   Dijkstra
-   Shortest Path

That is incorrect.

------------------------------------------------------------------------

## Actual Category

This is a:

> Connected Component + Graph Traversal problem.

The edge weights are only used to maintain the minimum value while
traversing.

------------------------------------------------------------------------

## Key Concepts Revised

-   Graph Representation (Adjacency List)
-   BFS
-   DFS
-   Connected Components
-   Graph Traversal
-   DSU (alternative solution)
-   Reading Constraints Carefully
-   Objective Function Recognition

------------------------------------------------------------------------

## Pattern Recognition

Whenever solving graph problems, ask:

1.  What is being optimized?
2.  Can I revisit nodes or edges?
3.  Does revisiting simplify the problem?
4.  Is this actually a path problem, or just a connected component
    problem?

------------------------------------------------------------------------

## Complexity

Building graph:

``` text
O(E)
```

Traversal:

``` text
O(V + E)
```

Overall:

``` text
Time  : O(V + E)
Space : O(V + E)
```

------------------------------------------------------------------------

## Mental Model

The key realization is:

> Because roads and cities can be revisited, every edge inside the
> connected component containing city 1 is usable.

Therefore the answer is simply the minimum edge in that connected
component.

## Solution 1 :: Connected Component + BFS

``` cpp
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
```

# DSU Solution for LeetCode 2492 - Minimum Score of a Path Between Two Cities

## First Principles

The key insight is:

> The answer is the **minimum edge weight in the connected component
> containing city 1**.

A Disjoint Set Union (DSU) data structure is perfect when the only
question is:

-   Are two nodes in the same connected component?

It supports:

-   **find(x)** → Returns the representative (parent) of x's component.
-   **union(u, v)** → Merges the components containing u and v.

------------------------------------------------------------------------

## Step 1: Build Connected Components

Initially every city is its own component.

``` text
1   2   3   4   5
```

For every road `(u, v)`:

``` cpp
dsu.unite(u, v);
```

After processing all roads, each connected component has one
representative.

------------------------------------------------------------------------

## Step 2: Find City 1's Component

``` cpp
int parent = dsu.find(1);
```

Now `parent` identifies the connected component containing city `1`.

------------------------------------------------------------------------

## Step 3: Scan Every Road

For each road:

``` cpp
if (dsu.find(u) == parent)
    ans = min(ans, weight);
```

Why is checking only one endpoint enough?

Because every road was already unioned.

If `u` belongs to city 1's component, then `v` must belong to the same
component.

------------------------------------------------------------------------

## Example

Roads:

``` text
1 --9-- 2
2 --6-- 3
2 --5-- 4
```

After unions:

``` text
      2
    / | \
   1  3  4
```

Representative:

``` text
find(1) = find(2) = find(3) = find(4)
```

Scanning edges:

``` text
1-2 (9) → answer = 9
2-3 (6) → answer = 6
2-4 (5) → answer = 5
```

Return:

``` text
5
```

------------------------------------------------------------------------

## Complete Code

``` cpp
class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }

        int find(int node) {
            if (parent[node] == node)
                return node;

            return parent[node] = find(parent[node]);
        }

        void unite(int u, int v) {
            u = find(u);
            v = find(v);

            if (u == v) return;

            if (size[u] < size[v])
                swap(u, v);

            parent[v] = u;
            size[u] += size[v];
        }
    };

    int minScore(int n, vector<vector<int>>& roads) {

        DSU dsu(n);

        for (auto &road : roads)
            dsu.unite(road[0], road[1]);

        int parent = dsu.find(1);
        int ans = INT_MAX;

        for (auto &road : roads) {
            if (dsu.find(road[0]) == parent)
                ans = min(ans, road[2]);
        }

        return ans;
    }
};
```

------------------------------------------------------------------------

## Complexity

  Operation         Complexity
  ----------------- ------------------------
  Union all edges   O(E · α(N))
  Scan all edges    O(E · α(N))
  Total             **O(E · α(N)) ≈ O(E)**
  Space             **O(N)**

------------------------------------------------------------------------

## When Should You Think of DSU?

Choose DSU when the problem involves:

-   Connected components
-   Dynamic connectivity
-   Merge operations
-   "Are these nodes connected?"
-   Kruskal's MST
-   Redundant connections
-   Accounts Merge

**Rule of thumb:**

-   Need to **traverse** a component → BFS / DFS.
-   Need to **identify or merge** components → DSU.

