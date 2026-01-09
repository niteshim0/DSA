// LC 1458. Max Dot Product of Two Subsequences
// https://leetcode.com/problems/max-dot-product-of-two-subsequences/?envType=daily-question&envId=2026-01-08

// Concept :: DP on Subsequences

// Approach I : Memoization(Top Down Approach)

class Solution {
public:
    vector<vector<int>> memo;
    const int NEG_INF = -1e9;

    int dotProductSolver(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i == nums1.size() || j == nums2.size())
            return NEG_INF;

        if (memo[i][j] != -1)
            return memo[i][j];

        int take = nums1[i] * nums2[j];
        int extend = take + dotProductSolver(i+1, j+1, nums1, nums2);
        int skip1 = dotProductSolver(i+1, j, nums1, nums2);
        int skip2 = dotProductSolver(i, j+1, nums1, nums2);

        return memo[i][j] = max({take, extend, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        memo.resize(n, vector<int>(m, -1));

        int firstMin = INT_MAX, firstMax = INT_MIN;
        int secondMin = INT_MAX, secondMax = INT_MIN;

        for (int x : nums1) {
            firstMin = min(firstMin, x);
            firstMax = max(firstMax, x);
        }
        for (int x : nums2) {
            secondMin = min(secondMin, x);
            secondMax = max(secondMax, x);
        }

        // Edge cases: all negative vs all positive
        if (firstMax < 0 && secondMin > 0)
            return firstMax * secondMin;

        if (firstMin > 0 && secondMax < 0)
            return firstMin * secondMax;

        return dotProductSolver(0, 0, nums1, nums2);
    }
};

// Time Complexity : O(N*M)
// Space Complexity : O(N*M) + Recursion Stack Space Growth(MAX DEPTH)(N+M));

// Approach II : Tabulaltion (Bottom Up Approach)

class Solution {
public:
    vector<vector<int>> tab;
    const int NEG_INF = -1e9;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        tab.resize(n+1, vector<int>(m+1,NEG_INF));

        int firstMin = INT_MAX, firstMax = INT_MIN;
        int secondMin = INT_MAX, secondMax = INT_MIN;

        for (int x : nums1) {
            firstMin = min(firstMin, x);
            firstMax = max(firstMax, x);
        }
        for (int x : nums2) {
            secondMin = min(secondMin, x);
            secondMax = max(secondMax, x);
        }

        // Edge cases: all negative vs all positive
        if (firstMax < 0 && secondMin > 0)
            return firstMax * secondMin;

        if (firstMin > 0 && secondMax < 0)
            return firstMin * secondMax;
        
        // Writing the base case
        // this base case is already included while intializing the tab vector
        // it is written here again for understanding(here we are DRY : don' do in actual rounds just explain them)
        for(int idx1 = 0;idx1<=n;idx1++){
            tab[idx1][m] = NEG_INF;
        }
        for(int idx2 = 0;idx2<=m;idx2++){
            tab[n][idx2] = NEG_INF;
        }
        //Tabulation Process
        for(int idx1 = n-1;idx1>=0;idx1--){
            for(int idx2 = m-1;idx2>=0;idx2--){
                    int take = nums1[idx1] * nums2[idx2];
                    int extend = take + tab[idx1+1][idx2+1];
                    int skip1 = tab[idx1+1][idx2];
                    int skip2 = tab[idx1][idx2+1];

                    tab[idx1][idx2] = max({take, extend, skip1, skip2});
            }
        }

        return tab[0][0];
    }
};
// Time Complexity : O(N*M)
// Space Complexity :  O(N*M)


// Approach III :: Space Optimized

class Solution {
public:
    const int NEG_INF = -1e9;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int firstMin = INT_MAX, firstMax = INT_MIN;
        int secondMin = INT_MAX, secondMax = INT_MIN;

        for (int x : nums1) {
            firstMin = min(firstMin, x);
            firstMax = max(firstMax, x);
        }
        for (int x : nums2) {
            secondMin = min(secondMin, x);
            secondMax = max(secondMax, x);
        }

        // Edge cases: all negative vs all positive
        if (firstMax < 0 && secondMin > 0)
            return firstMax * secondMin;

        if (firstMin > 0 && secondMax < 0)
            return firstMin * secondMax;
        
        vector<int> next(m+1,NEG_INF);
        vector<int> curr(m+1,NEG_INF);
        
        //Tabulation Process(Space Optimized)
        for(int idx1 = n-1;idx1>=0;idx1--){

            for(int idx2 = m-1;idx2>=0;idx2--){

                    int take = nums1[idx1] * nums2[idx2];
                    int extend = take + next[idx2+1];
                    int skip1 = next[idx2];
                    int skip2 = curr[idx2+1];

                    curr[idx2] = max({take, extend, skip1, skip2});
            }
            next = curr;
        }

        return next[0];
    }
};

// Time Complexity : O(N*M)
// Space Complexity :  O(M)