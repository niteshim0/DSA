// LC 1411. Number of Ways to Paint N × 3 Grid
// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

// Concept :: DFS + Memoization

class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int n,int red,int yellow,int green,vector<vector<vector<vector<int>>>>& memo){
        if(n == 0) return 1;
        if(memo[n][red][yellow][green]!=0) return memo[n][red][yellow][green];

        vector<int> colors = {1,2,3};
        int ans = 0;
        for(int& Red : colors){
            if(Red == red) continue;
            for(int& Yellow : colors){
                if(Yellow == Red || Yellow == yellow) continue;
                for(int& Green : colors ){
                    if(Green == Yellow || Green == green) continue;
                    ans+=dfs(n-1,Red,Yellow,Green,memo);
                    ans%=MOD;
                }
            }
        }

        return memo[n][red][yellow][green] = ans;
    }
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> memo(n+1,
        vector<vector<vector<int>>>(4,
        vector<vector<int>>(4,
        vector<int>(4,0))));

        return dfs(n,0,0,0,memo);
    }
};

// Time Complexity : No of States = n*3*3*3
                    // Every state time Complexity : O(3^3)
                    // so total tC : O(n*3^6) or O(n*27^2)
// Space Complexity : O(N*4^3)













// Time Complexity :
// Space Complexity : 