// LC 3864. Minimum Cost to Partition a Binary String
// https://leetcode.com/problems/minimum-cost-to-partition-a-binary-string/description/
// Concepts :: PrefixSum + Divide and Conquer + Dynamic Programming

// Approach :: Standard Choice DP Problem


class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (s[i] == '1');

        unordered_map<long long, long long> dp;

        // Function to get number of '1's in [l, r]
        auto getOnes = [&](int l, int r) -> long long {
            return pref[r + 1] - pref[l];
        };

        // Recursive function with memoization
        function<long long(int,int)> solve = [&](int l, int r) -> long long {
            long long key = ((long long)l << 32) | r;
            if (dp.count(key)) return dp[key];

            int L = r - l + 1;
            long long X = getOnes(l, r);
            long long cost_no_split = (X == 0) ? flatCost : 1LL * L * X * encCost;

            long long ans = cost_no_split;

            if (L % 2 == 0) {
                int mid = (l + r) / 2;
                ans = min(ans, solve(l, mid) + solve(mid + 1, r));
            }

            return dp[key] = ans;
        };

        return solve(0, n - 1);
    }
};

// Time Complexity : O(NlogN)
// Space Complexity : O(N)

// I should have gone for this ques during contest I would have done much better.

typedef long long ll;

class Solution {
public:
    ll enc, flat ;
    vector<int> pref ;
    string t ; 

    ll dfs( int l, int r ) {
        int len = r - l + 1 ; 
        int ones = pref[r+1] - pref[l] ;

        ll cost ;
        if( ones == 0) cost = flat ; 
        else cost = 1LL * len * ones * enc ; 

        if( len % 2 == 0 ) {
            int mid = ( l + r ) / 2 ; 
            cost = min( cost, dfs(l, mid ) + dfs( mid + 1, r ) ) ; 
        }

        return cost; 
    };

    long long minCost(string s, int encCost, int flatCost) {
        t = s ; 
        enc = encCost ;
        flat = flatCost ; 

        int n = s.size() ;

        pref.assign(n+1, 0 ) ;
        for( int i = 0 ; i < n ; i++ ) pref[i+1] = pref[i] + ( s[i] == '1' ) ; 

        return dfs(0, n-1 ) ; 
    }
};