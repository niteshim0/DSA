// https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[V];
        for(vector<int>& edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> indegree(V,0);
        
       for(int i = 0;i<V;i++){
           for(auto adjNode : adj[i]){
               indegree[adjNode]++;
           }
       }
       
       queue<int> q;
       for(int i = 0;i<V;i++){
           if(indegree[i] == 0) q.push(i);
       }
       
       int cnt = 0;
       while(!q.empty()){
           int node = q.front(); q.pop();
           cnt++;
           
           for(auto adjNode : adj[node]){
               indegree[adjNode]--;
               if(indegree[adjNode] == 0) q.push(adjNode);
           }
       }
       
       return cnt == numCourses;
    }
};

// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[V];
        for(vector<int>& edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> indegree(V,0);
        
       for(int i = 0;i<V;i++){
           for(auto adjNode : adj[i]){
               indegree[adjNode]++;
           }
       }
       
       queue<int> q;
       for(int i = 0;i<V;i++){
           if(indegree[i] == 0) q.push(i);
       }
       
       vector<int> topo;
       while(!q.empty()){
           int node = q.front(); q.pop();
           topo.push_back(node);
           
           for(auto adjNode : adj[node]){
               indegree[adjNode]--;
               if(indegree[adjNode] == 0) q.push(adjNode);
           }
       }
       
       if(topo.size() == numCourses) return topo;
       return {};
    }
};