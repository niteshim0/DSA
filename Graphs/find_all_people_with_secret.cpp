//It has multitude of approaches
//one of the best question to check many approaches BFS,DFS,Union-Find

//Approach I : Earliest Informed First Traversal
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<pair<int,int>>> graph;
        vector<int> ans;
        for(auto& meeting: meetings){
            int x = meeting[0],y = meeting[1],t = meeting[2];
            graph[x].emplace_back(t,y);
            graph[y].emplace_back(t,x);
        }
        vector<bool> visited(n,false);
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq; //minHeap
        
        pq.emplace(0,0);
        pq.emplace(0,firstPerson);

        while(!pq.empty()){
            auto [time,person] = pq.top();
            pq.pop();
            if(visited[person]){
                continue;
            }

            visited[person] = true;
            for(auto [t,nextPerson] : graph[person]){
                if(!visited[nextPerson] && t>=time){
                    pq.emplace(t,nextPerson);
                }
            }
        }



        for(int i = 0;i<n;i++){
            if(visited[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//Approach II : Modified BFS which may process same node multiple times as according to the condition
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<pair<int,int>>> graph;
        vector<int> ans;
        for(auto& meeting: meetings){
            int x = meeting[0],y = meeting[1],t = meeting[2];
            graph[x].emplace_back(t,y);
            graph[y].emplace_back(t,x);
        }
        vector<int> earliest(n,INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        queue<pair<int,int>> q;
        q.emplace(0,0);
        q.emplace(firstPerson,0);

        while(!q.empty()){
            auto [person,time] = q.front();
            q.pop();

            for(auto[t,nextPerson] : graph[person]){
            if(t>=time && earliest[nextPerson]>t){
                earliest[nextPerson] = t;
                q.emplace(nextPerson,t);
            }
            }
        }

        for(int i = 0;i<n;i++){
            if(earliest[i]!=INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
//Approach 3 ::  Modified DFS which may process same node multiple times as according to the condition
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        //DFS using stack
        unordered_map<int,vector<pair<int,int>>> graph;
        vector<int> ans;
        for(auto& meeting: meetings){
            int x = meeting[0],y = meeting[1],t = meeting[2];
            graph[x].emplace_back(t,y);
            graph[y].emplace_back(t,x);
        }
        vector<int> earliest(n,INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        stack<pair<int,int>> stack;
        stack.emplace(0,0);
        stack.emplace(firstPerson,0);

        while(!stack.empty()){
            auto [person,time] = stack.top();
            stack.pop();

            for(auto[t,nextPerson] : graph[person]){
            if(t>=time && earliest[nextPerson]>t){
                earliest[nextPerson] = t;
                stack.emplace(nextPerson,t);
            }
            }
        }

        for(int i = 0;i<n;i++){
            if(earliest[i]!=INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//Recursion wala DFS

class Solution {
public:
    void dfs(int time,int person,auto& graph,auto& earliest){
        for(auto[t,nextPerson] : graph[person]){
            if(t>=time && earliest[nextPerson]>t){
                earliest[nextPerson] = t;
                dfs(t,nextPerson,graph,earliest);
            }
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<pair<int,int>>> graph;
        vector<int> ans;
        for(auto& meeting: meetings){
            int x = meeting[0],y = meeting[1],t = meeting[2];
            graph[x].emplace_back(t,y);
            graph[y].emplace_back(t,x);
        }
        vector<int> earliest(n,INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        dfs(0,0,graph,earliest);
        dfs(0,firstPerson,graph,earliest);
        for(int i = 0;i<n;i++){
            if(earliest[i]!=INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};