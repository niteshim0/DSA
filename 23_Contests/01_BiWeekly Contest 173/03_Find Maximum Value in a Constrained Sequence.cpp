// 3796. Find Maximum Value in a Constrained Sequence
// https://leetcode.com/problems/find-maximum-value-in-a-constrained-sequence/description/


// During Contest
// I was thinking of DFS solution , due to high constraints its gives TLE and as well as it was much simpler Greedy + Prefix Sum problem that I can't able to see.
// Not able to solve


// During Upsolving
// Concept :: Greedy Problem

// Code

class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> sequence(n,1e8);
        sequence[0] = 0;
        int ans = INT_MIN;
        for(vector<int>& restriction : restrictions){
            sequence[restriction[0]] = restriction[1];
        }

        for(int i = 1;i<n;i++){
            sequence[i] = min(sequence[i],sequence[i-1] + diff[i-1]);
        }

        for(int i = n-2;i>=0;i--){
            sequence[i] = min(sequence[i],sequence[i+1] + diff[i]);
        }

        for(auto &num : sequence){
            ans = max(ans,num);
        }

        return ans;

    }
};

// Time Complexity : O(N)
// Space Complexity : O(N) // but can be reduced to O(1) by using some variables as well as can get rid of last loop as well but that for later