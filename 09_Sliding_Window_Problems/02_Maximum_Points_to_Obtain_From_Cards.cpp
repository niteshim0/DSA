class Solution {
  public:
      int maxScore(vector<int>& cardPoints, int k) {
          int maxSum = 0;
          int leftSum = 0;
          int n = cardPoints.size();
          for(int i = 0;i<k;i++){
             leftSum+=cardPoints[i];
          }
          maxSum = leftSum;
          int rightIdx = n-1;
          int rightSum = 0;
          for(int i = k-1;i>=0;i--){
              leftSum = leftSum-cardPoints[i];
              rightSum = rightSum + cardPoints[rightIdx];
              rightIdx--;
              maxSum = max(maxSum,rightSum + leftSum);
          }
          return maxSum;
      }
  };
// Time Complexity : O(2*k)
// Space Complexity : O(1)