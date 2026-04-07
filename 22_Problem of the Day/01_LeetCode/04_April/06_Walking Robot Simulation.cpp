// https://leetcode.com/problems/walking-robot-simulation
// LC 874. Walking Robot Simulation

/*
Approach:
- Store all obstacles in an unordered_set for O(1) lookup
- Use direction array to simulate movement (North, East, South, West)
- For each command:
    - Turn left/right by updating direction index
    - Move step-by-step to properly handle obstacles
    - Stop movement if next position is an obstacle
- Track maximum Euclidean distance (x^2 + y^2)

Time Complexity:
- O(k) to insert obstacles into set
- O(total_steps) to process all movements
- Each step takes O(1) for obstacle check
=> Overall: O(k + total_steps) ≈ O(n + k) (amortized)

Space Complexity:
- O(k) for storing obstacles
- O(1) extra space for direction + variables
=> Overall: O(k)
*/


class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<long long>()(((long long)p.first << 32) ^ p.second);
        }
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        unordered_set<pair<int,int>, pair_hash> obs;
        for(auto &o : obstacles){
            obs.insert({o[0], o[1]});
        }

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int d = 0;
        int x = 0, y = 0;
        int maxDist = 0;

        for(int cmd : commands){
            if(cmd == -1){
                d = (d + 1) % 4;
            }
            else if(cmd == -2){
                d = (d + 3) % 4;
            }
            else{
                for(int i = 0; i < cmd; i++){
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    if(obs.count({nx, ny})) break;

                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};