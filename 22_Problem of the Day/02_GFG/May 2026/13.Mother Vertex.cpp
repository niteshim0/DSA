// Mother Vertex
// https://www.geeksforgeeks.org/problems/mother-vertex/1


// Concepts :: DFS + Kosaraju observation

class Solution {
public:

    void dfs(int node, vector<int> adj[], vector<bool>& vis) {

        vis[node] = true;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> vis(V, false);

        int candidate = 0;

        // Step 1: Find candidate
        for (int i = 0; i < V; i++) {

            if (!vis[i]) {
                dfs(i, adj, vis);
                candidate = i;
            }
        }

        // Step 2: Verify candidate
        fill(vis.begin(), vis.end(), false);

        dfs(candidate, adj, vis);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) return -1;
        }

        return candidate;
    }
};

// Time Complexity : O(V + E)
// Space Complexity : O(V)


/*
Problem

Find a vertex from which all vertices are reachable.

That vertex is called a mother vertex.

First Think Brute Force

Your code does:

For every node:
    Run DFS
    Check if all visited

Perfectly valid.

But expensive.

Now the Main Question

Why can we find candidate using ONLY one traversal?

This is the real magic.

Think About DFS Carefully

Suppose graph:

0 → 1 → 2

3 → 0

Who is mother vertex?

Obviously 3.

Because:

3 → 0 → 1 → 2

Now simulate DFS loop.

Step 1

Start DFS from 0

Visited:

0 1 2

But 3 still unvisited.

Important observation:

0 failed to reach 3

Therefore:

0 can NEVER be mother vertex

Very important.

Now loop continues.

Step 2

Node 1 already visited.

Skip.

Step 3

Node 2 already visited.

Skip.

Step 4

Node 3 unvisited.

Now DFS starts from 3.

Visits:

3 0 1 2

Now all covered.

Why Did We Save 3 as Candidate?

Because:

All previous DFS roots already failed.

Only latest root still has a chance.

This Is the Entire Logic

Whenever DFS finishes and still some nodes remain unvisited:

current start node is disqualified

because it couldn't reach remaining nodes.

Then we try another node.

Eventually:

the LAST DFS root becomes the only surviving candidate
Think Like Elimination

Imagine election elimination.

Initially:

All nodes can be mother vertex

Now DFS from 0 misses some nodes.

So:

remove 0

Later DFS from 5 misses some nodes.

So:

remove 5

Eventually only one possible candidate survives.

That is:

last DFS starting node
VERY IMPORTANT PROPERTY

Suppose DFS starts from A
and later another DFS starts from B.

That means:

A could NOT reach B

Correct?

Otherwise B would've already been visited.

So:

A is automatically disqualified

This is THE theorem behind solution.

Why Last DFS Root Works

Suppose actual mother vertex exists.

Call it M.

Then:

M can reach EVERY node

including every DFS tree.

Therefore:

either DFS started from M
OR some DFS before it reached M

But if some earlier DFS reached M,
then that DFS would eventually visit whole graph too.

So if mother vertex exists,
the final surviving DFS root becomes that mother region.

Another Example

Graph:

0 → 1
1 → 2
4 → 0
4 → 5
5 → 6
6 → 2

Mother vertex?

Looks like 4.

Simulation
i = 0

DFS visits:

0 1 2

Unvisited:

4 5 6

So:

0 is rejected
i = 1

already visited.

i = 2

already visited.

i = 3

Suppose isolated.

DFS only visits 3.

Now candidate = 3.

But:

3 cannot reach others

So maybe not mother.

i = 4

DFS visits:

4 0 1 2 5 6

Now candidate = 4.

End.

Now verification DFS from 4.

If all visited:

yes mother exists

Else:

no mother vertex
Why Verification Is Mandatory

Consider:

0 → 1

2 → 3

No mother vertex exists.

Simulation:

DFS from 0 visits 0,1
DFS from 2 visits 2,3

Candidate becomes 2.

But:

2 cannot reach 0 or 1

So candidate is not guaranteed.

Only POSSIBLE.

Hence second DFS needed.

Full Intuition in One Sentence

The last DFS root is special because:

Every previous DFS root failed to reach something discovered later.

Hence only last root can still possibly reach all nodes.
*/