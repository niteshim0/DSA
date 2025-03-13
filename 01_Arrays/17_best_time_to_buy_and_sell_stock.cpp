class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int mini = INT_MAX;
          int maxi  = INT_MIN;
          for(int& num : prices){
              mini = min(mini,num);
              maxi = max(maxi,num-mini);
          }
          return maxi;
      }
  };