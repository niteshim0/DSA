// 1. Recursion Solution


class Solution {
  public:
    int solve(int day,int lastTask,vector<vector<int>>& arr){
        if(day == 0){
            int maxi = 0;
            for(int i = 0;i<=2;i++){
                if(i!=lastTask){
                maxi = max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        int maxi = 0;
        for(int i = 0;i<=2;i++){
                if(i!=lastTask){
                int points = arr[day][i] + solve(day-1,i,arr);
                maxi = max(maxi,points);
            }
        }
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        return solve(n-1,3,arr);
    }
};

/*
Metric	Value :: (t = 3)
Recurrence ::	solve(day, lastTask) = max(arr[day][i] + solve(day-1, i)) for all i ≠ lastTask
Time Complexity  :: (recursive)	O(2ⁿ)
Space Complexity :: 	O(n) (recursion stack)
*/

// 2. Memoization Solution(Bottom Up Approach)

class Solution {
  public:
    int solve(int day,int lastTask,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(dp[day][lastTask]!=-1) return dp[day][lastTask];
        if(day == 0){
            int maxi = 0;
            for(int i = 0;i<=2;i++){
                if(i!=lastTask){
                maxi = max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        int maxi = 0;
        for(int i = 0;i<=2;i++){
                if(i!=lastTask){
                int points = arr[day][i] + solve(day-1,i,arr,dp);
                maxi = max(maxi,points);
            }
        }
        return dp[day][lastTask] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(n-1,3,arr,dp);
    }
};
// Time Complexity :: O(N*T) // N function calls with each loop running for t times
// Space Complexity:: O(N*T)//for dp array + O(N)//for recursion stack space

//3. Tabulation Solution(Top Down Approach)

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case for day 0
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]}); // no task restriction on first day

        for (int day = 1; day < n; day++) {
            for (int lastTask = 0; lastTask <= 3; lastTask++) {
                int maxi = 0;
                for (int i = 0; i <= 2; i++) {
                    if (i != lastTask) {
                        int points = arr[day][i] + dp[day - 1][i];
                        maxi = max(maxi, points);
                    }
                }
                dp[day][lastTask] = maxi;
            }
        }

        return dp[n - 1][3]; // lastTask = 3 means no restriction
    }
};
// Time Complexity : O(N*4*3)
// Space Complexity : O(N*4)

// 4. Space Optimization

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> prev(4, 0);

        // Base case for day 0
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});

        for (int day = 1; day < n; day++) {
            vector<int> temp(4, 0);
            for (int lastTask = 0; lastTask <= 3; lastTask++) {
                int maxi = 0;
                for (int i = 0; i <= 2; i++) {
                    if (i != lastTask) {
                        int points = arr[day][i] + prev[i];
                        maxi = max(maxi, points);
                    }
                }
                temp[lastTask] = maxi;
            }
            prev = temp; 
        }

        return prev[3]; 
    }
};
// Time Complexity : O(N*4*3)
// Space Complexity : O(4)