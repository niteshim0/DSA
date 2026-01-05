// LC 1975. Maximum Matrix Sum
// https://leetcode.com/problems/maximum-matrix-sum/description


// Concept :: Need to think , sign propagation
// what we are doing ?
// if negativeCount%2 == 0 (even) , we can easily make all negative postive ultimately increasing our totalSum , what if two elements are not adjacent , we can make every negative element share border,because by multiplying any two element , we can propagate the sign so that two adjacent element becomes negative
// if  if negativeCount%2 == 1 (odd) ,no matter what we do , one element must remain negative , that element will be the absolute(min) one , increasing our total sum
// why we are 2 * mini in odd case , because for once we wanted to remove mini from totalSum , and for other that abs(mini) is already summed into while we are doing sum of matrix , we need to remove that as well.



class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long totalSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int val : row) {
                if (val < 0) negCount++;
                totalSum += abs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        if (negCount % 2 == 1) {
            totalSum -= 2LL * minAbs;
        }

        return totalSum;
    }
};

// Time Complexity : O(N*N)
// Space Complexity : O(1)
