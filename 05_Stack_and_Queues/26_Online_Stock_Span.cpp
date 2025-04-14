class StockSpanner {
  private:
  vector<int> ans;
  public:
      StockSpanner() {
          
      }
      
      int next(int price) {
          ans.push_back(price);
          int cnt = 1;
          int n = ans.size();
          if(n==1) return 1;
          for(int i = n-2;i>=0;i--){
              if(ans[i]<=price){
                  cnt++;
              }else{
                  break;
              }
          }
          return cnt;
      }
  };
// Time Complexity : O(No. of Next Calls * Size of array till that point)
// Space Complexity : O(no. of next calls)

class StockSpanner {
  private:
  stack<pair<int,int>> st;
  int idx;
  public:
      StockSpanner() {
          idx = -1;
      }
      
      int next(int price) {
          idx = idx+1;
          while(!st.empty() && st.top().first<=price){
              st.pop();
          }
          int ans = idx - (st.empty() ? -1 : st.top().second);
          st.push({price,idx});
          return ans;
      }
  };
  
 // Time Complexity: O(2N)
 // Space Complexity : O(N)
