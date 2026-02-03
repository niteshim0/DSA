// Stock Buy and Sell – Max one Transaction Allowed
// https://www.geeksforgeeks.org/problems/buy-stock-2/1
// Concept :: Greedy + Arrays

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int minVal = prices[0];
        int maxProfit = 0;
        
        for(int &x : prices){
            int need = x-minVal;
            maxProfit = max(maxProfit,need);
            minVal = min(minVal,x);
        }
        return maxProfit;
    }
};
// Time Complexity : O(N)
// Space Complexity : O(1)