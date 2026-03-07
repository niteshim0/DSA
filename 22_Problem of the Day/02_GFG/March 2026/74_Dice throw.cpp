// Dice throw
// https://www.geeksforgeeks.org/problems/dice-throw5349/1

// Concepts :: Recursion + Dynamic Programming(Bottom Up + Top Down + Space Optimized) + Mathematical Logic

// Approach :: There are two states which changes firs is diceNo and second is sum , for every state ,there might be different diceNo and remainingSum , so if diceNo gets down to 0 as well as sum == 0 , we will count as 1 possiblity , and for every faces , we will calculate plausible states and cnt .

// Technique 1 : Memoization Approach
class Solution {
public:
    int countWays(int diceNo, int faces, int sum, vector<vector<int>>& memo){
        if(sum < 0) return 0;
        if(diceNo == 0){
            return (sum == 0 ? 1 : 0);
        }
        if(memo[diceNo][sum] != -1){
            return memo[diceNo][sum];
        }

        int cnt = 0;
        for(int i = 1; i <= faces; i++){
            cnt += countWays(diceNo - 1, faces, sum - i, memo);
        }

        return memo[diceNo][sum] = cnt;
    }
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> memo(n + 1, vector<int>(x + 1, -1));
        return countWays(n, m, x, memo);
    }
};
// Time Complexity : O(N*X*M) + O(N)(Recursion Stack Space)
// Space Complexity : O(N*X)

// Technique 2 :: Tabulation Approach
class Solution {
public:
    int noOfWays(int m, int n, int x) {
        
        vector<vector<int>> tab(n + 1, vector<int>(x + 1, 0));

        tab[0][0] = 1;

        for(int dice = 1; dice <= n; dice++) {
            for(int sum = 1; sum <= x; sum++) {
                for(int face = 1; face <= m; face++) {

                    if(sum - face >= 0) {
                        tab[dice][sum] += tab[dice - 1][sum - face];
                    }

                }
            }
        }

        return tab[n][x];
    }
};

// Time Complexity : O(N*X*M) 
// Space Complexity : O(N*X)

// Technique 3 :: Space Optimized Approach

class Solution {
public:
    int noOfWays(int m, int n, int x) {
        
        vector<int> prev(x+1,0);

        prev[0] = 1;

        for(int dice = 1; dice <= n; dice++) {

            vector<int> curr(x+1,0);

            for(int sum = 1; sum <= x; sum++) {

                for(int face = 1; face <= m; face++) {

                    if(sum - face >= 0) {
                        curr[sum] += prev[sum - face];
                    }

                }

            }

            prev = curr;
        }

        return prev[x];
    }
};

// Time Complexity : O(N*X*M) 
// Space Complexity : O(X)

// Approach II :: Inclusion - Exclusion Principle
/* What Problem Says ?
We want the number of solutions to:
a1 + a2 + ... + an = x where 1 ≤ ai ≤ m
Each ai represents the value on a dice.
*/

// Moving towards Solution

/* // Step 1: Remove lower bound

-> Let bi = ai - 1
Then 0 ≤ bi ≤ m-1 and b1 + b2 + ... + bn = x - n(subtracting 1 from each dice results in n)

-> Let S = x - n
*/

/*
// Step 2: Without upper bound

-> Number of non-negative solutions of b1 + b2 + ... + bn = S
is given by Stars and Bars: C(S + n - 1, n - 1)

-> But this counts invalid cases where bi ≥ m (Case where dice >=faces)
So we must subtract them.
*/
/*
Step 3: Inclusion–Exclusion

-> Final formula:
Ways = Σ (-1)^k * C(n, k) * C(x - m*k - 1, n - 1) where
k = number of variables violating the limit and k ≤ (x-n)/m
*/

class Solution {
public:

    long long nCr(int n, int r){
        if(r > n || r < 0) return 0;
        long long res = 1;
        for(int i = 1; i <= r; i++){
            res = res * (n - r + i) / i;
        }
        return res;
    }

    int noOfWays(int m, int n, int x) {

        long long ans = 0;

        for(int k = 0; k <= n; k++){

            int val = x - m*k - 1;

            if(val < n-1) break;

            long long term = nCr(n, k) * nCr(val, n-1);

            if(k % 2 == 0)
                ans += term;
            else
                ans -= term;
        }

        return ans;
    }
};

// Time Complexity : O(N^2)
// Space Complexity : O(1)