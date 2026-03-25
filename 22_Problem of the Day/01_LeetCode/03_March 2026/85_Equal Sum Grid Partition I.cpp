// LC 3546. Equal Sum Grid Partition I
// https://leetcode.com/problems/equal-sum-grid-partition-i/description/

// Concepts :: Prefix Sum

// Approach :: Calculate totalSum of whole matrix and then travel two time,first time row-major order , for every completed row check , is it can be two equal parts(sum should be same) , same goes for col , traverse according to col major order

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        long long totalSum = 0;

        for(vector<int>& vec:  grid){

            totalSum+=accumulate(vec.begin(),vec.end(),0ll);
        }

        if(totalSum&1) return false;

        long long currentSum = 0;

        for(vector<int>& vec:  grid){

            currentSum+=accumulate(vec.begin(),vec.end(),0ll);

            if(totalSum - currentSum == currentSum) return true;
        }

        int n = grid.size() , m = grid[0].size();
        currentSum = 0;

        for(int col = 0;col<m;col++){
            for(int row = 0;row<n;row++){
                currentSum+=grid[row][col];
            }
            if(totalSum - currentSum == currentSum) return true;
        }

        return false;
    }
};

// Time Complexity : O(M*N)
// Space Complexity : O(1)