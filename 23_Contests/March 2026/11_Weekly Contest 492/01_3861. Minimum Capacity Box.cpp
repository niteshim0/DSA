// LC 3861. Minimum Capacity Box
// https://leetcode.com/problems/minimum-capacity-box/
// Concepts :: Enumeration + Minimum Logic
// Solved During contest , its easy means easy just do what is saying in ques

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minCap = INT_MAX;
        int n = capacity.size();
        int minIdx = n;
        bool found = false;
        for(int i = 0;i<n;i++){
            if(capacity[i]>=itemSize){
                found = true;
                if(capacity[i]<minCap){
                    minCap = capacity[i];
                    minIdx = i;
                }
            }
        }
        if(!found) return -1;
        return minIdx;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)