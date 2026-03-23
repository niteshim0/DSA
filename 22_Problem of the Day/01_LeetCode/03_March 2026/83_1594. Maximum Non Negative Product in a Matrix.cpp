// LC 1594. Maximum Non Negative Product in a Matrix
// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

// Concepts :: Reursion + Dynamic Programming(all optimizations) + typical pick/non-pick choices + Strong syntax knowledge of programmming language(here C++) + Rolling Arrays (needed in space optimzation)

// Key Idea:
// Tracking both maximum and minimum products at each cell to handle negative number sign flips during path traversal.

// Technique 1 :: Recursion

class Solution {
public:
    const int MOD = 1e9 + 7;

    pair<long long, long long> maxProductPathSolver(vector<vector<int>>& grid,int row,int col){

        int n = grid.size() , m = grid[0].size();

        if(row>=n || col>=m) return {LLONG_MAX,LLONG_MIN};

        if(row == n-1 && col == m-1) return {grid[row][col], grid[row][col]};

        auto right = maxProductPathSolver(grid,row,col+1);

        auto down  = maxProductPathSolver(grid,row+1,col);

        vector<int> vals;

        for(auto pr : {right,down}){
            
            if(pr.first!=LLONG_MAX) vals.push_back(grid[row][col] * pr.first);
            
            if(pr.second!=LLONG_MIN) vals.push_back(grid[row][col] * pr.second);

        }

        long long mini = *min_element(vals.begin(),vals.end());

        long long maxi = *max_element(vals.begin(),vals.end());

        return {mini, maxi};

    }  
    int maxProductPath(vector<vector<int>>& grid) {
        
        auto res = maxProductPathSolver(grid,0,0);

        return res.second<0 ? -1 : (res.second%MOD);
    }
};

// | Complexity | Value                                 |
// | ---------- | ------------------------------------- |
// | Time       | **O(2^(n+m))** ❌ (TLE for large grid) |
// | Space      | **O(n+m)**                            |


// Technique 2 :: Memoization (Top Down Approach)

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<pair<long long,long long>>> dp;
    bool vis[20][20];

    pair<long long, long long> maxProductPathSolver(vector<vector<int>>& grid,int row,int col){

        int n = grid.size() , m = grid[0].size();

        if(row>=n || col>=m) return {LLONG_MAX,LLONG_MIN};

        if(row == n-1 && col == m-1) return {grid[row][col], grid[row][col]};

        if(vis[row][col]) return dp[row][col];

        auto right = maxProductPathSolver(grid,row,col+1);

        auto down  = maxProductPathSolver(grid,row+1,col);

        vector<long long> vals;

        for(auto pr : {right,down}){
            
            if(pr.first!=LLONG_MAX) vals.push_back(grid[row][col] * pr.first);
            
            if(pr.second!=LLONG_MIN) vals.push_back(grid[row][col] * pr.second);

        }

        long long mini = *min_element(vals.begin(),vals.end());

        long long maxi = *max_element(vals.begin(),vals.end());

        vis[row][col] = true;

        return dp[row][col] = {mini, maxi};

    }  
    int maxProductPath(vector<vector<int>>& grid) {

        int n = grid.size() , m = grid[0].size();

        dp.resize(n,vector<pair<long long,long long>>(m));

        memset(vis,false,sizeof(vis));

        auto res = maxProductPathSolver(grid,0,0);

        return res.second<0 ? -1 : (res.second%MOD);
    }
};

// | Complexity | Value                                 |
// | ---------- | ------------------------------------- |
// | Time       | **O(N*M)**|
// | Space      | **O(n*M)** + **O(N+M)**(Recursion Stack Space)

// Technique3 :: Tabulation (Bottom Up DP) 
// Recursion stack space can be avoided


class Solution {
public:

    const int MOD = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size();

        vector<vector<long long>> maxDP(n,vector<long long>(m));

        vector<vector<long long>> minDP(n,vector<long long>(m));

        maxDP[0][0] = minDP[0][0] = grid[0][0];

        for(int col = 1;col<m;col++){

            maxDP[0][col] = minDP[0][col] = maxDP[0][col-1] * grid[0][col];

        }

        for(int row = 1;row<n;row++){

            maxDP[row][0] = minDP[row][0] = maxDP[row-1][0] * grid[row][0];

        }

        for(int row = 1; row<n; row++){

            for(int col = 1;col<m;col++){

                long long a = maxDP[row-1][col] * grid[row][col];
                long long b = minDP[row-1][col] * grid[row][col];
                long long c = maxDP[row][col-1] * grid[row][col];
                long long d = minDP[row][col-1] * grid[row][col];

                maxDP[row][col] = max({a, b, c, d});
                minDP[row][col] = min({a, b, c, d});

            }
        }

        long long res = maxDP[n-1][m-1];

        return res < 0 ? -1 : (res%MOD);


    }
};


// | Complexity | Value                                 |
// | ---------- | ------------------------------------- |
// | Time       | **O(N*M)**|
// | Space      | **O(N*M)**

// Technique 4 :: Space Optimized

class Solution {
public:

    const int MOD = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        vector<long long> maxDp(m), minDp(m);

        maxDp[0] = minDp[0] = grid[0][0];

        for(int j = 1; j < m; j++) {
            maxDp[j] = minDp[j] = maxDp[j-1] * grid[0][j];
        }

        for(int i = 1; i < n; i++) {

            // update first column
            maxDp[0] = maxDp[0] * grid[i][0];
            minDp[0] = minDp[0] * grid[i][0];

            for(int j = 1; j < m; j++) {

                long long a = maxDp[j] * grid[i][j];     // from top
                long long b = minDp[j] * grid[i][j];     // from top
                long long c = maxDp[j-1] * grid[i][j];   // from left
                long long d = minDp[j-1] * grid[i][j];   // from left

                long long newMax = max({a, b, c, d});
                long long newMin = min({a, b, c, d});

                maxDp[j] = newMax;
                minDp[j] = newMin;
            }
        }

        long long res = maxDp[m-1];
        
        return res < 0 ? -1 : (res%MOD);

    }
};

// | Complexity | Value                                 |
// | ---------- | ------------------------------------- |
// | Time       | **O(N*M)**|
// | Space      | **O(M)**