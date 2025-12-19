// https://leetcode.com/problems/find-all-people-with-secret/description/?envType=daily-question&envId=2025-12-19

// LC 2092. Find All People With Secret

// Approach I :: Plain BFS
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<int> ans;

        unordered_map<int, vector<pair<int,int>>> graph;
        for(auto &meeting : meetings){
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].push_back({y, t});
            graph[y].push_back({x, t});
        }
        
        vector<int> earliest(n, INT_MAX);

        queue<pair<int,int>> q;
        q.push({0, 0});              
        earliest[0] = 0;

        q.push({firstPerson, 0});   
        earliest[firstPerson] = 0;

        while(!q.empty()){
            auto [person, secretTime] = q.front();
            q.pop();

            for(auto &[nextPerson, meetingTime] : graph[person]){
                if(secretTime <= meetingTime && earliest[nextPerson] > meetingTime){
                    earliest[nextPerson] = meetingTime;
                    q.push({nextPerson, meetingTime});
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(earliest[i] != INT_MAX) ans.push_back(i);
        }

        return ans;
    }
};

// Time Complexity : O(N+M)
// Space Complexity : O(N+M)
// gives TLE(n == 10000) , might fail at tricky edge cases

// Approach II :: Plain DFS
class Solution {
public:
    void DFS(int secretTime,int personKnowsSecret,unordered_map<int, vector<pair<int,int>>> &graph,vector<int>& earliest){
        
            for(auto &[nextPerson, meetingTime] : graph[personKnowsSecret]){
                if(secretTime <= meetingTime && earliest[nextPerson] > meetingTime){
                    earliest[nextPerson] = meetingTime;
                    DFS(meetingTime,nextPerson,graph,earliest);
                }
            }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<int> ans;

        unordered_map<int, vector<pair<int,int>>> graph;
        for(auto &meeting : meetings){
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].push_back({y, t});
            graph[y].push_back({x, t});
        }
        
        vector<int> earliest(n, INT_MAX);
        
        earliest[0] = 0;
        earliest[firstPerson] = 0;
        DFS(0,0,graph,earliest);
        DFS(0,firstPerson,graph,earliest);

        for(int i = 0; i < n; i++){
            if(earliest[i] != INT_MAX) ans.push_back(i);
        }

        return ans;
    }
};
// Time Complexity : O(N+M)
// Space Complexity : O(N+M)
                    // :O(N)// recursion stack


// NOW VALID APPROACHES

// Approach II :: Dijkstra's Algorithm

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<vector<pair<int,int>>> graph(n);

        for (auto &m : meetings) {
            int x = m[0], y = m[1], t = m[2];
            graph[x].push_back({y, t});
            graph[y].push_back({x, t});
        }

        vector<int> earliest(n, INT_MAX);

        earliest[0] = 0;
        earliest[firstPerson] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();

            if (time > earliest[person]) continue;

            for (auto &[nextPerson, meetTime] : graph[person]) {
                if (time <= meetTime && earliest[nextPerson] > meetTime) {
                    earliest[nextPerson] = meetTime;
                    pq.push({meetTime, nextPerson});
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
            if (earliest[i] != INT_MAX)
                ans.push_back(i);

        return ans;
    }
};

// NOTE :: If work can be done using vectors rather than map , prefer vector you will escape from the constant overhead of collison + hashing + rehashing.
// In earlier BFS and DSA cases, TLE happens due to use of map.

// Time Complexity : O(MlogN)
// --> Graph Building : O(M)
// --> Dijkstra's : O(MlogN)
// --> Ans Building : O(N)

// Space Complexity : O(M + N)
// --> adjacency list → O(m)
// --> earliest array → O(n)
// --> min-heap → up to O(n)

// Approach II :  BFS + Time Grouping

// Approach III :: DSU + Time Grouping