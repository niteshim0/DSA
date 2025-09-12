// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
  public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        
        for(int i = 0; i < V; i++) {
            for(auto adjNode : adj[i]) {
                indegree[adjNode]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            
            for(auto adjNode : adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        
        return topo;
    }

    string findOrder(vector<string> &words) {
        // Step 1: collect distinct characters
        int n = words.size();
        unordered_set<char> uniqueChars;
        for (auto &w : words) {
            for (char c : w) uniqueChars.insert(c);
        }
        int V = uniqueChars.size();

        // Map characters to indices
        unordered_map<char,int> charToIndex;
        unordered_map<int,char> indexToChar;
        int idx = 0;
        for (char c : uniqueChars) {
            charToIndex[c] = idx;
            indexToChar[idx] = c;
            idx++;
        }

        // Step 2: build graph
        vector<int> adj[V];
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());

            bool foundDiff = false;
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[charToIndex[s1[j]]].push_back(charToIndex[s2[j]]);
                    foundDiff = true;
                    break; // only first differing char matters
                }
            }

            // Invalid case: prefix order violation
            if (!foundDiff && s1.size() > s2.size()) {
                return "";
            }
        }

        // Step 3: topo sort
        vector<int> topo = topoSort(V, adj);

        if ((int)topo.size() != V) return ""; // cycle → invalid

        // Step 4: build order string
        string order = "";
        for (int id : topo) {
            order += indexToChar[id];
        }
        return order;
    }
};


// Time Complexity: O(N * L + V + E) → ~ O(N * L) in practice.
// Space Complexity: O(V + E) → bounded by O(26²) = O(1).