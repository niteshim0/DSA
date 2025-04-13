class Solution {
  public:
      int trap(vector<int>& height) {
          int n = height.size();
          int maxLeft = height[0];
          vector<int> rightMax(n,0);
          int maxRight = height[n-1];
          for(int i = n-1;i>=0;i--){
              maxRight = max(maxRight,height[i]);
              rightMax[i] = maxRight;
          }
          int ans = 0;
          for(int i = 0;i<n;i++){
              maxLeft = max(maxLeft,height[i]);
              if(height[i]<maxLeft && height[i]<rightMax[i]){
                  ans+=min(maxLeft,rightMax[i])-height[i];
              }
          }
          return ans;
      }
  };
// Time Complexity : O(2N)
// Space Complexity : O(N)

// Optimal Approach :: Smaller building will always be limiting factor because all the water can overflow from it even on either side there is bigger building.

class Solution {
  public:
      int trap(vector<int>& height) {
          int n = height.size();
          int leftMax = 0;
          int rightMax = 0;
          int total = 0;
          int i = 0;
          int j = n-1;
          while(i<=j){
              if(height[i]<=height[j]){
                  if(leftMax>height[i]){
                      total+=(leftMax-height[i]);
                  }else{
                      leftMax = height[i];
                  }
                  i++;
              }else{
                  if(rightMax>height[j]){
                      total+=(rightMax-height[j]);
                  }else{
                      rightMax = height[j];
                  }
                  j--;
              }
          }
          return total;
      }
  };
// Time Complexity : O(N/2)
// Space Complexity : O(1)