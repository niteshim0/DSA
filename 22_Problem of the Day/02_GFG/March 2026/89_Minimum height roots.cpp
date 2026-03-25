// Minimum height roots
// https://www.geeksforgeeks.org/problems/minimum-height-roots/1

// Concepts :: BFS + Topological Sorting + Diameter of Tree

// Approach I :: Try every node in a bfs way , and choose the root which gives the minimal height

class Solution {
  public:
    int bfsHeight(int srcNode,vector<vector<int>>& adjList,int V){
        
        vector<bool> visited(V,false);
        queue<int> q;
        
        q.push(srcNode);
        visited[srcNode] = true;
        
        int height = -1;
        
        while(!q.empty()){
            
            int size = q.size();
            height++;
            
            while(size--){
                
                int node = q.front();
                q.pop();
                
                for(int adjNode : adjList[node]){
                    
                    if(!visited[adjNode]){
                        
                        q.push(adjNode);
                        visited[adjNode] = true;
                    }
                }
            }
        }
        
        return height;
    }
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
       
       vector<vector<int>> adjList(V);
       
       for(auto& edge : edges){
           
           adjList[edge[0]].push_back(edge[1]);
           adjList[edge[1]].push_back(edge[0]);
       }
       
       vector<int> ans;
       
       int mini = 1e6;
       
       for(int node = 0; node < V ; node++){
           
           int height = bfsHeight(node,adjList,V);
           
           if(height < mini){
               
               ans.clear();
               ans.push_back(node);
               mini = height;
               
           }else if(height == mini){
               
               ans.push_back(node);
           }
       }
       
       return ans;
        
    }
};

// | Complexity           | Value                                   |
// | -------------------- | --------------------------------------- |
// | **Time Complexity**  | `O(V * (V + E))` → **O(V²)** (for tree) |
// | **Space Complexity** | `O(V + E)` → **O(V)**                   |


// Approach II :: Use Graph Theory + Topological Sort

/*
🔥 Why does “leaf removal” give MHT roots?
🧠 Core Intuition (very important)

A tree’s height depends on its farthest node (leaf).

👉 If you choose a root near the edges, height is large
👉 If you choose a root near the center, height is minimum

🌳 Key Observation
Leaves (degree = 1) are always the farthest nodes
They can never be part of an optimal root (MHT)

👉 So we safely remove them

🔁 What happens when we remove leaves?

Think of it like:

“Peeling an onion layer by layer”

First remove outermost nodes (leaves)
New leaves appear
Keep removing…

👉 Eventually, only the center remains

🎯 Final Remaining Nodes
When process stops:
1 node left → single centroid
2 nodes left → two centroids

👉 These are exactly the Minimum Height Tree roots

📌 Deep Reason (Graph Theory Insight)
Tree has a diameter (longest path)
MHT roots lie at the middle of this diameter

Now what leaf removal does:

Removes nodes from both ends of diameter simultaneously
Gradually shrinks the diameter
Stops at the middle

👉 That middle = centroid(s)

🔍 Example (Visual Thinking)
    0
    |
    1
   / \
  2   3
       \
        4
Step 1: Leaves → {0,2,4}

Remove them

Step 2: New leaves → {1,3}

Remove them

Step 3: Remaining → {1 or 3 depending structure}

👉 Center found

⚡ Why this is efficient

Instead of:

Trying every node (your BFS approach ❌)

We:

Remove useless nodes (leaves) in layers

👉 Each node is processed once

🧠 One-line intuition (interview ready)

“MHT roots are the middle of the tree’s diameter, and removing leaves layer by layer converges to that center.”
*/


class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
       
       vector<vector<int>> adjList(V);
       vector<int> degree(V,0);
       
       for(auto& edge : edges){
           
           int u = edge[0], v = edge[1];
           adjList[u].push_back(v);
           adjList[v].push_back(u);
           degree[u]++;
           degree[v]++;
       }
       
       queue<int> q;
       vector<int> ans;
       
       for(int node = 0; node < V ; node++){
           
           if(degree[node] == 1) q.push(node);
       }
       
       
       int centroids = V;
       
       while( centroids > 2){
           
           int size = q.size();
           centroids-=size;
           
           while(size--){
               
               int node = q.front();
               q.pop();
               
               for(int adjNode : adjList[node]){
                   
                   degree[adjNode]--;
                   if(degree[adjNode] == 1){
                       q.push(adjNode);
                   }
               }
           }
       }
       
       while(!q.empty()){
           
           ans.push_back(q.front());
           q.pop();
       }
       
       return ans;
    }
       
};

// | Complexity           | Value                                   |
// | -------------------- | --------------------------------------- |
// | **Time Complexity**  | `O(V+E) |
// | **Space Complexity** | `O(V + E)` → **O(V)**                   |


// Approach III :: Tree Diameter Method

/*
🧠 Core Idea

Minimum Height Tree root = middle of the longest path (diameter)

Why?

Height of a tree = distance to the farthest node
To minimize height → choose node closest to all extremes
That happens at the center of the diameter
🌳 What is Diameter?

The longest path between any two nodes in a tree

Let endpoints be:

A ----------- B   (longest path)

👉 Answer = middle node(s) of A → B

🚀 Steps Breakdown
✅ Step 1: Find farthest node from any node (say 0)
BFS from 0 → get A

👉 Why works?

In a tree, BFS from any node always ends at one end of diameter
✅ Step 2: Find farthest node from A
BFS from A → get B

👉 Now:

A → B = diameter path
✅ Step 3: Reconstruct path (A → B)

Using parent[]:

while (B != -1) {
    path.push_back(B);
    B = parent[B];
}

👉 This gives full diameter path

✅ Step 4: Find middle
if (n % 2 == 1)
    return {path[n/2]};
else
    return {path[n/2 - 1], path[n/2]};
Odd length → 1 center
Even length → 2 centers
🔍 Why this works (Deep Intuition)

Imagine the tree stretched like a rope:

A ----------- B
Ends = worst possible roots ❌
Moving toward center → height decreases
Best point = middle

👉 That’s where max distance to both ends is minimized

⚡ Key Insight (Interview Line)

“The root that minimizes height lies at the center of the tree’s diameter.”
*/

class Solution {
public:

    // BFS to find farthest node + parent tracking
    pair<int, vector<int>> bfs(int src, vector<vector<int>>& adj, int V) {
        vector<bool> vis(V, false);
        vector<int> parent(V, -1);
        queue<int> q;

        q.push(src);
        vis[src] = true;

        int farthest = src;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            farthest = node;

            for (int nbr : adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }

        return {farthest, parent};
    }

    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {

        if (V == 1) return {0};

        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 1: BFS from 0 → get A
        auto [A, _] = bfs(0, adj, V);

        // Step 2: BFS from A → get B + parent
        auto [B, parent] = bfs(A, adj, V);

        // Step 3: Build diameter path (A → B)
        vector<int> path;
        while (B != -1) {
            path.push_back(B);
            B = parent[B];
        }

        int n = path.size();

        // Step 4: Return middle node(s)
        if (n % 2 == 1)
            return {path[n / 2]};
        else
            return {path[n / 2 - 1], path[n / 2]};
    }
};

// | Complexity           | Value                                   |
// | -------------------- | --------------------------------------- |
// | **Time Complexity**  | `O(V+E) | // two times bfs build
// | **Space Complexity** | `O(V + E)` → **O(V)** // for creating adjacency List                   |

