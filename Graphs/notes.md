# Dijkstra's Shortest Path Algorithm

Dijkstra's algorithm is a popular method used to find the shortest path from a single source vertex to all other vertices in a weighted graph. It works for both directed and undirected graphs with non-negative edge weights.

## Algorithm Steps:

1. **Initialization**: 
   - Initialize distances from the source vertex to all other vertices as infinity, and the distance to the source vertex itself as 0.
   - Maintain a priority queue (or min-heap) to store vertices and their distances. Initially, enqueue the source vertex with distance 0.

2. **Main Loop**:
   - Repeat the following until the priority queue is empty:
     - Dequeue a vertex `v` with the minimum distance from the priority queue.
     - For each neighbor `u` of `v`, update the distance to `u` if the distance through `v` is shorter than the previously known distance.
     - Enqueue `u` with the updated distance into the priority queue.

3. **Termination**:
   - After processing all vertices, the distances array contains the shortest distances from the source vertex to all other vertices.

## Time Complexity:
- The time complexity of Dijkstra's algorithm depends on the data structure used for the priority queue. 
- With a binary heap or Fibonacci heap, the time complexity is O((V + E) log V), where V is the number of vertices and E is the number of edges.

## Usage:
- Dijkstra's algorithm is commonly used in routing and network protocols to find the shortest path in computer networks, such as the Internet.
- It also has applications in various fields like transportation networks, GPS navigation systems, and task scheduling.

## Considerations:
- Dijkstra's algorithm fails when there are negative edge weights.
- It may not work efficiently with large graphs due to its time complexity.
- Various optimizations and data structures, such as bidirectional Dijkstra's algorithm and A* search algorithm, are used to improve its performance in practical scenarios.

## C++ Code:


### Way I : Using Priority Queue
```c++
vector<int> dijkstra(int V,vector<vector<int>> adj[],int src){

  //adjacency list = {node,distanceToReachThatNode}
  priority_queue<pair<int,int>,
  vector<pair<int,int>>,
  greater<pair<int,int>>> pq; 

  vector<int> dist(v,INT_MAX);
  dist[src] = 0;
  pq.push({0,0}) ; // {costToReachThatNode,node}

  while(!pq.empty()){
    int node  = pq.top().second;
    int distance = pq.top().first;
    pq.pop();

    for(auto it : adj[node]){
      int adjNode = it[0];
      int nodeDistance = it[1];
      if(distance + nodeDistance<dist[adjNode]){
        dist[adjNode] = distance + nodeDistance;
        pq.push({distance + nodeDistance,adjNode});
      }
    }
  }

  return dist;
}
```

### Way II : Using Set

```c++
vector<int> dijkstra(int V,vector<vector<int>> adj[],int src){

  //adjacency list = {node,distanceToReachThatNode}
  set<pair<int,int>> st;

  vector<int> dist(v,INT_MAX);
  dist[src] = 0;
  st.insert({0,0}) ; // {costToReachThatNode,node}

  while(!st.empty()){
    auto it = *(st.begin());
    int node  = it.second;
    int distance = it.first;
    st.erase(it);

    for(auto it : adj[node]){
      int adjNode = it[0];
      int nodeDistance = it[1];
      if(distance + nodeDistance<dist[adjNode]){
        if(dist[adjNode]!=INT_MAX){
          st.erase({dist[adjNode],adjNode});
        }else{
          dist[adjNode] = distance + nodeDistance;
          st.insert({distance + nodeDistance,adjNode});
        }
      }
    }
  }
  return dist;
}
```
