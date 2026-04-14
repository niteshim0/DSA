// LC 2463. Minimum Total Distance Traveled
// https://leetcode.com/problems/minimum-total-distance-traveled


// Concepts :: Dynamic Programming + Greedy  + Sorting 

// Short Version Explaination :: "I sort robots and factories to ensure optimal pairing. Since factories have capacities, I flatten them into slots so the problem reduces to matching robots to positions. Then I use a 2D DP where at each step I either assign the current robot to the current slot or skip the slot. The state is dp[i][j], representing minimum cost for robots from i using slots from j. I optimize it to O(n) space. Overall time complexity is O(m × n)."

// Explaination :: How to say in interview ?

/*

1. Intuition

“We want to assign robots to factories such that total distance is minimized. Since distance depends on positions, I first sort both robots and factories to ensure optimal pairing in order.”

2. Key Optimization Idea

“Each factory has a capacity, so instead of handling it separately, I flatten factories into multiple positions based on their capacity. This converts the problem into assigning robots to slots.”

3. DP Formulation

“Now the problem reduces to a 2-pointer DP:
At each step, I decide whether to:
assign current robot to current factory slot
or skip this slot”

4. State Definition
dp[i][j] = minimum cost to assign robots from index i using factory slots from index j

5. Transition
dp[i][j] = min(
    abs(robot[i] - factoryPositions[j]) + dp[i+1][j+1],   // assign
    dp[i][j+1]                                            // skip
)

6. Base Cases
If all robots are assigned → cost = 0
If slots are exhausted but robots remain → invalid (infinity) (which will never be the case in terms of given constraints of the ques , its only for sanctity purpose here)

7. Optimization

“I first wrote recursion, then optimized it using DP(Memoization and Tabulation), and finally reduced space to O(n) using two arrays.”

8. Complexity

“Time complexity is O(m * n), where m is number of robots and n is total factory capacity. Space is optimized to O(n).”

9. Non flattening Approach

“Alternatively, we can avoid flattening and directly assign k robots per factory using a grouped DP approach, but that leads to O(m * n * capacity).”

*/

// 


// Approach I : Recursion

class Solution {
public:
    long long calculateMinDistance(int roboIdx, int factoryIdx , vector<int>& robot, vector<int>& factoryPositions){
        
        if(roboIdx == robot.size()) return 0;

        if(factoryIdx == factoryPositions.size()) return 1e12;

        long long assign = abs(robot[roboIdx] - factoryPositions[factoryIdx]) + 

                          calculateMinDistance(roboIdx+1, factoryIdx + 1 , robot , factoryPositions);

        long long skip   =  calculateMinDistance(roboIdx, factoryIdx + 1 , robot , factoryPositions);

        
        return min(assign, skip);
                         
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int> factoryPositions;


        // flattening so that limit can be handled
        for(vector<int>& f : factory){

            for(int i = 0 ; i < f[1] ; i++) {

                factoryPositions.push_back(f[0]);
            }
        }
        

        return calculateMinDistance(0 , 0 , robot, factoryPositions);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    }
};

// Time Complexity : O(2^(N*M))
// Space Complexity : O(max(N,M)) // recursion stack space + O(totalCapacity) // extra array for flattened array


// Approach II : Memoization (Flattened Array Approach)

class Solution {
public:
    vector<vector<long long>> dp;
    long long calculateMinDistance(int roboIdx, int factoryIdx , vector<int>& robot, vector<int>& factoryPositions){
        
        if(roboIdx == robot.size()) return 0;

        if(factoryIdx == factoryPositions.size()) return 1e12;

        if(dp[roboIdx][factoryIdx] != -1) return dp[roboIdx][factoryIdx];

        long long assign = abs(robot[roboIdx] - factoryPositions[factoryIdx]) + 

                          calculateMinDistance(roboIdx+1, factoryIdx + 1 , robot , factoryPositions);

        long long skip   =  calculateMinDistance(roboIdx, factoryIdx + 1 , robot , factoryPositions);

        
        return dp[roboIdx][factoryIdx] = min(assign, skip);
                         
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int> factoryPositions;


        // flattening so that limit can be handled
        for(vector<int>& f : factory){

            for(int i = 0 ; i < f[1] ; i++) {

                factoryPositions.push_back(f[0]);
            }
        }

        int m = robot.size();
        int n = factoryPositions.size();

        dp.resize(m,vector<long long>(n,-1));
        
        return calculateMinDistance(0 , 0 , robot, factoryPositions);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    }
};

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)


// Approach III : Tabulation (Flattned)

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPositions;

        for (auto &f : factory) {
            for (int i = 0; i < f[1]; i++) {
                factoryPositions.push_back(f[0]);
            }
        }

        int m = robot.size();
        int n = factoryPositions.size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 1e15));

        // base cases
        for (int j = 0; j <= n; j++) dp[m][j] = 0;     // no robots left
        for (int i = 0; i < m; i++) dp[i][n] = 1e15;   // no slots left

        for (int roboIdx = m - 1; roboIdx >= 0; roboIdx--) {
            for (int factoryIdx = n - 1; factoryIdx >= 0; factoryIdx--) {

                long long assign = abs(robot[roboIdx] - factoryPositions[factoryIdx]) + dp[roboIdx + 1][factoryIdx + 1];
                long long skip = dp[roboIdx][factoryIdx + 1];

                dp[roboIdx][factoryIdx] = min(assign, skip);
            }
        }

        return dp[0][0];
    }
};

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)


// Approach IV : Space Optimized Approach

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPositions;

        for (auto &f : factory) {
            for (int i = 0; i < f[1]; i++) {
                factoryPositions.push_back(f[0]);
            }
        }

        int m = robot.size();
        int n = factoryPositions.size();

        vector<long long> curr(n + 1, 1e15), next(n + 1, 1e15);

        for (int j = 0; j <= n; j++) next[j] = 0;

        for (int roboIdx = m - 1; roboIdx >= 0; roboIdx--) {

            for (int factoryIdx = n - 1; factoryIdx >= 0; factoryIdx--) {

                long long assign = abs(robot[roboIdx] - factoryPositions[factoryIdx]) + next[factoryIdx + 1];
                long long skip = curr[factoryIdx + 1];

                curr[factoryIdx] = min(assign, skip);
            }

            next = curr; 
        }

        return next[0];
    }
};

// Time Complexity: O(m * n) in all previous approaches n is sum of capcities == totalCapacity
// Space Complexity: O(n)

// Approach V :: Non-Flattned + Prefix Sum Approach(Grouped DP)
// If sum of limits is very high , it is the best choice
/*
Instead of converting factories into slots,
we directly use: factory[j] = [position, capacity]
At each factory, we assign a group of robots (k robots)

// State Definition :: dp[i][j] = minimum cost to assign robots[i...] using factories[j...]
*/

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int m = robot.size();
        int n = factory.size();

        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 1e15));

        for(int j = 0; j <= n; j++) dp[m][j] = 0;

        for(int j = n-1; j >= 0; j--){
            for(int i = m-1; i >= 0; i--){

                long long res = dp[i][j+1];

                long long dist = 0;

                for(int k = 0; k < factory[j][1] && i+k < m; k++){

                    dist += abs(robot[i+k] - factory[j][0]);

                    res = min(res, dist + dp[i+k+1][j+1]);
                }

                dp[i][j] = res;
            }
        }

        return dp[0][0];
    }
};

// Time Complexity :: O(M * N * maxCapacity(C))
// Space Complexity :: O(M*N)

