// Minimum Multiplications to Reach End
// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1


// Concepts :: Shortes Path + BFS + Dijkstra + Distance Array + Graph on Array Implicit + Implicit Graph / State Space Graph


// Key Idea :: Since we want to know minimum steps -> simply apply BFS to go level by level.

class Solution {
  public:
    const int MOD = 1000;
    int minSteps(vector<int>& arr, int start, int end) {
        
        // Minimum -> BFS it indicates
        
        queue<int> q;
        vector<int> visited(1000,-1);
        
        q.push(start);
        visited[start] = 1;
        
        
        int steps = 0;
        
        
        while(!q.empty()){
            
            int levelSize = q.size();
            
            while(levelSize--){
                
                int node = q.front();
                q.pop();
                
                if(node == end) return steps;
                
                for(int x : arr){
                    
                    int res = (node *1ll* x) % MOD;
                    
                    if(visited[res] == -1){
                        q.push(res);
                        visited[res] = 1;
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

// NOTES TO REMEMBER

/*
=============================================
MINIMUM MULTIPLICATIONS TO REACH END
=============================================

Problem:
Start from "start"
For every step:

next = (current * arr[i]) % 1000

Find minimum steps to reach end.

---------------------------------------------
WHY BFS?
---------------------------------------------

Keywords:

1. Minimum steps
2. Minimum operations
3. Minimum moves
4. Least transformations

All operations cost same (=1)

Whenever:
minimum + equal cost edges

=> THINK BFS

Reason:
BFS explores level by level.

Level 0 -> distance 0
Level 1 -> distance 1
Level 2 -> distance 2

First time reaching destination
= shortest path guaranteed

---------------------------------------------
GRAPH INTERPRETATION
---------------------------------------------

No graph is explicitly given.

We create graph dynamically.

Node:

current value

Edge:

current ----> (current*x)%1000

This is called:

Implicit Graph / State Space Graph

Examples of states:

1. Number
2. String
3. Matrix cell
4. Index
5. Bitmask

---------------------------------------------
STATE TRANSITION
---------------------------------------------

for(int x:arr){

    next=(node*x)%1000;
}

Generate neighbors dynamically.

No adjacency list required.

---------------------------------------------
IMPORTANT OBSERVATION
---------------------------------------------

(node*x)%1000

Range:

0 -> 999

Only 1000 possible states exist.

Therefore:

vector<int> visited(1000);

is better than:

unordered_map<int,int>

Array:
O(1)

Hash map:
average O(1)
extra overhead

---------------------------------------------
STANDARD BFS TEMPLATE
---------------------------------------------

queue<int> q;

vector<int> visited(MAX,0);

q.push(start);

visited[start]=1;

steps=0;

while(!q.empty()){

    int level=q.size();

    while(level--){

        int node=q.front();
        q.pop();

        if(node==end)
            return steps;

        for(neighbor){

            if(!visited[next]){

                visited[next]=1;

                q.push(next);
            }
        }
    }

    steps++;
}

---------------------------------------------
BETTER BFS USING DISTANCE ARRAY
---------------------------------------------

vector<int> dist(MAX,1e9);

dist[start]=0;

queue<int> q;

q.push(start);

while(!q.empty()){

    int node=q.front();

    q.pop();

    for(neighbor){

        if(dist[node]+1<dist[next]){

            dist[next]=dist[node]+1;

            q.push(next);
        }
    }
}

Reason:

distance array stores:

minimum steps to each node

Advantage:

No separate level counting needed

---------------------------------------------
TIME COMPLEXITY
---------------------------------------------

Total nodes:

1000

For each node:

iterate over arr

Time:

O(1000*N)

Space:

O(1000)

---------------------------------------------
RELATED CONCEPTS
---------------------------------------------

1) BFS on implicit graph

2) State space search

3) Modulo compression

4) Level order traversal

5) Neighbor generation

6) Shortest path in unweighted graph

---------------------------------------------
TYPES OF BFS
---------------------------------------------

1. NORMAL BFS

Use:

Equal edge cost

Examples:

Word ladder
Open lock
Jump Game IV

Complexity:

O(V+E)

---------------------------------------------

2. MULTI SOURCE BFS

Start from multiple nodes

Example:

for(auto x:sources){

    q.push(x);

    dist[x]=0;
}

Questions:

Rotting Oranges
01 Matrix
Walls and Gates

---------------------------------------------

3. BIDIRECTIONAL BFS

Search from:

start -> end

and

end -> start

Useful:

Huge search space

Complexity:

Normal:

O(b^d)

Bidirectional:

O(b^(d/2))

Questions:

Word Ladder
Open Lock

---------------------------------------------

4. 0-1 BFS

Edge cost:

0 or 1

Use deque

deque<int> dq;

if(weight==0)
    dq.push_front(node);

else
    dq.push_back(node);

Complexity:

O(V+E)

Questions:

Minimum cost path
Reverse edge problem

---------------------------------------------

5. DIJKSTRA

Use when:

weights:

1,2,5,10...

priority_queue<
pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>
>pq;

Questions:

Network Delay Time
Cheapest Flights
Path with minimum effort

---------------------------------------------
TOP INTERVIEW QUESTIONS
---------------------------------------------

BFS ON STATE SPACE:

1. Open Lock
2. Word Ladder
3. Jump Game IV
4. Snakes and Ladders
5. Minimum Genetic Mutation
6. Minimum Multiplications

---------------------------------------------

MULTI SOURCE BFS:

1. Rotting Oranges
2. 01 Matrix
3. Walls and Gates
4. As Far From Land As Possible

---------------------------------------------

0-1 BFS:

1. Minimum Cost Valid Path
2. Reverse Edge Problems

---------------------------------------------

DIJKSTRA:

1. Network Delay Time
2. Cheapest Flights K Stops
3. Path with Minimum Effort

---------------------------------------------
INTERVIEW IDENTIFICATION TRICK
---------------------------------------------

Question says:

minimum + operations

Ask:

Are all operations same cost?

YES:

BFS

Cost 0/1:

0-1 BFS

Variable cost:

Dijkstra

Multiple sources:

Multi-source BFS

Huge search space:

Bidirectional BFS

---------------------------------------------
MOST IMPORTANT TAKEAWAY
---------------------------------------------

minimum operations
+
equal edge cost

= BFS

minimum path
+
weighted graph

= Dijkstra

0/1 weights

= 0-1 BFS

multiple sources

= Multi-source BFS

---------------------------------------------
*/