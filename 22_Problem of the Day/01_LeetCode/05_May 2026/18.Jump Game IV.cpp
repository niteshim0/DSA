// LC 1345. Jump Game IV
// https://leetcode.com/problems/jump-game-iv/description

// Concepts :: Breadth-First Search/Hash Table/Shortest Path/Graph Coloring

// Key Idea :: Modeling array indices as graph nodes and using BFS to find the shortest path while optimizing edge transitions.

class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();
        if(n == 1) return 0;

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n,false);

        q.push(0);
        visited[0]=true;

        int steps=0;

        while(!q.empty()){

            int levelSize=q.size();

            while(levelSize--){

                int node=q.front();
                q.pop();

                if(node==n-1) return steps;

                int next1=node+1;
                int next2=node-1;

                if(next1<n && !visited[next1]){
                    q.push(next1);
                    visited[next1]=true;
                }

                if(next2>=0 && !visited[next2]){
                    q.push(next2);
                    visited[next2]=true;
                }

                vector<int>& need = mp[arr[node]];

                for(int idx:need){

                    if(!visited[idx]){
                        q.push(idx);
                        visited[idx]=true;
                    }
                }

                mp[arr[node]].clear();
            }

            steps++;
        }

        return -1;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)