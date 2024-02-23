class Solution {
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
      List<int[]>[] adj = new ArrayList[n]; // array of arraylist
      for(int i = 0;i<n;i++){
          adj[i] = new ArrayList<>();
      }
      for(int i = 0;i<n;i++){
          adj[i] = new ArrayList<>();
      }

      for(int[] flight : flights){
          adj[flight[0]].add(new int[]{flight[1],flight[2]}); //{node,costToReachtThatNode}
      }
      int[] dist = new int[n];
      Arrays.fill(dist,Integer.MAX_VALUE);

      Queue<int[]> queue = new LinkedList<>(); //LinkedList because queue is interface not class
      queue.add(new int[]{0,src,0}); //{stops,node,costToReachtThatNode}
      dist[src] = 0;

      while(!queue.isEmpty()){
          int[] curr = queue.poll();
          int stops = curr[0];
          int node = curr[1];
          int cost = curr[2];

          for(int[] neighbor : adj[node]){
              int adjNode = neighbor[0];
              int flightCost  = neighbor[1];
              if(cost+flightCost<dist[adjNode] && stops<=k){
                  dist[adjNode] = cost + flightCost;
                  queue.add(new int[]{stops+1,adjNode,dist[adjNode]});
              }
          }
      }

      return (dist[dst] == Integer.MAX_VALUE ? -1 : dist[dst]);

  }
}