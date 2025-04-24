class Solution {
  public:
      int candy(vector<int>& rating) {
          int N = rating.size();
          vector<int> left(N,1);
          vector<int> right(N,1);
          for(int i = 1;i<N;i++){
              if(rating[i]>rating[i-1]){
                  left[i] = left[i-1] + 1;
              }
          }
          for(int i = N-2;i>=0;i--){
              if(rating[i]>rating[i+1]){
                  right[i] = right[i+1] + 1;
              }
          }
          int sum = 0;
          for(int i = 0;i<N;i++){
              sum+=max(left[i],right[i]);
          }
          return sum;
      }
  };
// Time Complexity : O(3N)
// Space Complexity : O(2N)

class Solution {
  public:
      int candy(vector<int>& rating) {
          int n = rating.size();
          int sum = 1;
          int idx  = 1;
          while(idx<n){
              if(rating[idx] == rating[idx-1]){
                  sum+=1;
                  idx++;
                  continue;
              }
              int peak = 1;
              while(idx<n && rating[idx]>rating[idx-1]){
                  peak++;
                  sum+=peak;
                  idx++;
              }
              int valley = 1;
              while(idx<n && rating[idx]<rating[idx-1]){
                  sum+=valley;
                  valley++;
                  idx++;
              }
              if(valley>peak){
                  sum+=(valley-peak);
              }
          }
          return sum;
      }
  };
  // Time Complexity : O(N)
  // Space Complexity : O(1)