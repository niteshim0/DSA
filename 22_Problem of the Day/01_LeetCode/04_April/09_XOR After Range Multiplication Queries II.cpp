// LC 3653. XOR After Range Multiplication Queries I
// https://leetcode.com/problems/xor-after-range-multiplication-queries-i



// Approach I 
// Just do what ques said , it is easy to follow go brute 
// Traverse every query and apply changes in original nums of that query.
// At last , take xor of every element of now modified array and return the xor as ans


class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for(vector<int>& query : queries){

            for(int idx = query[0] ; idx<=query[1];idx+=query[2]){

                nums[idx] = (nums[idx] * 1ll * query[3]) % MOD;
            }
        }

        int xr = 0;
        for(int& x : nums){

            xr^=x;
        }

        return xr;
    }
};

// Time Complexity : O(N * Q)
// Space Complexity : O(1)


// Drawbacks :: If constraints will be high it is bound to fail , use segment tree or any such things.


// Approach 2 :: Square Root Decomposition + Fermet Theorem

// Classic Pattern Name :: "Range Updates On Arithmetic Progression Indices"
// Strategy :: "Split on k using √n"


// Intuition :: 
// 1. Each query updates indices in an arithmetic progression, not a continuous range → normal prefix tricks fail.

// 2. Split on k: small k → many hits → batch using grouping, large k → few hits → simulate directly.

// 3. This balances work to ~√n per query, giving overall O((n + q)√n).

// Complexity
// Time  : O((n + q) * sqrt(n))
// Space : O(n)

// Key Concepts Used
// 1 Sqrt Decomposition
// 2 Arithmetic Progression grouping
// 3 Lazy multiplication (difference-style events)
// 4 Modular inverse (to “remove” effect)


class Solution {
public:
    static const int MOD = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // ------------------------------------------------------------
        // 🔑 IDEA:
        // Queries update indices in AP: l, l+k, l+2k...
        // → Not continuous → can't use normal prefix tricks
        //
        // So:
        // - Small k  → many indices → batch process
        // - Large k  → few indices → simulate directly
        // ------------------------------------------------------------

        int B = sqrt(n) + 1;

        // group queries by k (only for small k)
        unordered_map<int, vector<vector<int>>> mp;

        // ------------------------------------------------------------
        // Step 1: Split queries
        // ------------------------------------------------------------
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k <= B) {
                // store for batch processing
                mp[k].push_back(q);
            } else {
                // ----------------------------------------------------
                // Large k → very few jumps → direct simulation is cheap
                // ----------------------------------------------------
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            }
        }

        // ------------------------------------------------------------
        // Step 2: Process small k (batch processing)
        // ------------------------------------------------------------
        for (auto &[k, qs] : mp) {

            // For fixed k:
            // indices follow pattern → i % k = remainder
            // So we divide array into k groups
            vector<vector<pair<int,int>>> group(k);

            for (auto &q : qs) {
                int l = q[0], r = q[1], v = q[3];

                int rem = l % k;

                // ----------------------------------------------------
                // 🔥 KEY IDEA: COMPRESSED INDEX SPACE
                //
                // Instead of real indices:
                //   r, r+k, r+2k, ...
                //
                // Map them to:
                //   0, 1, 2, ...
                //
                // So we convert:
                //   index → (index - rem) / k
                // ----------------------------------------------------
                int start = (l - rem) / k;
                int end   = (r - rem) / k;

                // ----------------------------------------------------
                // We use "difference array" idea for multiplication:
                //
                // At 'start' → multiply by v
                // After 'end' → remove effect → multiply by inverse(v)
                // ----------------------------------------------------
                group[rem].push_back({start, v});
                group[rem].push_back({end + 1, modInverse(v)});
            }

            // --------------------------------------------------------
            // Process each remainder group independently
            // --------------------------------------------------------
            for (int r = 0; r < k; r++) {
                if (group[r].empty()) continue;

                // sort events by compressed index
                sort(group[r].begin(), group[r].end());

                long long curr = 1; // current multiplier
                int ptr = 0;

                int idx = 0; // compressed index (0,1,2,...)

                // traverse actual indices: r, r+k, r+2k...
                for (int i = r; i < n; i += k, idx++) {

                    // ------------------------------------------------
                    // Apply all events scheduled at this position
                    // (start → multiply, end+1 → divide via inverse)
                    // ------------------------------------------------
                    while (ptr < group[r].size() && group[r][ptr].first == idx) {
                        curr = (curr * group[r][ptr].second) % MOD;
                        ptr++;
                    }

                    // apply accumulated multiplier
                    nums[i] = (1LL * nums[i] * curr) % MOD;
                }
            }
        }

        // ------------------------------------------------------------
        // Step 3: Final XOR
        // ------------------------------------------------------------
        int ans = 0;
        for (int x : nums) ans ^= x;

        return ans;
    }

    // ------------------------------------------------------------
    // Fast exponentiation (binary exponentiation)
    // ------------------------------------------------------------
    long long modExp(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    // ------------------------------------------------------------
    // Modular inverse using Fermat's theorem:
    // a^(-1) ≡ a^(MOD-2) % MOD
    // ------------------------------------------------------------
    long long modInverse(long long x) {
        return modExp(x, MOD - 2);
    }
};